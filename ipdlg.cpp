#include "ipdlg.h"
#include "ui_ipdlg.h"

IPdlg::IPdlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IPdlg)
{
    ui->setupUi(this);
}

IPdlg::~IPdlg()
{
    delete ui;
}
