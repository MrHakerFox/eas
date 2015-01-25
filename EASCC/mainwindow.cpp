#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cr/easCore.hpp>
#include <QMessageBox>
#include <QDialog>
#include <QInputDialog>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowFlags(windowFlags() ^ Qt::WindowMaximizeButtonHint);

    setWindowTitle(tr("EAS Control Center"));

    //connect( ui->connectPushButton, SIGNAL( clicked( bool ) ), this, SLOT( interfaceSelect( bool ) ) );
    connect( ui->rs485RadioButton, SIGNAL( toggled( bool ) ), this, SLOT( isel( bool ) ) );
    connect( ui->ethernetRadioButton, SIGNAL( toggled( bool ) ), this, SLOT( isel( bool ) ) );
    connect( ui->connectPushButton, SIGNAL( clicked( bool ) ), this, SLOT( connectToEas( bool ) ) );
    connect( ui->action_Connect, SIGNAL( triggered( bool ) ), this, SLOT( connectToEas( bool ) ) );

    connect( ui->uploadPushButton, SIGNAL( clicked( bool ) ), this, SLOT( uploadMsg( bool ) ) );
    connect( ui->downloadPushButton, SIGNAL( clicked( bool ) ), this, SLOT( downloadMsg( bool ) ) );
    connect( ui->renamePushButton, SIGNAL( clicked( bool ) ), this, SLOT( renameMsg( bool ) ) );
    connect( ui->removePushButton, SIGNAL( clicked( bool ) ), this, SLOT( deleteMsg( bool ) ) );
    connect( ui->newFolderPushButton, SIGNAL( clicked( bool ) ), this, SLOT( newFolder( bool ) ) );
    connect( ui->descriptionPushButton, SIGNAL( clicked( bool ) ), this, SLOT( descriptionMsg( bool ) ) );
    connect( ui->eventPushButton, SIGNAL( clicked( bool ) ), this, SLOT( eventMsg( bool ) ) );

    connect( ui->easGetTimePushButton, SIGNAL( clicked( bool ) ), this, SLOT( easGetTime( bool ) ) );
    connect( ui->easSyncTimePushButton, SIGNAL( clicked( bool ) ), this, SLOT( easSyncTime( bool ) ) );

    connect( ui->messageTreeWidget, SIGNAL(itemActivated(QTreeWidgetItem*,int)),
            this, SLOT(processItem(QTreeWidgetItem*,int)));
    connect( ui->messageTreeWidget, SIGNAL(itemClicked(QTreeWidgetItem*,int)),
            this, SLOT(itemClicked( QTreeWidgetItem*,int )));

    connect( ui->action_Quit, SIGNAL( triggered( bool )), this, SLOT( close() ) );

    ftp = new QFtp();
    connect(ftp, SIGNAL(commandFinished(int,bool)), this, SLOT(ftpCommandFinished(int,bool)));
    connect(ftp, SIGNAL(listInfo(QUrlInfo)), this, SLOT(addToList(QUrlInfo)));

    tcp = new QTcpSocket;
    connect( tcp, SIGNAL( readyRead() ), this, SLOT( tcpReadyRead() ) );

    ftpControlFlag = false;
    scheduleFileCounter = 0;
    scheduleFileFoundCounter = -1;
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::isel( bool checked )
{
    ui->rs485AddrLineEdit->setEnabled( ui->rs485RadioButton->isChecked() );
    ui->ethernetAddrLineEdit->setEnabled( ui->ethernetRadioButton->isChecked() );
}



void MainWindow::connectToEas( bool clicked )
{
#ifndef QT_NO_CURSOR
    setCursor(Qt::WaitCursor);
#endif
    if( ui->messageGroupBox->isEnabled() )
    {
        ftp->abort();
        ftp->close();
        ui->connMethodGroupBox->setEnabled( true );
        ui->connectPushButton->setText( tr( "Connect" ) );
        ui->action_Connect->setText( tr( "Connect" ) );
        ui->messageGroupBox->setEnabled( false );
        ui->easDateTimeGroupBox->setEnabled( false );
        return;
    }

    ftp->abort();
    tcp->abort();;
    ui->messageTreeWidget->clear();
    currentPath.clear();
    isDirectory.clear();

    ftp->connectToHost( ui->ethernetAddrLineEdit->text() );
    ftp->login();

    tcp->connectToHost( ui->ethernetAddrLineEdit->text(), 1277 );

    return;


    FRetResCodes::code connResult;

    if( !FEasCore::getInstance()->isConnected() )
    {
        if( ui->rs485RadioButton->isChecked() )
        {
            connResult = FEasCore::getInstance()->rs485Connect( ui->rs485AddrLineEdit->text().toStdString() );
        }

        if( ui->ethernetRadioButton->isChecked() )
        {
           // connResult = FEasCore::getInstance()->ethernetConnect( ui->rs485AddrLineEdit->text().toStdString() );
        }

        switch( connResult )
        {
        case FRetResCodes::OK:
            break;

        case FRetResCodes::Failed:
        default:
            QMessageBox::information( this, tr( "Connection" ), tr( "General error occured!" ), QMessageBox::Ok );
        }
    }
    else
    {
        FEasCore::getInstance()->disconnect();
    }

    if( FEasCore::getInstance()->isConnected() )
    {
        ui->connMethodGroupBox->setEnabled( false );
        ui->connectPushButton->setText( tr( "Disconnect" ) );
        ui->action_Connect->setText( tr( "Disconnect" ) );
        ui->messageGroupBox->setEnabled( true );

    }
    else
    {
        ui->connMethodGroupBox->setEnabled( true );
        ui->connectPushButton->setText( tr( "Connect" ) );
        ui->action_Connect->setText( tr( "Connect" ) );
        ui->messageGroupBox->setEnabled( false );
    }
}


void MainWindow::ftpCommandFinished(int, bool error)
{
#ifndef QT_NO_CURSOR
    setCursor(Qt::ArrowCursor);
#endif

    if (ftp->currentCommand() == QFtp::ConnectToHost )
    {
        if (error) {
            QMessageBox::information(this, tr("EAS connecting..."),
                                     tr("Unable to connect to EAS module!"
                                        "at %1. Please check that the host "
                                        "name is correct.")
                                     .arg(ui->ethernetAddrLineEdit->text()));
            ui->connMethodGroupBox->setEnabled( true );
            ui->connectPushButton->setText( tr( "Connect" ) );
            ui->messageGroupBox->setEnabled( false );
            return;
        }
        ui->connMethodGroupBox->setEnabled( false );
        ui->easDateTimeGroupBox->setEnabled( true );
        ui->connectPushButton->setText( tr( "Disconnect" ) );
        ui->messageGroupBox->setEnabled( true );

        easGetTime( false );

        return;
    }

    if(ftp->currentCommand() == QFtp::Login)
    {
        scheduleFileCounter = 0;
        ftp->list();

        //if( ui->messageTreeWidget->ite)
        //QModelIndex ind( 0, 0 );
        //ui->messageTreeWidget->setCurrentIndex( );
       // ui->eventPushButton->setEnabled( ui->messageTreeWidget->currentItem()->text( 0 ) != ".." && !isDirectory.value( ui->messageTreeWidget->currentItem()->text( 0 ) ) );
    }

    if( ftp->currentCommand() == QFtp::Mkdir )
    {
        ui->messageGroupBox->setEnabled( true );
        if( error )
        {
            QMessageBox::information(this, tr("EAS new folder"),
                                     tr("Unable to create new folder!"));
            return;
        }
        addParentDir();
        scheduleFileCounter = 0;
        ftp->list();
    }

    if( ftp->currentCommand() == QFtp::Remove || ftp->currentCommand() == QFtp::Rmdir )
    {
        ui->messageGroupBox->setEnabled( true );

        if( ftpControlFlag )
        {
            if( error )
            {
                QMessageBox::information(this, tr("EAS"),
                                         tr( "General error!" ) );
                return;
            }

            ftpControlFlag = false;
            if( scheduleFileFoundCounter > -1 )
            {
                ftpControlFlag = true;
                QByteArray ba;
                ba.resize(5);
                ba[0] = 0x3c;
                ba[1] = 0xb8;
                ba[2] = 0x64;
                ba[3] = 0x18;
                ba[4] = 0xca;
                ftp->put( ba, scheduleFile[ scheduleFileFoundCounter ].newScheduleFileName );

                return;
            }
        }

        if( error )
        {
            QMessageBox::information(this, tr("EAS removing message"),
                                     tr( "Can't remove message!" ) );
            return;
        }

        addParentDir();
        scheduleFileCounter = 0;
        ftp->list();
    }

    if( ftp->currentCommand() == QFtp::Rename )
    {
        ui->messageGroupBox->setEnabled( true );
        if( error )
        {
            QMessageBox::information(this, tr("EAS rename"),
                                     tr( "Can't rename item!" ) );
            return;
        }

        addParentDir();
        scheduleFileCounter = 0;
        ftp->list();
    }

    if ( ftp->currentCommand() == QFtp::Get )
    {
        ui->messageGroupBox->setEnabled( true );
        if (error)
        {
            QMessageBox::critical(this, tr("EAS Downloading"),
                                     tr( "Can't download %1!" ).arg( file->fileName() ) );
            file->close();
            file->remove();
        }
        else
        {
            file->close();
            QMessageBox::information(this, tr("EAS Downloading"),
                                     tr( "%1 successfully downloaded!" ).arg( file->fileName() ) );
        }


//![8]
//![9]
    }

    if( ftp->currentCommand() == QFtp::Put )
    {

        ui->messageGroupBox->setEnabled( true );
        if (error)
        {
            if( ftpControlFlag )
            {
                QMessageBox::critical(this, tr("EAS"),
                                         tr( "General error!" ) );
                ftpControlFlag = false;
                return;
            }

            QMessageBox::critical(this, tr("EAS Uploading"),
                                     tr( "Can't upload %1!" ).arg( file->fileName() ) );
            file->close();
        }
        else
        {
            if( !ftpControlFlag )
            {
                file->close();
                QMessageBox::information(this, tr("EAS Uploading"),
                                         tr( "%1 successfully uploaded!" ).arg( file->fileName() ) );
            }

            ftpControlFlag = false;


            addParentDir();
            scheduleFileCounter = 0;
            ftp->list();
        }
    }
}



void MainWindow::addToList(const QUrlInfo &urlInfo)
{
    QTreeWidgetItem *item = new QTreeWidgetItem;

    if( urlInfo.name().contains( "_schedule_", Qt::CaseInsensitive ) &&
            ( urlInfo.name().contains( ".mp3", Qt::CaseInsensitive ) || urlInfo.name().contains( ".wav", Qt::CaseInsensitive ) ) )
    {
       //QMessageBox::information( this, "Something changed", urlInfo.name(), QMessageBox::Ok );
        int extensionIndex;

        if( urlInfo.name().contains( ".mp3", Qt::CaseInsensitive ) )
        {
            extensionIndex = urlInfo.name().indexOf( ".mp3", 0, Qt::CaseInsensitive );
        }
        else
        {
            extensionIndex = urlInfo.name().indexOf( ".wav", 0, Qt::CaseInsensitive );
        }

        int hour = urlInfo.name().mid( extensionIndex + 5, 2 ).toInt();
        int min = urlInfo.name().mid( extensionIndex + 8, 2 ).toInt();

        int day = urlInfo.name().mid( extensionIndex + 14, 2 ).toInt();
        int mon = urlInfo.name().mid( extensionIndex + 17, 2 ).toInt();
        int year = urlInfo.name().mid( extensionIndex + 20, 4 ).toInt();

        QTime time;
        time.setHMS( hour, min, 0 );
        QDate date;
        date.setYMD( year, mon, day );

        scheduleFile[ scheduleFileCounter ].scheduleFileName = urlInfo.name();
        scheduleFile[ scheduleFileCounter ].fileName = urlInfo.name().mid( 10, extensionIndex + 4 - 10 );
        scheduleFile[ scheduleFileCounter ].dtime.setTime( time );
        scheduleFile[ scheduleFileCounter ].dtime.setDate( date );
        scheduleFile[ scheduleFileCounter ].byte = urlInfo.name().mid( extensionIndex + 25, 4 ).toInt();
        scheduleFileCounter++;
    }

    if( !urlInfo.isDir() )
    {
        if( !urlInfo.name().contains( ".mp3", Qt::CaseInsensitive) && !urlInfo.name().contains( ".wav", Qt::CaseInsensitive) )
        {
            return;
        }

        if( urlInfo.name().at( urlInfo.name().length() - 3 ) != 'm' && urlInfo.name().at( urlInfo.name().length() - 3 ) != 'w' )
        {
            return;
        }
    }

    item->setText(0, urlInfo.name());
    item->setText(1, QString::number(urlInfo.size()));
    item->setText(3, urlInfo.lastModified().toString("dd MMM yyyy"));

    QPixmap pixmap(urlInfo.isDir() ? ":/images/dir.png" : ":/images/file.png");
    item->setIcon(0, pixmap);

    isDirectory[urlInfo.name()] = urlInfo.isDir();
    ui->messageTreeWidget->addTopLevelItem(item);
    if (!ui->messageTreeWidget->currentItem()) {
        ui->messageTreeWidget->setCurrentItem(ui->messageTreeWidget->topLevelItem(0));
        ui->messageTreeWidget->setEnabled(true);
    }
}



void MainWindow::processItem(QTreeWidgetItem *item, int column)
{
    if( item->text( 0 ) == ".." )
    {
#ifndef QT_NO_CURSOR
        setCursor(Qt::WaitCursor);
#endif
       ui->messageTreeWidget->clear();
        isDirectory.clear();
        currentPath = currentPath.left(currentPath.lastIndexOf('/'));

        addParentDir();

        if (currentPath.isEmpty()) {
            //cdToParentButton->setEnabled(false);
            ftp->cd("/");
        } else {
            ftp->cd(currentPath);
        }
        scheduleFileCounter = 0;
        ftp->list();
        return;
    }

    QString name = item->text(0);
    if (isDirectory.value(name)) {
        isDirectory.clear();
        currentPath += '/';
        currentPath += name;

        addParentDir();

        ftp->cd(name);
        scheduleFileCounter = 0;
        ftp->list();

#ifndef QT_NO_CURSOR
        setCursor(Qt::WaitCursor);
#endif
        return;
    }
    else
    {
        //QMessageBox::information( this, "", currentPath + "/" + name );
        //ui->messageTreeWidget->setEnabled( false );
        ui->messageGroupBox->setEnabled( false );
        QString buffer = "CMD_PLAY" + currentPath + "/" + name + "CMD_END";
        lastSentCmd = buffer;
        setCursor( Qt::WaitCursor );
        tcp->write( buffer.toStdString().c_str() );
    }
}


void MainWindow::renameMsg( bool clicked )
{
    QTreeWidgetItem *current = ui->messageTreeWidget->currentItem();

    bool ok;
    if (current)
    {
        QString currentFile = current->text(0);

        QString text = QInputDialog::getText(this, tr("Rename") + currentPath + "/" + currentFile,
                                                 tr("New name:"), QLineEdit::Normal,
                                                 currentFile, &ok);
        if (ok && !text.isEmpty())
        {
            ui->messageGroupBox->setEnabled( false );
            ftp->rename( currentPath + "/" + currentFile, currentPath + "/" + text );
        }
    }
}



void MainWindow::deleteMsg( bool clicked )
{
    QTreeWidgetItem *current = ui->messageTreeWidget->currentItem();

    if (current)
    {
        QString currentFile = current->text(0);

        if( QMessageBox::question( this, tr("EAS removing message"),
                                 tr( "Do you really want to remove" ) + currentPath + "/" + current->text( 0 ) + " ?", QMessageBox::Yes | QMessageBox::No ) ==QMessageBox::Yes )
        {
            ui->messageGroupBox->setEnabled( false );
            if( !isDirectory.value(currentFile) )
            {
                ftp->remove( currentPath + "/" + current->text( 0 ) );
            }
            else
            {
                ftp->rmdir( currentPath + "/" + current->text( 0 ) );
            }
        }
    }
}



void MainWindow::uploadMsg( bool clicked )
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Message to be Downloaded"),
                                                     "",
                                                     tr("Files (*.mp3 *.wav)"));
    if( fileName.isEmpty() )
    {
        return;
    }

    //QMessageBox::information( this, "", fileName );

    file = new QFile( fileName );
    if (!file->open(QIODevice::ReadOnly)) {
        QMessageBox::information(this, tr("EAS Uploading"),
                                 tr("Unable to upload file %1: %2.")
                                 .arg(fileName).arg(file->errorString()));
        delete file;
        return;
    }

    //QMessageBox::information( this, "", file->f );

    ui->messageGroupBox->setEnabled( false );
    QFileInfo fname( file->fileName() );
    ftp->put( file, fname.fileName() );
}



void MainWindow::downloadMsg( bool clicked )
{
    QString filename = ui->messageTreeWidget->currentItem()->text(0);
//![3]
//!
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                 "/home",
                                                 QFileDialog::ShowDirsOnly
                                                 | QFileDialog::DontResolveSymlinks);

    if( dir.isEmpty() )
    {
        return;
    }

    QString fullFileName = dir + "\\" + filename;
//
    if (QFile::exists(fullFileName)) {
        QMessageBox::information(this, tr("EAS Downloading"),
                                 tr("There already exists a file called %1 in "
                                    "the current directory.")
                                 .arg(fullFileName));
        return;
    }

//![4]
    file = new QFile( fullFileName);
    if (!file->open(QIODevice::WriteOnly)) {
        QMessageBox::information(this, tr("EAS Saving"),
                                 tr("Unable to save the file %1: %2.")
                                 .arg(fullFileName).arg(file->errorString()));
        delete file;
        return;
    }

    ui->messageGroupBox->setEnabled( false );
    ftp->get(ui->messageTreeWidget->currentItem()->text(0), file);

    //progressDialog->setLabelText(tr("Downloading %1...").arg(fileName));
    //downloadButton->setEnabled(false);
    //progressDialog->exec();
}



void MainWindow::newFolder( bool clicked )
{
    bool ok;
    QString text = QInputDialog::getText(this, tr("New folder at ") + currentPath,
                                             tr("Folder name:"), QLineEdit::Normal,
                                             "New Folder", &ok);
    if (ok && !text.isEmpty())
    {
        ui->messageGroupBox->setEnabled( false );
        ftp->mkdir( currentPath + "/" + text );
    }
}



void MainWindow::addParentDir()
{
    ui->messageTreeWidget->clear();
    if( !currentPath.isEmpty() )
    {
        QTreeWidgetItem *tmp = new QTreeWidgetItem;
        tmp->setText(0, ".." );
        ui->messageTreeWidget->addTopLevelItem(tmp);
    }
}



void MainWindow::descriptionMsg( bool blicked )
{
    QMessageBox::information( this, "Something changed", QString( "Counter %1" ).arg( scheduleFileCounter ), QMessageBox::Ok );
}



void MainWindow::eventMsg( bool clicked )
{
    QDateTime dtime;
    uint8_t schedule = 0;
    QString description;

    scheduleFileFoundCounter = -1;

    QString dtimeString;
    QString scheduleString;

    QTime time;
    QDate date;

    //time.setHMS( 17, 33, 10 );
    //date.setYMD( 2015, 1, 8 );



    for( int i = 0; i < scheduleFileCounter; i++ )
    {
        if( scheduleFile[ i ].fileName == ui->messageTreeWidget->currentItem()->text( 0 ) )
        {
            scheduleFileFoundCounter = i;
            break;
        }
    }

    if( scheduleFileFoundCounter > -1 )
    {
        dtime = scheduleFile[ scheduleFileFoundCounter ].dtime;
        schedule = scheduleFile[ scheduleFileFoundCounter ].byte;
    }

    //dtime.setTime( time );
   // dtime.setDate( date );

    FMsgEventDialog* dlg = new FMsgEventDialog( 0, ui->messageTreeWidget->currentItem()->text( 0 ), schedule, "no descr", dtime );
    if( dlg->exec() == QDialog::Accepted )
    {
        if( dlg->getAttribs( &schedule, &description, &dtime ) )
        {
            dtimeString.sprintf( "%02d-%02d-%02d_%02d-%02d-%04d-", dtime.time().hour(),
                                 dtime.time().minute(), dtime.time().second(),
                                 dtime.date().day(), dtime.date().month(), dtime.date().year() );

            scheduleString.sprintf( "%04d", schedule );

            scheduleFile[ scheduleFileFoundCounter ].newScheduleFileName = "_schedule_" + ui->messageTreeWidget->currentItem()->text( 0 ) + "_" + dtimeString + scheduleString;

            ftpControlFlag = true;

            if( scheduleFileFoundCounter > -1 )
            {
                ftp->remove( currentPath + "/" + scheduleFile[ scheduleFileFoundCounter ].scheduleFileName );
            }
            else

            {
                ftpControlFlag = true;
                QByteArray ba;
                ba.resize(5);
                ba[0] = 0x3c;
                ba[1] = 0xb8;
                ba[2] = 0x64;
                ba[3] = 0x18;
                ba[4] = 0xca;
                ftp->put( ba, scheduleFile[ scheduleFileFoundCounter ].newScheduleFileName );
            }



            //QMessageBox::information( this, "Something changed", fileName, QMessageBox::Ok );



            //tcp->write( buffer.toStdString().c_str() );

            //lastSentCmd = buffer;
        }
    }
    delete dlg;
}



void MainWindow::easGetTime( bool clicked )
{
    QDate date = QDate::currentDate();
    QTime time = QTime::currentTime();

    //QString dateString = QString( "%1-%2-%3" ).arg( date.year() ).arg( date.month() ).arg( date.day() );
    //QString timeString = QString( "%1:%2:%3" ).arg( time.hour() ).arg( time.minute() ).arg( time.second() );

    QString buffer = "CMD_GETTIMECMD_END";
    tcp->write( buffer.toStdString().c_str() );

    lastSentCmd = buffer;


}



void MainWindow::easSyncTime( bool clicked )
{
    QDate date = QDate::currentDate();
    QTime time = QTime::currentTime();

    QString dateString = QString( "%1-%2-%3" ).arg( date.year() ).arg( date.month() ).arg( date.day() );
    QString timeString = QString( "%1:%2:%3" ).arg( time.hour() ).arg( time.minute() ).arg( time.second() );

    QString buffer = "CMD_SETTIME" + dateString + " " + timeString + "CMD_END";
    tcp->write( buffer.toStdString().c_str() );
}



void MainWindow::tcpReadyRead()
{
    char* readSocketBuffer = new char[ 32768 ];

    while( !tcp->bytesAvailable() );

    tcp->read( readSocketBuffer, 32768 );

    QMessageBox::information( this, "Data read", readSocketBuffer, QMessageBox::Ok );

    if( lastSentCmd.contains( "CMD_GETTIME", Qt::CaseInsensitive ) &&
            QString( readSocketBuffer ).contains( "CMD_ANSW", Qt::CaseInsensitive ) )
    {
        QDate date;
        QTime time;

        int hour = ( readSocketBuffer[ 8 ] - 0x30 ) * 10 + ( readSocketBuffer[ 9 ] - 0x30 );
        int min = ( readSocketBuffer[ 11 ] - 0x30 ) * 10 + ( readSocketBuffer[ 12 ] - 0x30 );
        int sec = ( readSocketBuffer[ 14 ] - 0x30 ) * 10 + ( readSocketBuffer[ 15 ] - 0x30 );

        int day = ( readSocketBuffer[ 17 ] - 0x30 ) * 10 + ( readSocketBuffer[ 18 ] - 0x30 );
        int mon = ( readSocketBuffer[ 20 ] - 0x30 ) * 10 + ( readSocketBuffer[ 21 ] - 0x30 );
        int year = ( readSocketBuffer[ 23 ] - 0x30 ) * 1000 + ( readSocketBuffer[ 24 ] - 0x30 ) * 100 +
                ( readSocketBuffer[ 25 ] - 0x30 ) * 10 + ( readSocketBuffer[ 26 ] - 0x30 );

        date.setYMD( year, mon, day );
        time.setHMS( hour, min, sec );

        ui->dateTimeEdit->setDate( date );
        ui->dateTimeEdit->setTime( time );
    }

    if( lastSentCmd.contains( "CMD_PLAY", Qt::CaseInsensitive ) &&
            QString( readSocketBuffer ).contains( "CMD_OK", Qt::CaseInsensitive ) )
    {
        ui->messageGroupBox->setEnabled( true );
        setCursor( Qt::ArrowCursor );
    }

    lastSentCmd = "CMD_NONE";

    delete [] readSocketBuffer;
}



void MainWindow::itemClicked( QTreeWidgetItem* item, int column )
{
    //QMessageBox::information( this, "Item", item->text( 0 ), QMessageBox::Ok );


    ui->eventPushButton->setEnabled( item->text( 0 ) != ".." && !isDirectory.value( item->text( 0 ) ) );
    ui->descriptionPushButton->setEnabled( item->text( 0 ) != ".." && !isDirectory.value( item->text( 0 ) ) );
}

