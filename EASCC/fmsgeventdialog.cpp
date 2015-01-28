#include "fmsgeventdialog.h"
#include "ui_fmsgeventdialog.h"

// shedule is one byte:
//  bit 7 - Mon
//  bit 6 - Tue
//  bit 5 - Wed
//  bit 4 - Thu
//  bit 3 - Fri
//  bit 2 - Sat
//  bit 1 - Sun
//  bit 0 - enabled

FMsgEventDialog::FMsgEventDialog(QWidget *parent, QString fileName, uint8_t schedule, QString description, QDateTime dtime ) :
    QDialog(parent),
    ui(new Ui::FMsgEventDialog)
{
    ui->setupUi(this);

    _schedule = schedule;
    _description = description;
    _dtime = dtime;

    connect( ui->byTimerCheckBox, SIGNAL( toggled( bool ) ), ui->timeGroupBox, SLOT( setEnabled( bool ) ) );

    ui->byTimerCheckBox->setChecked( schedule & ( 1 << 0 ) );
    ui->timeGroupBox->setEnabled( schedule & ( 1 << 0 ) );

    ui->monCheckBox->setChecked( schedule & ( 1 << 1 ) );
    ui->tueCheckBox->setChecked( schedule & ( 1 << 2 ) );
    ui->wedCheckBox->setChecked( schedule & ( 1 << 3 ) );
    ui->thuCheckBox->setChecked( schedule & ( 1 << 4 ) );
    ui->friCheckBox->setChecked( schedule & ( 1 << 5 ) );
    ui->satCheckBox->setChecked( schedule & ( 1 << 6 ) );
    ui->sunCheckBox->setChecked( schedule & ( 1 << 7 ) );

    ui->msgNameLabel->setText( fileName );
    ui->msgDescriptioLabel->setText( description );

    ui->dateTimeEdit->setDateTime( dtime );
}



bool FMsgEventDialog::getAttribs( uint8_t* schedule, QString* description, QDateTime* dtime )
{
    QString lDescription;
    uint8_t lSchedule = 0;
    QDateTime lDateTime;

    if( ui->byTimerCheckBox->isChecked() )
    {
        lSchedule |= ( 1 << 0 );
    }

    if( ui->monCheckBox->isChecked() )
    {
        lSchedule |= ( 1 << 1 );
    }

    if( ui->tueCheckBox->isChecked() )
    {
        lSchedule |= ( 1 << 2 );
    }

    if( ui->wedCheckBox->isChecked() )
    {
        lSchedule |= ( 1 << 3 );
    }

    if( ui->thuCheckBox->isChecked() )
    {
        lSchedule |= ( 1 << 4 );
    }

    if( ui->friCheckBox->isChecked() )
    {
        lSchedule |= ( 1 << 5 );
    }

    if( ui->satCheckBox->isChecked() )
    {
        lSchedule |= ( 1 << 6 );
    }

    if( ui->sunCheckBox->isChecked() )
    {
        lSchedule |= ( 1 << 7 );
    }

    lDateTime = ui->dateTimeEdit->dateTime();

    lDescription = _description;

    if( schedule )
    {
        *schedule = lSchedule;
    }

    if( description )
    {
        *description = lDescription;
    }

    if( dtime )
    {
        *dtime = lDateTime;
    }

    return ( lSchedule != _schedule ) | ( lDescription != _description ) | ( lDateTime != _dtime );

}


FMsgEventDialog::~FMsgEventDialog()
{
    delete ui;
}
