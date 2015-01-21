#ifndef FMSGEVENTDIALOG_H
#define FMSGEVENTDIALOG_H

#include <QDialog>
#include <inttypes.h>
#include <QDateTime>

namespace Ui {
class FMsgEventDialog;
}

class FMsgEventDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FMsgEventDialog(QWidget *parent, QString fileName, uint8_t schedule, QString description, QDateTime dtime );
    ~FMsgEventDialog();

    bool getAttribs( uint8_t* schedule = 0, QString* description = 0, QDateTime* dtime = 0 );

private:
    Ui::FMsgEventDialog *ui;
    uint8_t _schedule;
    QString _description;
    QDateTime _dtime;
};

#endif // FMSGEVENTDIALOG_H
