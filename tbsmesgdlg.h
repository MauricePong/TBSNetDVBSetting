#ifndef TBSMESGDLG_H
#define TBSMESGDLG_H

#include <QDialog>

namespace Ui {
class TBSMesgDlg;
}

class TBSMesgDlg : public QDialog
{
    Q_OBJECT

public:
    explicit TBSMesgDlg(QWidget *parent = 0);
    ~TBSMesgDlg();

private:
    Ui::TBSMesgDlg *ui;
};

#endif // TBSMESGDLG_H
