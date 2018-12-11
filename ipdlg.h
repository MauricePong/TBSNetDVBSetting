#ifndef IPDLG_H
#define IPDLG_H

#include <QDialog>

namespace Ui {
class IPdlg;
}

class IPdlg : public QDialog
{
    Q_OBJECT

public:
    explicit IPdlg(QWidget *parent = nullptr);
    ~IPdlg();

private:
    Ui::IPdlg *ui;
};

#endif // IPDLG_H
