/********************************************************************************
** Form generated from reading UI file 'tbsmesgdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TBSMESGDLG_H
#define UI_TBSMESGDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_TBSMesgDlg
{
public:
    QGridLayout *gridLayout;
    QPushButton *btn_Left;
    QPushButton *btn_Right;
    QLabel *lab_Msg;
    QSpacerItem *hspc;

    void setupUi(QDialog *TBSMesgDlg)
    {
        if (TBSMesgDlg->objectName().isEmpty())
            TBSMesgDlg->setObjectName(QStringLiteral("TBSMesgDlg"));
        TBSMesgDlg->resize(350, 100);
        gridLayout = new QGridLayout(TBSMesgDlg);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        btn_Left = new QPushButton(TBSMesgDlg);
        btn_Left->setObjectName(QStringLiteral("btn_Left"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btn_Left->sizePolicy().hasHeightForWidth());
        btn_Left->setSizePolicy(sizePolicy);
        btn_Left->setStyleSheet(QStringLiteral("background-color: rgb(0, 60, 0);"));

        gridLayout->addWidget(btn_Left, 1, 0, 1, 1);

        btn_Right = new QPushButton(TBSMesgDlg);
        btn_Right->setObjectName(QStringLiteral("btn_Right"));
        sizePolicy.setHeightForWidth(btn_Right->sizePolicy().hasHeightForWidth());
        btn_Right->setSizePolicy(sizePolicy);
        btn_Right->setStyleSheet(QStringLiteral("background-color: rgb(0, 60, 0);"));

        gridLayout->addWidget(btn_Right, 1, 2, 1, 1);

        lab_Msg = new QLabel(TBSMesgDlg);
        lab_Msg->setObjectName(QStringLiteral("lab_Msg"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lab_Msg->sizePolicy().hasHeightForWidth());
        lab_Msg->setSizePolicy(sizePolicy1);
        lab_Msg->setWordWrap(true);

        gridLayout->addWidget(lab_Msg, 0, 0, 1, 3);

        hspc = new QSpacerItem(100, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(hspc, 1, 1, 1, 1);


        retranslateUi(TBSMesgDlg);

        QMetaObject::connectSlotsByName(TBSMesgDlg);
    } // setupUi

    void retranslateUi(QDialog *TBSMesgDlg)
    {
        TBSMesgDlg->setWindowTitle(QString());
        btn_Left->setText(QApplication::translate("TBSMesgDlg", "Yes", nullptr));
        btn_Right->setText(QApplication::translate("TBSMesgDlg", "NO", nullptr));
        lab_Msg->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TBSMesgDlg: public Ui_TBSMesgDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TBSMESGDLG_H
