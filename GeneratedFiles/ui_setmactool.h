/********************************************************************************
** Form generated from reading UI file 'setmactool.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETMACTOOL_H
#define UI_SETMACTOOL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SetMACTool
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *com_LocalIP;
    QLabel *label_2;
    QLineEdit *lin_NetMac;
    QLabel *label_3;
    QLineEdit *lin_SeNetMac;
    QPushButton *btn_Macapply;

    void setupUi(QDialog *SetMACTool)
    {
        if (SetMACTool->objectName().isEmpty())
            SetMACTool->setObjectName(QStringLiteral("SetMACTool"));
        gridLayout = new QGridLayout(SetMACTool);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox = new QGroupBox(SetMACTool);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        com_LocalIP = new QComboBox(groupBox);
        com_LocalIP->setObjectName(QStringLiteral("com_LocalIP"));

        formLayout->setWidget(0, QFormLayout::FieldRole, com_LocalIP);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        lin_NetMac = new QLineEdit(groupBox);
        lin_NetMac->setObjectName(QStringLiteral("lin_NetMac"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lin_NetMac);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        lin_SeNetMac = new QLineEdit(groupBox);
        lin_SeNetMac->setObjectName(QStringLiteral("lin_SeNetMac"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lin_SeNetMac);

        btn_Macapply = new QPushButton(groupBox);
        btn_Macapply->setObjectName(QStringLiteral("btn_Macapply"));

        formLayout->setWidget(3, QFormLayout::FieldRole, btn_Macapply);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);


        retranslateUi(SetMACTool);

        QMetaObject::connectSlotsByName(SetMACTool);
    } // setupUi

    void retranslateUi(QDialog *SetMACTool)
    {
        SetMACTool->setWindowTitle(QApplication::translate("SetMACTool", "Dialog", nullptr));
        groupBox->setTitle(QApplication::translate("SetMACTool", "SetMAC:", nullptr));
        label->setText(QApplication::translate("SetMACTool", "LocalIP:", nullptr));
        label_2->setText(QApplication::translate("SetMACTool", "Display Netmac:", nullptr));
        lin_NetMac->setPlaceholderText(QApplication::translate("SetMACTool", "00:22:ab:00:00:00", nullptr));
        label_3->setText(QApplication::translate("SetMACTool", "Set Netmac:", nullptr));
        lin_SeNetMac->setPlaceholderText(QApplication::translate("SetMACTool", "00:22:ab:00:00:00", nullptr));
        btn_Macapply->setText(QApplication::translate("SetMACTool", "Apply", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SetMACTool: public Ui_SetMACTool {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETMACTOOL_H
