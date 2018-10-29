/********************************************************************************
** Form generated from reading UI file 'tbsui.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TBSUI_H
#define UI_TBSUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tbsui
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widgetTitle;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labIco;
    QLabel *labTitle;
    QWidget *widgetTop;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QWidget *widgetMenu;
    QGridLayout *gridLayout_2;
    QPushButton *btnMenu_Close;
    QPushButton *btnMenu_Min;
    QPushButton *btnMenu_Max;
    QSpacerItem *verticalSpacer;
    QStackedWidget *stackedWidget;
    QWidget *page2;
    QGridLayout *gridLayout_4;
    QWidget *UpdateWdiget;
    QGridLayout *gridLayout_6;
    QToolButton *too_Apply;
    QTabWidget *tw_Set;
    QWidget *tab_IPSetting;
    QGridLayout *gridLayout_7;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout;
    QCheckBox *che_dhcp;
    QLineEdit *lin_LIP;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lin_Lport;
    QLineEdit *lin_Gateway;
    QLineEdit *Lin_Netmask;
    QLabel *label_3;
    QLabel *label_4;
    QWidget *tab_KidSetting;
    QGridLayout *gridLayout_3;
    QGroupBox *gbox_Tuners;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *che_t0;
    QCheckBox *che_t1;
    QCheckBox *che_t2;
    QCheckBox *che_t3;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_5;
    QLabel *label_13;
    QLabel *label_5;
    QLabel *label_12;
    QLineEdit *lin_Pla;
    QComboBox *com_Modulation;
    QLabel *label_9;
    QLineEdit *lin_Lev;
    QLineEdit *lin_Fre;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_6;
    QLineEdit *lin_Sym;
    QLabel *label_11;
    QLabel *label_10;
    QLineEdit *lin_TSPort;
    QLabel *label_15;
    QToolButton *too_Refresh;
    QLabel *label_14;
    QComboBox *com_IP;
    QSlider *sli_H;

    void setupUi(QDialog *tbsui)
    {
        if (tbsui->objectName().isEmpty())
            tbsui->setObjectName(QStringLiteral("tbsui"));
        tbsui->resize(520, 640);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tbsui->sizePolicy().hasHeightForWidth());
        tbsui->setSizePolicy(sizePolicy);
        tbsui->setLayoutDirection(Qt::LeftToRight);
        tbsui->setSizeGripEnabled(true);
        verticalLayout = new QVBoxLayout(tbsui);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(1, 1, 1, 1);
        widgetTitle = new QWidget(tbsui);
        widgetTitle->setObjectName(QStringLiteral("widgetTitle"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widgetTitle->sizePolicy().hasHeightForWidth());
        widgetTitle->setSizePolicy(sizePolicy1);
        horizontalLayout_2 = new QHBoxLayout(widgetTitle);
        horizontalLayout_2->setSpacing(10);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(10, 0, 0, 0);
        labIco = new QLabel(widgetTitle);
        labIco->setObjectName(QStringLiteral("labIco"));
        labIco->setStyleSheet(QStringLiteral(""));
        labIco->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(labIco);

        labTitle = new QLabel(widgetTitle);
        labTitle->setObjectName(QStringLiteral("labTitle"));
        labTitle->setStyleSheet(QStringLiteral(""));
        labTitle->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(labTitle);

        widgetTop = new QWidget(widgetTitle);
        widgetTop->setObjectName(QStringLiteral("widgetTop"));
        horizontalLayout_3 = new QHBoxLayout(widgetTop);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);

        horizontalLayout_2->addWidget(widgetTop);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        widgetMenu = new QWidget(widgetTitle);
        widgetMenu->setObjectName(QStringLiteral("widgetMenu"));
        gridLayout_2 = new QGridLayout(widgetMenu);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        btnMenu_Close = new QPushButton(widgetMenu);
        btnMenu_Close->setObjectName(QStringLiteral("btnMenu_Close"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btnMenu_Close->sizePolicy().hasHeightForWidth());
        btnMenu_Close->setSizePolicy(sizePolicy2);
        btnMenu_Close->setMinimumSize(QSize(30, 30));
        btnMenu_Close->setCursor(QCursor(Qt::ArrowCursor));
        btnMenu_Close->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(btnMenu_Close, 0, 3, 1, 1);

        btnMenu_Min = new QPushButton(widgetMenu);
        btnMenu_Min->setObjectName(QStringLiteral("btnMenu_Min"));
        sizePolicy2.setHeightForWidth(btnMenu_Min->sizePolicy().hasHeightForWidth());
        btnMenu_Min->setSizePolicy(sizePolicy2);
        btnMenu_Min->setMinimumSize(QSize(30, 30));
        btnMenu_Min->setCursor(QCursor(Qt::ArrowCursor));
        btnMenu_Min->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(btnMenu_Min, 0, 1, 1, 1);

        btnMenu_Max = new QPushButton(widgetMenu);
        btnMenu_Max->setObjectName(QStringLiteral("btnMenu_Max"));
        sizePolicy2.setHeightForWidth(btnMenu_Max->sizePolicy().hasHeightForWidth());
        btnMenu_Max->setSizePolicy(sizePolicy2);
        btnMenu_Max->setMinimumSize(QSize(30, 30));
        btnMenu_Max->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(btnMenu_Max, 0, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 1, 1, 1, 3);


        horizontalLayout_2->addWidget(widgetMenu);


        verticalLayout->addWidget(widgetTitle);

        stackedWidget = new QStackedWidget(tbsui);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setStyleSheet(QStringLiteral(""));
        page2 = new QWidget();
        page2->setObjectName(QStringLiteral("page2"));
        gridLayout_4 = new QGridLayout(page2);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        UpdateWdiget = new QWidget(page2);
        UpdateWdiget->setObjectName(QStringLiteral("UpdateWdiget"));
        UpdateWdiget->setEnabled(true);
        sizePolicy.setHeightForWidth(UpdateWdiget->sizePolicy().hasHeightForWidth());
        UpdateWdiget->setSizePolicy(sizePolicy);
        gridLayout_6 = new QGridLayout(UpdateWdiget);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        too_Apply = new QToolButton(UpdateWdiget);
        too_Apply->setObjectName(QStringLiteral("too_Apply"));
        too_Apply->setStyleSheet(QStringLiteral("background-color: rgb(0, 60, 0);"));

        gridLayout_6->addWidget(too_Apply, 1, 3, 1, 1);

        tw_Set = new QTabWidget(UpdateWdiget);
        tw_Set->setObjectName(QStringLiteral("tw_Set"));
        tab_IPSetting = new QWidget();
        tab_IPSetting->setObjectName(QStringLiteral("tab_IPSetting"));
        gridLayout_7 = new QGridLayout(tab_IPSetting);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        groupBox_3 = new QGroupBox(tab_IPSetting);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout = new QGridLayout(groupBox_3);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        che_dhcp = new QCheckBox(groupBox_3);
        che_dhcp->setObjectName(QStringLiteral("che_dhcp"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(che_dhcp->sizePolicy().hasHeightForWidth());
        che_dhcp->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(che_dhcp, 0, 0, 1, 1);

        lin_LIP = new QLineEdit(groupBox_3);
        lin_LIP->setObjectName(QStringLiteral("lin_LIP"));

        gridLayout->addWidget(lin_LIP, 1, 1, 1, 1);

        label = new QLabel(groupBox_3);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        lin_Lport = new QLineEdit(groupBox_3);
        lin_Lport->setObjectName(QStringLiteral("lin_Lport"));

        gridLayout->addWidget(lin_Lport, 2, 1, 1, 1);

        lin_Gateway = new QLineEdit(groupBox_3);
        lin_Gateway->setObjectName(QStringLiteral("lin_Gateway"));

        gridLayout->addWidget(lin_Gateway, 4, 1, 1, 1);

        Lin_Netmask = new QLineEdit(groupBox_3);
        Lin_Netmask->setObjectName(QStringLiteral("Lin_Netmask"));

        gridLayout->addWidget(Lin_Netmask, 3, 1, 1, 1);

        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 4, 0, 1, 1);


        gridLayout_7->addWidget(groupBox_3, 2, 0, 1, 2);

        tw_Set->addTab(tab_IPSetting, QString());
        tab_KidSetting = new QWidget();
        tab_KidSetting->setObjectName(QStringLiteral("tab_KidSetting"));
        gridLayout_3 = new QGridLayout(tab_KidSetting);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gbox_Tuners = new QGroupBox(tab_KidSetting);
        gbox_Tuners->setObjectName(QStringLiteral("gbox_Tuners"));
        gbox_Tuners->setCheckable(false);
        verticalLayout_2 = new QVBoxLayout(gbox_Tuners);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        che_t0 = new QCheckBox(gbox_Tuners);
        che_t0->setObjectName(QStringLiteral("che_t0"));
        che_t0->setEnabled(true);
        che_t0->setChecked(true);

        verticalLayout_2->addWidget(che_t0);

        che_t1 = new QCheckBox(gbox_Tuners);
        che_t1->setObjectName(QStringLiteral("che_t1"));

        verticalLayout_2->addWidget(che_t1);

        che_t2 = new QCheckBox(gbox_Tuners);
        che_t2->setObjectName(QStringLiteral("che_t2"));
        che_t2->setEnabled(true);

        verticalLayout_2->addWidget(che_t2);

        che_t3 = new QCheckBox(gbox_Tuners);
        che_t3->setObjectName(QStringLiteral("che_t3"));

        verticalLayout_2->addWidget(che_t3);


        gridLayout_3->addWidget(gbox_Tuners, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(tab_KidSetting);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_5 = new QGridLayout(groupBox_2);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QStringLiteral("label_13"));
        sizePolicy1.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy1);

        gridLayout_5->addWidget(label_13, 3, 2, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);

        gridLayout_5->addWidget(label_5, 5, 0, 1, 1);

        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        sizePolicy1.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy1);

        gridLayout_5->addWidget(label_12, 2, 2, 1, 1);

        lin_Pla = new QLineEdit(groupBox_2);
        lin_Pla->setObjectName(QStringLiteral("lin_Pla"));
        lin_Pla->setReadOnly(true);

        gridLayout_5->addWidget(lin_Pla, 1, 1, 1, 1);

        com_Modulation = new QComboBox(groupBox_2);
        com_Modulation->addItem(QString());
        com_Modulation->addItem(QString());
        com_Modulation->addItem(QString());
        com_Modulation->addItem(QString());
        com_Modulation->addItem(QString());
        com_Modulation->setObjectName(QStringLiteral("com_Modulation"));

        gridLayout_5->addWidget(com_Modulation, 5, 1, 1, 1);

        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        sizePolicy1.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy1);

        gridLayout_5->addWidget(label_9, 2, 0, 1, 1);

        lin_Lev = new QLineEdit(groupBox_2);
        lin_Lev->setObjectName(QStringLiteral("lin_Lev"));
        lin_Lev->setClearButtonEnabled(false);

        gridLayout_5->addWidget(lin_Lev, 3, 1, 1, 1);

        lin_Fre = new QLineEdit(groupBox_2);
        lin_Fre->setObjectName(QStringLiteral("lin_Fre"));
        lin_Fre->setEchoMode(QLineEdit::Normal);
        lin_Fre->setCursorPosition(0);
        lin_Fre->setDragEnabled(false);

        gridLayout_5->addWidget(lin_Fre, 2, 1, 1, 1);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        sizePolicy1.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy1);

        gridLayout_5->addWidget(label_7, 1, 0, 1, 1);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        sizePolicy1.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy1);

        gridLayout_5->addWidget(label_8, 3, 0, 1, 1);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);

        gridLayout_5->addWidget(label_6, 4, 0, 1, 1);

        lin_Sym = new QLineEdit(groupBox_2);
        lin_Sym->setObjectName(QStringLiteral("lin_Sym"));

        gridLayout_5->addWidget(lin_Sym, 4, 1, 1, 1);

        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        sizePolicy1.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy1);

        gridLayout_5->addWidget(label_11, 1, 2, 1, 1);

        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        sizePolicy1.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy1);

        gridLayout_5->addWidget(label_10, 4, 2, 1, 1);

        lin_TSPort = new QLineEdit(groupBox_2);
        lin_TSPort->setObjectName(QStringLiteral("lin_TSPort"));

        gridLayout_5->addWidget(lin_TSPort, 6, 1, 1, 1);

        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout_5->addWidget(label_15, 6, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_2, 0, 1, 1, 1);

        tw_Set->addTab(tab_KidSetting, QString());

        gridLayout_6->addWidget(tw_Set, 2, 0, 1, 4);

        too_Refresh = new QToolButton(UpdateWdiget);
        too_Refresh->setObjectName(QStringLiteral("too_Refresh"));
        too_Refresh->setStyleSheet(QStringLiteral("background-color: rgb(0, 60, 0);"));

        gridLayout_6->addWidget(too_Refresh, 1, 2, 1, 1);

        label_14 = new QLabel(UpdateWdiget);
        label_14->setObjectName(QStringLiteral("label_14"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy4);

        gridLayout_6->addWidget(label_14, 1, 0, 1, 1);

        com_IP = new QComboBox(UpdateWdiget);
        com_IP->setObjectName(QStringLiteral("com_IP"));

        gridLayout_6->addWidget(com_IP, 1, 1, 1, 1);


        gridLayout_4->addWidget(UpdateWdiget, 1, 0, 1, 1);

        sli_H = new QSlider(page2);
        sli_H->setObjectName(QStringLiteral("sli_H"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(sli_H->sizePolicy().hasHeightForWidth());
        sli_H->setSizePolicy(sizePolicy5);
        sli_H->setMinimum(6);
        sli_H->setMaximum(72);
        sli_H->setValue(10);
        sli_H->setSliderPosition(10);
        sli_H->setOrientation(Qt::Horizontal);

        gridLayout_4->addWidget(sli_H, 0, 0, 1, 1);

        stackedWidget->addWidget(page2);

        verticalLayout->addWidget(stackedWidget);


        retranslateUi(tbsui);

        stackedWidget->setCurrentIndex(0);
        tw_Set->setCurrentIndex(1);
        com_Modulation->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(tbsui);
    } // setupUi

    void retranslateUi(QDialog *tbsui)
    {
        tbsui->setWindowTitle(QApplication::translate("tbsui", "Form", nullptr));
        labIco->setText(QString());
        labTitle->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnMenu_Close->setToolTip(QApplication::translate("tbsui", "\345\205\263\351\227\255", nullptr));
#endif // QT_NO_TOOLTIP
        btnMenu_Close->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnMenu_Min->setToolTip(QApplication::translate("tbsui", "\346\234\200\345\260\217\345\214\226", nullptr));
#endif // QT_NO_TOOLTIP
        btnMenu_Min->setText(QString());
        btnMenu_Max->setText(QString());
        too_Apply->setText(QApplication::translate("tbsui", "Apply  ", nullptr));
#ifndef QT_NO_ACCESSIBILITY
        tab_IPSetting->setAccessibleDescription(QString());
#endif // QT_NO_ACCESSIBILITY
        groupBox_3->setTitle(QString());
        che_dhcp->setText(QApplication::translate("tbsui", "DHCP", nullptr));
#ifndef QT_NO_ACCESSIBILITY
        lin_LIP->setAccessibleDescription(QString());
#endif // QT_NO_ACCESSIBILITY
        label->setText(QApplication::translate("tbsui", "Local IP:", nullptr));
        label_2->setText(QApplication::translate("tbsui", "Local port:", nullptr));
        lin_Lport->setInputMask(QApplication::translate("tbsui", "00000", nullptr));
        label_3->setText(QApplication::translate("tbsui", "Netmask:", nullptr));
        label_4->setText(QApplication::translate("tbsui", "Gateway:", nullptr));
        tw_Set->setTabText(tw_Set->indexOf(tab_IPSetting), QApplication::translate("tbsui", "IP Setting", nullptr));
        gbox_Tuners->setTitle(QApplication::translate("tbsui", "Tuner List:", nullptr));
        che_t0->setText(QApplication::translate("tbsui", "Tuner 0", nullptr));
        che_t1->setText(QApplication::translate("tbsui", "Tuner 1", nullptr));
        che_t2->setText(QApplication::translate("tbsui", "Tuner 2", nullptr));
        che_t3->setText(QApplication::translate("tbsui", "Tuner 3", nullptr));
        groupBox_2->setTitle(QString());
        label_13->setText(QApplication::translate("tbsui", "(-35~0dBm)", nullptr));
        label_5->setText(QApplication::translate("tbsui", "Modulation:", nullptr));
        label_12->setText(QApplication::translate("tbsui", "(100~1000MHZ)", nullptr));
        lin_Pla->setText(QApplication::translate("tbsui", "0", nullptr));
        com_Modulation->setItemText(0, QApplication::translate("tbsui", "16QAM", nullptr));
        com_Modulation->setItemText(1, QApplication::translate("tbsui", "32QAM", nullptr));
        com_Modulation->setItemText(2, QApplication::translate("tbsui", "64QAM", nullptr));
        com_Modulation->setItemText(3, QApplication::translate("tbsui", "128QAM", nullptr));
        com_Modulation->setItemText(4, QApplication::translate("tbsui", "256QAM", nullptr));

        label_9->setText(QApplication::translate("tbsui", "Frequence:", nullptr));
        lin_Lev->setText(QString());
#ifndef QT_NO_ACCESSIBILITY
        lin_Fre->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
        lin_Fre->setText(QString());
        label_7->setText(QApplication::translate("tbsui", "Playrate:", nullptr));
        label_8->setText(QApplication::translate("tbsui", "Level:", nullptr));
        label_6->setText(QApplication::translate("tbsui", "Symbolrate:", nullptr));
        lin_Sym->setText(QString());
        label_11->setText(QApplication::translate("tbsui", "(bps)", nullptr));
        label_10->setText(QApplication::translate("tbsui", "(2000-7200\n"
"kbps)", nullptr));
        lin_TSPort->setText(QString());
        label_15->setText(QApplication::translate("tbsui", "TS Port:", nullptr));
        tw_Set->setTabText(tw_Set->indexOf(tab_KidSetting), QApplication::translate("tbsui", "Modulator", nullptr));
        too_Refresh->setText(QApplication::translate("tbsui", "Refresh", nullptr));
        label_14->setText(QApplication::translate("tbsui", "Net list:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class tbsui: public Ui_tbsui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TBSUI_H
