/********************************************************************************
** Form generated from reading UI file 'fmsgeventdialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FMSGEVENTDIALOG_H
#define UI_FMSGEVENTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDateTimeEdit>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QRadioButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FMsgEventDialog
{
public:
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *msgNameLabel;
    QLabel *msgDescriptioLabel;
    QLabel *label_4;
    QGroupBox *groupBox_2;
    QComboBox *conditionComboBox;
    QCheckBox *byTimerCheckBox;
    QCheckBox *byIOEventCheckBox;
    QGroupBox *timeGroupBox;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QDateTimeEdit *dateTimeEdit;
    QRadioButton *onceRadioButton;
    QRadioButton *repeatRadioButton;
    QGroupBox *ioGroupBox;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QComboBox *di0TrigComboBox;
    QLabel *label_3;
    QComboBox *di1TrigComboBox;
    QLabel *label_6;
    QComboBox *di2TrigComboBox;
    QLabel *label_7;
    QComboBox *di3TrigComboBox;

    void setupUi(QDialog *FMsgEventDialog)
    {
        if (FMsgEventDialog->objectName().isEmpty())
            FMsgEventDialog->setObjectName(QString::fromUtf8("FMsgEventDialog"));
        FMsgEventDialog->resize(580, 340);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FMsgEventDialog->sizePolicy().hasHeightForWidth());
        FMsgEventDialog->setSizePolicy(sizePolicy);
        FMsgEventDialog->setMinimumSize(QSize(580, 340));
        FMsgEventDialog->setMaximumSize(QSize(580, 340));
        buttonBox = new QDialogButtonBox(FMsgEventDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(10, 300, 561, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        groupBox = new QGroupBox(FMsgEventDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 20, 551, 271));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 61, 16));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);
        msgNameLabel = new QLabel(groupBox);
        msgNameLabel->setObjectName(QString::fromUtf8("msgNameLabel"));
        msgNameLabel->setGeometry(QRect(160, 20, 371, 16));
        msgNameLabel->setFont(font);
        msgDescriptioLabel = new QLabel(groupBox);
        msgDescriptioLabel->setObjectName(QString::fromUtf8("msgDescriptioLabel"));
        msgDescriptioLabel->setGeometry(QRect(160, 40, 371, 16));
        msgDescriptioLabel->setFont(font);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 40, 71, 16));
        label_4->setFont(font);
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 80, 531, 181));
        conditionComboBox = new QComboBox(groupBox_2);
        conditionComboBox->setObjectName(QString::fromUtf8("conditionComboBox"));
        conditionComboBox->setGeometry(QRect(187, 15, 111, 22));
        byTimerCheckBox = new QCheckBox(groupBox_2);
        byTimerCheckBox->setObjectName(QString::fromUtf8("byTimerCheckBox"));
        byTimerCheckBox->setGeometry(QRect(20, 15, 71, 18));
        byIOEventCheckBox = new QCheckBox(groupBox_2);
        byIOEventCheckBox->setObjectName(QString::fromUtf8("byIOEventCheckBox"));
        byIOEventCheckBox->setGeometry(QRect(332, 15, 91, 18));
        timeGroupBox = new QGroupBox(groupBox_2);
        timeGroupBox->setObjectName(QString::fromUtf8("timeGroupBox"));
        timeGroupBox->setEnabled(false);
        timeGroupBox->setGeometry(QRect(20, 42, 141, 101));
        layoutWidget = new QWidget(timeGroupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 118, 70));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        dateTimeEdit = new QDateTimeEdit(layoutWidget);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));

        gridLayout->addWidget(dateTimeEdit, 0, 0, 1, 1);

        onceRadioButton = new QRadioButton(layoutWidget);
        onceRadioButton->setObjectName(QString::fromUtf8("onceRadioButton"));
        onceRadioButton->setChecked(true);

        gridLayout->addWidget(onceRadioButton, 1, 0, 1, 1);

        repeatRadioButton = new QRadioButton(layoutWidget);
        repeatRadioButton->setObjectName(QString::fromUtf8("repeatRadioButton"));

        gridLayout->addWidget(repeatRadioButton, 2, 0, 1, 1);

        ioGroupBox = new QGroupBox(groupBox_2);
        ioGroupBox->setObjectName(QString::fromUtf8("ioGroupBox"));
        ioGroupBox->setEnabled(false);
        ioGroupBox->setGeometry(QRect(333, 40, 181, 131));
        layoutWidget1 = new QWidget(ioGroupBox);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 20, 151, 100));
        gridLayout_2 = new QGridLayout(layoutWidget1);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        di0TrigComboBox = new QComboBox(layoutWidget1);
        di0TrigComboBox->setObjectName(QString::fromUtf8("di0TrigComboBox"));

        gridLayout_2->addWidget(di0TrigComboBox, 0, 1, 1, 1);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 1, 0, 1, 1);

        di1TrigComboBox = new QComboBox(layoutWidget1);
        di1TrigComboBox->setObjectName(QString::fromUtf8("di1TrigComboBox"));

        gridLayout_2->addWidget(di1TrigComboBox, 1, 1, 1, 1);

        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 2, 0, 1, 1);

        di2TrigComboBox = new QComboBox(layoutWidget1);
        di2TrigComboBox->setObjectName(QString::fromUtf8("di2TrigComboBox"));

        gridLayout_2->addWidget(di2TrigComboBox, 2, 1, 1, 1);

        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_2->addWidget(label_7, 3, 0, 1, 1);

        di3TrigComboBox = new QComboBox(layoutWidget1);
        di3TrigComboBox->setObjectName(QString::fromUtf8("di3TrigComboBox"));

        gridLayout_2->addWidget(di3TrigComboBox, 3, 1, 1, 1);


        retranslateUi(FMsgEventDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), FMsgEventDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), FMsgEventDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(FMsgEventDialog);
    } // setupUi

    void retranslateUi(QDialog *FMsgEventDialog)
    {
        FMsgEventDialog->setWindowTitle(QApplication::translate("FMsgEventDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("FMsgEventDialog", "Event Manager", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("FMsgEventDialog", "Name", 0, QApplication::UnicodeUTF8));
        msgNameLabel->setText(QApplication::translate("FMsgEventDialog", "Super Message to go in USA with family!", 0, QApplication::UnicodeUTF8));
        msgDescriptioLabel->setText(QApplication::translate("FMsgEventDialog", "Description:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("FMsgEventDialog", "Description:", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("FMsgEventDialog", "Play it, when the following contitions are met", 0, QApplication::UnicodeUTF8));
        conditionComboBox->clear();
        conditionComboBox->insertItems(0, QStringList()
         << QApplication::translate("FMsgEventDialog", "INDEPENDENTLY", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("FMsgEventDialog", "AND", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("FMsgEventDialog", "OR", 0, QApplication::UnicodeUTF8)
        );
        byTimerCheckBox->setText(QApplication::translate("FMsgEventDialog", "By time", 0, QApplication::UnicodeUTF8));
        byIOEventCheckBox->setText(QApplication::translate("FMsgEventDialog", "By IO event", 0, QApplication::UnicodeUTF8));
        timeGroupBox->setTitle(QApplication::translate("FMsgEventDialog", "Time", 0, QApplication::UnicodeUTF8));
        onceRadioButton->setText(QApplication::translate("FMsgEventDialog", "Once", 0, QApplication::UnicodeUTF8));
        repeatRadioButton->setText(QApplication::translate("FMsgEventDialog", "Repeatedly", 0, QApplication::UnicodeUTF8));
        ioGroupBox->setTitle(QApplication::translate("FMsgEventDialog", "DI Trgigger Options", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("FMsgEventDialog", "DI0", 0, QApplication::UnicodeUTF8));
        di0TrigComboBox->clear();
        di0TrigComboBox->insertItems(0, QStringList()
         << QApplication::translate("FMsgEventDialog", "NONE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("FMsgEventDialog", "RISING EDGE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("FMsgEventDialog", "FALLING EDGE", 0, QApplication::UnicodeUTF8)
        );
        label_3->setText(QApplication::translate("FMsgEventDialog", "DI1", 0, QApplication::UnicodeUTF8));
        di1TrigComboBox->clear();
        di1TrigComboBox->insertItems(0, QStringList()
         << QApplication::translate("FMsgEventDialog", "NONE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("FMsgEventDialog", "RISING EDGE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("FMsgEventDialog", "FALLING EDGE", 0, QApplication::UnicodeUTF8)
        );
        label_6->setText(QApplication::translate("FMsgEventDialog", "DI2", 0, QApplication::UnicodeUTF8));
        di2TrigComboBox->clear();
        di2TrigComboBox->insertItems(0, QStringList()
         << QApplication::translate("FMsgEventDialog", "NONE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("FMsgEventDialog", "RISING EDGE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("FMsgEventDialog", "FALLING EDGE", 0, QApplication::UnicodeUTF8)
        );
        label_7->setText(QApplication::translate("FMsgEventDialog", "DI3", 0, QApplication::UnicodeUTF8));
        di3TrigComboBox->clear();
        di3TrigComboBox->insertItems(0, QStringList()
         << QApplication::translate("FMsgEventDialog", "NONE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("FMsgEventDialog", "RISING EDGE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("FMsgEventDialog", "FALLING EDGE", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class FMsgEventDialog: public Ui_FMsgEventDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FMSGEVENTDIALOG_H
