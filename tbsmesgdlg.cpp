#include "tbsmesgdlg.h"
#include "ui_tbsmesgdlg.h"

TBSMesgDlg::TBSMesgDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TBSMesgDlg)
{
    ui->setupUi(this);
}

TBSMesgDlg::~TBSMesgDlg()
{
    delete ui;
}
