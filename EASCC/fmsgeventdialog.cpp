#include "fmsgeventdialog.h"
#include "ui_fmsgeventdialog.h"

FMsgEventDialog::FMsgEventDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FMsgEventDialog)
{
    ui->setupUi(this);
}

FMsgEventDialog::~FMsgEventDialog()
{
    delete ui;
}
