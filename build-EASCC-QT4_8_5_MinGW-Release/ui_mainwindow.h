/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDateTimeEdit>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QListView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QTreeWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_Connect;
    QAction *action_Quit;
    QAction *action_Upload;
    QAction *action_Download;
    QAction *action_Rename;
    QAction *actionRe_move;
    QAction *action_Play;
    QAction *action_DO;
    QAction *action_About;
    QAction *actionNew_Folder;
    QAction *actionDescription;
    QAction *actionEvent;
    QWidget *centralWidget;
    QGroupBox *messageGroupBox;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_3;
    QPushButton *renamePushButton;
    QPushButton *uploadPushButton;
    QPushButton *downloadPushButton;
    QPushButton *descriptionPushButton;
    QPushButton *newFolderPushButton;
    QPushButton *eventPushButton;
    QPushButton *removePushButton;
    QTreeWidget *messageTreeWidget;
    QGroupBox *ioBoardGroupBox;
    QGroupBox *diGroupBox;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout;
    QCheckBox *di3CheckBox;
    QCheckBox *di1CheckBox;
    QCheckBox *di2CheckBox;
    QCheckBox *di0CheckBox;
    QGroupBox *doGroupBox;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_2;
    QCheckBox *do0CheckBox;
    QCheckBox *do1CheckBox;
    QCheckBox *do2CheckBox;
    QCheckBox *do3CheckBox;
    QPushButton *doManualPushButton;
    QGroupBox *aiGroupBox;
    QListView *aiListView;
    QGroupBox *connectGroupBox;
    QGroupBox *connMethodGroupBox;
    QWidget *layoutWidget3;
    QGridLayout *gridLayout_6;
    QRadioButton *ethernetRadioButton;
    QLineEdit *ethernetAddrLineEdit;
    QRadioButton *rs485RadioButton;
    QLineEdit *rs485AddrLineEdit;
    QPushButton *connectPushButton;
    QGroupBox *easDateTimeGroupBox;
    QWidget *layoutWidget4;
    QGridLayout *gridLayout_4;
    QDateTimeEdit *dateTimeEdit;
    QPushButton *easGetTimePushButton;
    QPushButton *easSyncTimePushButton;
    QMenuBar *menuBar;
    QMenu *fileMenu;
    QMenu *messageMenu;
    QMenu *ioBoardMenu;
    QMenu *helpMenu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setMaximumSize(QSize(800, 600));
        MainWindow->setToolButtonStyle(Qt::ToolButtonIconOnly);
        action_Connect = new QAction(MainWindow);
        action_Connect->setObjectName(QString::fromUtf8("action_Connect"));
        action_Quit = new QAction(MainWindow);
        action_Quit->setObjectName(QString::fromUtf8("action_Quit"));
        action_Upload = new QAction(MainWindow);
        action_Upload->setObjectName(QString::fromUtf8("action_Upload"));
        action_Upload->setEnabled(false);
        action_Download = new QAction(MainWindow);
        action_Download->setObjectName(QString::fromUtf8("action_Download"));
        action_Download->setEnabled(false);
        action_Rename = new QAction(MainWindow);
        action_Rename->setObjectName(QString::fromUtf8("action_Rename"));
        action_Rename->setEnabled(false);
        actionRe_move = new QAction(MainWindow);
        actionRe_move->setObjectName(QString::fromUtf8("actionRe_move"));
        actionRe_move->setEnabled(false);
        action_Play = new QAction(MainWindow);
        action_Play->setObjectName(QString::fromUtf8("action_Play"));
        action_Play->setEnabled(false);
        action_DO = new QAction(MainWindow);
        action_DO->setObjectName(QString::fromUtf8("action_DO"));
        action_DO->setEnabled(false);
        action_About = new QAction(MainWindow);
        action_About->setObjectName(QString::fromUtf8("action_About"));
        actionNew_Folder = new QAction(MainWindow);
        actionNew_Folder->setObjectName(QString::fromUtf8("actionNew_Folder"));
        actionNew_Folder->setEnabled(false);
        actionDescription = new QAction(MainWindow);
        actionDescription->setObjectName(QString::fromUtf8("actionDescription"));
        actionDescription->setEnabled(false);
        actionEvent = new QAction(MainWindow);
        actionEvent->setObjectName(QString::fromUtf8("actionEvent"));
        actionEvent->setEnabled(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        messageGroupBox = new QGroupBox(centralWidget);
        messageGroupBox->setObjectName(QString::fromUtf8("messageGroupBox"));
        messageGroupBox->setEnabled(false);
        messageGroupBox->setGeometry(QRect(10, 100, 531, 441));
        layoutWidget = new QWidget(messageGroupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(12, 22, 511, 411));
        gridLayout_3 = new QGridLayout(layoutWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        renamePushButton = new QPushButton(layoutWidget);
        renamePushButton->setObjectName(QString::fromUtf8("renamePushButton"));

        gridLayout_3->addWidget(renamePushButton, 1, 2, 1, 1);

        uploadPushButton = new QPushButton(layoutWidget);
        uploadPushButton->setObjectName(QString::fromUtf8("uploadPushButton"));

        gridLayout_3->addWidget(uploadPushButton, 1, 0, 1, 1);

        downloadPushButton = new QPushButton(layoutWidget);
        downloadPushButton->setObjectName(QString::fromUtf8("downloadPushButton"));

        gridLayout_3->addWidget(downloadPushButton, 1, 1, 1, 1);

        descriptionPushButton = new QPushButton(layoutWidget);
        descriptionPushButton->setObjectName(QString::fromUtf8("descriptionPushButton"));

        gridLayout_3->addWidget(descriptionPushButton, 2, 0, 1, 1);

        newFolderPushButton = new QPushButton(layoutWidget);
        newFolderPushButton->setObjectName(QString::fromUtf8("newFolderPushButton"));

        gridLayout_3->addWidget(newFolderPushButton, 1, 4, 1, 1);

        eventPushButton = new QPushButton(layoutWidget);
        eventPushButton->setObjectName(QString::fromUtf8("eventPushButton"));

        gridLayout_3->addWidget(eventPushButton, 2, 1, 1, 1);

        removePushButton = new QPushButton(layoutWidget);
        removePushButton->setObjectName(QString::fromUtf8("removePushButton"));

        gridLayout_3->addWidget(removePushButton, 1, 3, 1, 1);

        messageTreeWidget = new QTreeWidget(layoutWidget);
        messageTreeWidget->setObjectName(QString::fromUtf8("messageTreeWidget"));
        messageTreeWidget->setContextMenuPolicy(Qt::NoContextMenu);

        gridLayout_3->addWidget(messageTreeWidget, 0, 0, 1, 5);

        ioBoardGroupBox = new QGroupBox(centralWidget);
        ioBoardGroupBox->setObjectName(QString::fromUtf8("ioBoardGroupBox"));
        ioBoardGroupBox->setEnabled(false);
        ioBoardGroupBox->setGeometry(QRect(550, 110, 241, 391));
        ioBoardGroupBox->setLayoutDirection(Qt::LeftToRight);
        diGroupBox = new QGroupBox(ioBoardGroupBox);
        diGroupBox->setObjectName(QString::fromUtf8("diGroupBox"));
        diGroupBox->setGeometry(QRect(10, 20, 82, 151));
        layoutWidget1 = new QWidget(diGroupBox);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 20, 43, 92));
        gridLayout = new QGridLayout(layoutWidget1);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        di3CheckBox = new QCheckBox(layoutWidget1);
        di3CheckBox->setObjectName(QString::fromUtf8("di3CheckBox"));
        di3CheckBox->setCheckable(false);

        gridLayout->addWidget(di3CheckBox, 3, 0, 1, 1);

        di1CheckBox = new QCheckBox(layoutWidget1);
        di1CheckBox->setObjectName(QString::fromUtf8("di1CheckBox"));
        di1CheckBox->setCheckable(false);

        gridLayout->addWidget(di1CheckBox, 1, 0, 1, 1);

        di2CheckBox = new QCheckBox(layoutWidget1);
        di2CheckBox->setObjectName(QString::fromUtf8("di2CheckBox"));
        di2CheckBox->setCheckable(false);

        gridLayout->addWidget(di2CheckBox, 2, 0, 1, 1);

        di0CheckBox = new QCheckBox(layoutWidget1);
        di0CheckBox->setObjectName(QString::fromUtf8("di0CheckBox"));
        di0CheckBox->setCheckable(false);

        gridLayout->addWidget(di0CheckBox, 0, 0, 1, 1);

        doGroupBox = new QGroupBox(ioBoardGroupBox);
        doGroupBox->setObjectName(QString::fromUtf8("doGroupBox"));
        doGroupBox->setGeometry(QRect(100, 20, 131, 153));
        layoutWidget2 = new QWidget(doGroupBox);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 18, 77, 123));
        gridLayout_5 = new QGridLayout(layoutWidget2);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        do0CheckBox = new QCheckBox(layoutWidget2);
        do0CheckBox->setObjectName(QString::fromUtf8("do0CheckBox"));
        do0CheckBox->setCheckable(false);

        gridLayout_2->addWidget(do0CheckBox, 0, 0, 1, 1);

        do1CheckBox = new QCheckBox(layoutWidget2);
        do1CheckBox->setObjectName(QString::fromUtf8("do1CheckBox"));
        do1CheckBox->setCheckable(false);

        gridLayout_2->addWidget(do1CheckBox, 1, 0, 1, 1);

        do2CheckBox = new QCheckBox(layoutWidget2);
        do2CheckBox->setObjectName(QString::fromUtf8("do2CheckBox"));
        do2CheckBox->setCheckable(false);

        gridLayout_2->addWidget(do2CheckBox, 2, 0, 1, 1);

        do3CheckBox = new QCheckBox(layoutWidget2);
        do3CheckBox->setObjectName(QString::fromUtf8("do3CheckBox"));
        do3CheckBox->setCheckable(false);

        gridLayout_2->addWidget(do3CheckBox, 3, 0, 1, 1);


        gridLayout_5->addLayout(gridLayout_2, 0, 0, 1, 1);

        doManualPushButton = new QPushButton(layoutWidget2);
        doManualPushButton->setObjectName(QString::fromUtf8("doManualPushButton"));

        gridLayout_5->addWidget(doManualPushButton, 1, 0, 1, 1);

        aiGroupBox = new QGroupBox(ioBoardGroupBox);
        aiGroupBox->setObjectName(QString::fromUtf8("aiGroupBox"));
        aiGroupBox->setGeometry(QRect(10, 180, 221, 201));
        aiListView = new QListView(aiGroupBox);
        aiListView->setObjectName(QString::fromUtf8("aiListView"));
        aiListView->setGeometry(QRect(10, 20, 201, 171));
        connectGroupBox = new QGroupBox(centralWidget);
        connectGroupBox->setObjectName(QString::fromUtf8("connectGroupBox"));
        connectGroupBox->setGeometry(QRect(10, 0, 781, 101));
        connMethodGroupBox = new QGroupBox(connectGroupBox);
        connMethodGroupBox->setObjectName(QString::fromUtf8("connMethodGroupBox"));
        connMethodGroupBox->setGeometry(QRect(10, 10, 251, 81));
        layoutWidget3 = new QWidget(connMethodGroupBox);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(20, 20, 215, 48));
        gridLayout_6 = new QGridLayout(layoutWidget3);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        ethernetRadioButton = new QRadioButton(layoutWidget3);
        ethernetRadioButton->setObjectName(QString::fromUtf8("ethernetRadioButton"));
        ethernetRadioButton->setChecked(true);

        gridLayout_6->addWidget(ethernetRadioButton, 0, 0, 1, 1);

        ethernetAddrLineEdit = new QLineEdit(layoutWidget3);
        ethernetAddrLineEdit->setObjectName(QString::fromUtf8("ethernetAddrLineEdit"));
        ethernetAddrLineEdit->setEnabled(true);

        gridLayout_6->addWidget(ethernetAddrLineEdit, 0, 1, 1, 1);

        rs485RadioButton = new QRadioButton(layoutWidget3);
        rs485RadioButton->setObjectName(QString::fromUtf8("rs485RadioButton"));
        rs485RadioButton->setChecked(false);

        gridLayout_6->addWidget(rs485RadioButton, 1, 0, 1, 1);

        rs485AddrLineEdit = new QLineEdit(layoutWidget3);
        rs485AddrLineEdit->setObjectName(QString::fromUtf8("rs485AddrLineEdit"));
        rs485AddrLineEdit->setEnabled(false);

        gridLayout_6->addWidget(rs485AddrLineEdit, 1, 1, 1, 1);

        connectPushButton = new QPushButton(connectGroupBox);
        connectPushButton->setObjectName(QString::fromUtf8("connectPushButton"));
        connectPushButton->setGeometry(QRect(274, 67, 75, 23));
        easDateTimeGroupBox = new QGroupBox(connectGroupBox);
        easDateTimeGroupBox->setObjectName(QString::fromUtf8("easDateTimeGroupBox"));
        easDateTimeGroupBox->setEnabled(false);
        easDateTimeGroupBox->setGeometry(QRect(360, 10, 211, 80));
        layoutWidget4 = new QWidget(easDateTimeGroupBox);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(5, 20, 201, 51));
        gridLayout_4 = new QGridLayout(layoutWidget4);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        dateTimeEdit = new QDateTimeEdit(layoutWidget4);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setReadOnly(true);

        gridLayout_4->addWidget(dateTimeEdit, 0, 0, 1, 2);

        easGetTimePushButton = new QPushButton(layoutWidget4);
        easGetTimePushButton->setObjectName(QString::fromUtf8("easGetTimePushButton"));

        gridLayout_4->addWidget(easGetTimePushButton, 1, 0, 1, 1);

        easSyncTimePushButton = new QPushButton(layoutWidget4);
        easSyncTimePushButton->setObjectName(QString::fromUtf8("easSyncTimePushButton"));

        gridLayout_4->addWidget(easSyncTimePushButton, 1, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 18));
        fileMenu = new QMenu(menuBar);
        fileMenu->setObjectName(QString::fromUtf8("fileMenu"));
        messageMenu = new QMenu(menuBar);
        messageMenu->setObjectName(QString::fromUtf8("messageMenu"));
        ioBoardMenu = new QMenu(menuBar);
        ioBoardMenu->setObjectName(QString::fromUtf8("ioBoardMenu"));
        helpMenu = new QMenu(menuBar);
        helpMenu->setObjectName(QString::fromUtf8("helpMenu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(fileMenu->menuAction());
        menuBar->addAction(messageMenu->menuAction());
        menuBar->addAction(ioBoardMenu->menuAction());
        menuBar->addAction(helpMenu->menuAction());
        fileMenu->addAction(action_Connect);
        fileMenu->addAction(action_Quit);
        messageMenu->addAction(action_Upload);
        messageMenu->addAction(action_Download);
        messageMenu->addAction(action_Rename);
        messageMenu->addAction(actionRe_move);
        messageMenu->addAction(actionNew_Folder);
        messageMenu->addAction(action_Play);
        messageMenu->addSeparator();
        messageMenu->addAction(actionDescription);
        messageMenu->addAction(actionEvent);
        ioBoardMenu->addAction(action_DO);
        helpMenu->addSeparator();
        helpMenu->addAction(action_About);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        action_Connect->setText(QApplication::translate("MainWindow", "&Connect", 0, QApplication::UnicodeUTF8));
        action_Quit->setText(QApplication::translate("MainWindow", "&Quit", 0, QApplication::UnicodeUTF8));
        action_Upload->setText(QApplication::translate("MainWindow", "&Upload", 0, QApplication::UnicodeUTF8));
        action_Download->setText(QApplication::translate("MainWindow", "&Download", 0, QApplication::UnicodeUTF8));
        action_Rename->setText(QApplication::translate("MainWindow", "&Rename", 0, QApplication::UnicodeUTF8));
        actionRe_move->setText(QApplication::translate("MainWindow", "Re&move", 0, QApplication::UnicodeUTF8));
        action_Play->setText(QApplication::translate("MainWindow", "&Play", 0, QApplication::UnicodeUTF8));
        action_DO->setText(QApplication::translate("MainWindow", "&DO", 0, QApplication::UnicodeUTF8));
        action_About->setText(QApplication::translate("MainWindow", "&About", 0, QApplication::UnicodeUTF8));
        actionNew_Folder->setText(QApplication::translate("MainWindow", "New Folder", 0, QApplication::UnicodeUTF8));
        actionDescription->setText(QApplication::translate("MainWindow", "Description", 0, QApplication::UnicodeUTF8));
        actionEvent->setText(QApplication::translate("MainWindow", "Event", 0, QApplication::UnicodeUTF8));
        messageGroupBox->setTitle(QApplication::translate("MainWindow", "Message Control", 0, QApplication::UnicodeUTF8));
        renamePushButton->setText(QApplication::translate("MainWindow", "Rename", 0, QApplication::UnicodeUTF8));
        uploadPushButton->setText(QApplication::translate("MainWindow", "Upload", 0, QApplication::UnicodeUTF8));
        downloadPushButton->setText(QApplication::translate("MainWindow", "Download", 0, QApplication::UnicodeUTF8));
        descriptionPushButton->setText(QApplication::translate("MainWindow", "Description", 0, QApplication::UnicodeUTF8));
        newFolderPushButton->setText(QApplication::translate("MainWindow", "New Folder", 0, QApplication::UnicodeUTF8));
        eventPushButton->setText(QApplication::translate("MainWindow", "Event", 0, QApplication::UnicodeUTF8));
        removePushButton->setText(QApplication::translate("MainWindow", "Remove", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = messageTreeWidget->headerItem();
        ___qtreewidgetitem->setText(4, QApplication::translate("MainWindow", "Duration", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(3, QApplication::translate("MainWindow", "Date", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(2, QApplication::translate("MainWindow", "Description", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(1, QApplication::translate("MainWindow", "Size", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "File Name", 0, QApplication::UnicodeUTF8));
        ioBoardGroupBox->setTitle(QApplication::translate("MainWindow", "IO Board", 0, QApplication::UnicodeUTF8));
        diGroupBox->setTitle(QApplication::translate("MainWindow", "DI", 0, QApplication::UnicodeUTF8));
        di3CheckBox->setText(QApplication::translate("MainWindow", "DI3", 0, QApplication::UnicodeUTF8));
        di1CheckBox->setText(QApplication::translate("MainWindow", "DI1", 0, QApplication::UnicodeUTF8));
        di2CheckBox->setText(QApplication::translate("MainWindow", "DI2", 0, QApplication::UnicodeUTF8));
        di0CheckBox->setText(QApplication::translate("MainWindow", "DI0", 0, QApplication::UnicodeUTF8));
        doGroupBox->setTitle(QApplication::translate("MainWindow", "DO", 0, QApplication::UnicodeUTF8));
        do0CheckBox->setText(QApplication::translate("MainWindow", "DO0", 0, QApplication::UnicodeUTF8));
        do1CheckBox->setText(QApplication::translate("MainWindow", "DO1", 0, QApplication::UnicodeUTF8));
        do2CheckBox->setText(QApplication::translate("MainWindow", "DO2", 0, QApplication::UnicodeUTF8));
        do3CheckBox->setText(QApplication::translate("MainWindow", "DO3", 0, QApplication::UnicodeUTF8));
        doManualPushButton->setText(QApplication::translate("MainWindow", "Manual", 0, QApplication::UnicodeUTF8));
        aiGroupBox->setTitle(QApplication::translate("MainWindow", "AI", 0, QApplication::UnicodeUTF8));
        connectGroupBox->setTitle(QApplication::translate("MainWindow", "Connection", 0, QApplication::UnicodeUTF8));
        connMethodGroupBox->setTitle(QApplication::translate("MainWindow", "Type", 0, QApplication::UnicodeUTF8));
        ethernetRadioButton->setText(QApplication::translate("MainWindow", "ETHERNET", 0, QApplication::UnicodeUTF8));
        ethernetAddrLineEdit->setText(QApplication::translate("MainWindow", "192.168.1.150", 0, QApplication::UnicodeUTF8));
        rs485RadioButton->setText(QApplication::translate("MainWindow", "RS-485", 0, QApplication::UnicodeUTF8));
        connectPushButton->setText(QApplication::translate("MainWindow", "Connect", 0, QApplication::UnicodeUTF8));
        easDateTimeGroupBox->setTitle(QApplication::translate("MainWindow", "EAS Date/Time", 0, QApplication::UnicodeUTF8));
        easGetTimePushButton->setText(QApplication::translate("MainWindow", "Get", 0, QApplication::UnicodeUTF8));
        easSyncTimePushButton->setText(QApplication::translate("MainWindow", "Sync", 0, QApplication::UnicodeUTF8));
        fileMenu->setTitle(QApplication::translate("MainWindow", "&File", 0, QApplication::UnicodeUTF8));
        messageMenu->setTitle(QApplication::translate("MainWindow", "&Messages", 0, QApplication::UnicodeUTF8));
        ioBoardMenu->setTitle(QApplication::translate("MainWindow", "IO &Board", 0, QApplication::UnicodeUTF8));
        helpMenu->setTitle(QApplication::translate("MainWindow", "&Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
