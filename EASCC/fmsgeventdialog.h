#ifndef FMSGEVENTDIALOG_H
#define FMSGEVENTDIALOG_H

#include <QDialog>

namespace Ui {
class FMsgEventDialog;
}

class FMsgEventDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FMsgEventDialog(QWidget *parent = 0);
    ~FMsgEventDialog();

private:
    Ui::FMsgEventDialog *ui;
};

#endif // FMSGEVENTDIALOG_H
