#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cr/easCore.hpp>
#include <QMessageBox>
#include <QDialog>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle(tr("EAS Control Center"));

    //connect( ui->connectPushButton, SIGNAL( clicked( bool ) ), this, SLOT( interfaceSelect( bool ) ) );
    connect( ui->rs485RadioButton, SIGNAL( toggled( bool ) ), this, SLOT( isel( bool ) ) );
    connect( ui->ethernetRadioButton, SIGNAL( toggled( bool ) ), this, SLOT( isel( bool ) ) );
    connect( ui->connectPushButton, SIGNAL( clicked( bool ) ), this, SLOT( connectToEas( bool ) ) );

    connect( ui->uploadPushButton, SIGNAL( clicked( bool ) ), this, SLOT( uploadMsg( bool ) ) );
    connect( ui->downloadPushButton, SIGNAL( clicked( bool ) ), this, SLOT( downloadMsg( bool ) ) );
    connect( ui->renamePushButton, SIGNAL( clicked( bool ) ), this, SLOT( renameMsg( bool ) ) );
    connect( ui->removePushButton, SIGNAL( clicked( bool ) ), this, SLOT( deleteMsg( bool ) ) );
    connect( ui->newFolderPushButton, SIGNAL( clicked( bool ) ), this, SLOT( newFolder( bool ) ) );

    connect( ui->messageTreeWidget, SIGNAL(itemActivated(QTreeWidgetItem*,int)),
            this, SLOT(processItem(QTreeWidgetItem*,int)));
   // connect( ui->messageTreeWidget, SIGNAL(currentItemChanged(QTreeWidgetItem*,QTreeWidgetItem*)),
   //         this, SLOT(enableDownloadButton()));

    ftp = new QFtp();
    connect(ftp, SIGNAL(commandFinished(int,bool)), this, SLOT(ftpCommandFinished(int,bool)));
    connect(ftp, SIGNAL(listInfo(QUrlInfo)), this, SLOT(addToList(QUrlInfo)));
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
        ui->messageGroupBox->setEnabled( false );
        return;
    }

    ftp->abort();
    ui->messageTreeWidget->clear();
    currentPath.clear();
    isDirectory.clear();

    ftp->connectToHost( ui->ethernetAddrLineEdit->text() );
    ftp->login();

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
        ui->messageGroupBox->setEnabled( true );

    }
    else
    {
        ui->connMethodGroupBox->setEnabled( true );
        ui->connectPushButton->setText( tr( "Connect" ) );
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
        ui->connectPushButton->setText( tr( "Disconnect" ) );
        ui->messageGroupBox->setEnabled( true );
        return;
    }

    if(ftp->currentCommand() == QFtp::Login)
    {
        ftp->list();
    }

    if( ftp->currentCommand() == QFtp::Mkdir )
    {
        if( error )
        {
            QMessageBox::information(this, tr("EAS new folder"),
                                     tr("Unable to create new folder!"));
            return;
        }
        addParentDir();
        ftp->list();
    }

    if( ftp->currentCommand() == QFtp::Remove || ftp->currentCommand() == QFtp::Rmdir )
    {
        if( error )
        {
            QMessageBox::information(this, tr("EAS removing message"),
                                     tr( "Can't remove message!" ) );
            return;
        }

        addParentDir();
        ftp->list();
    }

    if( ftp->currentCommand() == QFtp::Rename )
    {
        if( error )
        {
            QMessageBox::information(this, tr("EAS rename"),
                                     tr( "Can't rename item!" ) );
            return;
        }

        addParentDir();
        ftp->list();
    }

    if ( ftp->currentCommand() == QFtp::Get )
    {
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
}



void MainWindow::addToList(const QUrlInfo &urlInfo)
{
    QTreeWidgetItem *item = new QTreeWidgetItem;
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
        ftp->list();

#ifndef QT_NO_CURSOR
        setCursor(Qt::WaitCursor);
#endif
        return;
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

}



void MainWindow::downloadMsg( bool clicked )
{
    QString fileName = ui->messageTreeWidget->currentItem()->text(0);
//![3]
//
    if (QFile::exists(fileName)) {
        QMessageBox::information(this, tr("EAS Downloading"),
                                 tr("There already exists a file called %1 in "
                                    "the current directory.")
                                 .arg(fileName));
        return;
    }

//![4]
    file = new QFile(fileName);
    if (!file->open(QIODevice::WriteOnly)) {
        QMessageBox::information(this, tr("EAS Saving"),
                                 tr("Unable to save the file %1: %2.")
                                 .arg(fileName).arg(file->errorString()));
        delete file;
        return;
    }

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

