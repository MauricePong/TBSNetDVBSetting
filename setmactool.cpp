#include "setmactool.h"
#include "ui_setmactool.h"

SetMACTool::SetMACTool(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetMACTool)
{
    ui->setupUi(this);
}

SetMACTool::~SetMACTool()
{
    delete ui;
}
