#ifndef SETMACTOOL_H
#define SETMACTOOL_H

#include <QDialog>

namespace Ui {
class SetMACTool;
}

class SetMACTool : public QDialog
{
    Q_OBJECT

public:
    explicit SetMACTool(QWidget *parent = 0);
    ~SetMACTool();

private:
    Ui::SetMACTool *ui;
};

#endif // SETMACTOOL_H
