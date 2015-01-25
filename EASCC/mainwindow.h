#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include <fmsgeventdialog.h>

QT_BEGIN_NAMESPACE
class QDialogButtonBox;
class QFile;
class QFtp;
class QLabel;
class QLineEdit;
class QTreeWidget;
class QTreeWidgetItem;
class QProgressDialog;
class QPushButton;
class QUrlInfo;
class QNetworkSession;
QT_END_NAMESPACE

struct TScheduleFile
{
    QString scheduleFileName;
    QString newScheduleFileName;
    QString fileName;
    uint8_t byte;
    QDateTime dtime;

    TScheduleFile()
    {
        scheduleFileName = "";
        newScheduleFileName = "";
        fileName = "";
        byte = 0;
    }
};


#define MAX_SCHEDULE_FILE_NUMBER    20


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:


private slots:
    void isel( bool checked );
    void connectToEas( bool clicked );
     void ftpCommandFinished(int commandId, bool error);
     void addToList(const QUrlInfo &urlInfo);
     void processItem(QTreeWidgetItem *item, int column);
    void renameMsg( bool clicked );
    void deleteMsg( bool clicked );
    void uploadMsg( bool clicked );
    void downloadMsg( bool clicked );
    void newFolder( bool clicked );
    void descriptionMsg( bool blicked );
    void eventMsg( bool clicked );
    void easGetTime( bool clicked );
    void easSyncTime( bool clicked );
    void tcpReadyRead();
    void itemClicked( QTreeWidgetItem* item,int column );

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();



private:
    Ui::MainWindow *ui;
    QFtp* ftp;
    QHash<QString, bool> isDirectory;
    QString currentPath;
    QFile* file;
    QTcpSocket* tcp;
    QString lastSentCmd;
    bool ftpControlFlag;
    int scheduleFileFoundCounter;

    int scheduleFileCounter;
    TScheduleFile scheduleFile[ MAX_SCHEDULE_FILE_NUMBER ];

    void addParentDir();
};

#endif // MAINWINDOW_H
