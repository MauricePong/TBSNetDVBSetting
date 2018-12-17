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
    QSlider *sli_H;
    QWidget *UpdateWdiget;
    QGridLayout *gridLayout_6;
    QHBoxLayout *horizontalLayout;
    QCheckBox *che_Mip;
    QComboBox *com_IP;
    QToolButton *too_Refresh;
    QToolButton *too_Apply;
    QToolButton *too_Reboot;
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
    QLabel *label_17;
    QComboBox *com_Modulation;
    QLineEdit *lin_Lev;
    QLabel *label_5;
    QLineEdit *lin_CastIP;
    QLabel *label_13;
    QLabel *label_6;
    QLineEdit *lin_Sym;
    QLabel *label_9;
    QLabel *label_16;
    QLabel *label_8;
    QLabel *label_11;
    QLabel *label_7;
    QLineEdit *lin_TSPort;
    QLabel *label_12;
    QLabel *label_15;
    QLabel *label_10;
    QComboBox *com_Protocol;
    QLineEdit *lin_Pla;
    QLabel *label_14;
    QComboBox *com_sfrst;
    QComboBox *com_Freq;

    void setupUi(QDialog *tbsui)
    {
        if (tbsui->objectName().isEmpty())
            tbsui->setObjectName(QStringLiteral("tbsui"));
        tbsui->resize(525, 444);
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
        sli_H = new QSlider(page2);
        sli_H->setObjectName(QStringLiteral("sli_H"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(sli_H->sizePolicy().hasHeightForWidth());
        sli_H->setSizePolicy(sizePolicy3);
        sli_H->setMinimum(6);
        sli_H->setMaximum(72);
        sli_H->setValue(10);
        sli_H->setSliderPosition(10);
        sli_H->setOrientation(Qt::Horizontal);

        gridLayout_4->addWidget(sli_H, 0, 0, 1, 1);

        UpdateWdiget = new QWidget(page2);
        UpdateWdiget->setObjectName(QStringLiteral("UpdateWdiget"));
        UpdateWdiget->setEnabled(true);
        sizePolicy.setHeightForWidth(UpdateWdiget->sizePolicy().hasHeightForWidth());
        UpdateWdiget->setSizePolicy(sizePolicy);
        gridLayout_6 = new QGridLayout(UpdateWdiget);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        che_Mip = new QCheckBox(UpdateWdiget);
        che_Mip->setObjectName(QStringLiteral("che_Mip"));
        che_Mip->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(che_Mip);

        com_IP = new QComboBox(UpdateWdiget);
        com_IP->setObjectName(QStringLiteral("com_IP"));
        com_IP->setEditable(false);

        horizontalLayout->addWidget(com_IP);

        too_Refresh = new QToolButton(UpdateWdiget);
        too_Refresh->setObjectName(QStringLiteral("too_Refresh"));
        sizePolicy1.setHeightForWidth(too_Refresh->sizePolicy().hasHeightForWidth());
        too_Refresh->setSizePolicy(sizePolicy1);
        too_Refresh->setStyleSheet(QStringLiteral("background-color: rgb(0, 60, 0);"));

        horizontalLayout->addWidget(too_Refresh);

        too_Apply = new QToolButton(UpdateWdiget);
        too_Apply->setObjectName(QStringLiteral("too_Apply"));
        sizePolicy1.setHeightForWidth(too_Apply->sizePolicy().hasHeightForWidth());
        too_Apply->setSizePolicy(sizePolicy1);
        too_Apply->setStyleSheet(QStringLiteral("background-color: rgb(0, 60, 0);"));

        horizontalLayout->addWidget(too_Apply);

        too_Reboot = new QToolButton(UpdateWdiget);
        too_Reboot->setObjectName(QStringLiteral("too_Reboot"));
        sizePolicy1.setHeightForWidth(too_Reboot->sizePolicy().hasHeightForWidth());
        too_Reboot->setSizePolicy(sizePolicy1);
        too_Reboot->setStyleSheet(QStringLiteral("background-color: rgb(0, 60, 0);"));

        horizontalLayout->addWidget(too_Reboot);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 2);
        horizontalLayout->setStretch(2, 1);
        horizontalLayout->setStretch(3, 1);
        horizontalLayout->setStretch(4, 1);

        gridLayout_6->addLayout(horizontalLayout, 0, 0, 1, 1);

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
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(che_dhcp->sizePolicy().hasHeightForWidth());
        che_dhcp->setSizePolicy(sizePolicy4);

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
        groupBox_2->setCheckable(false);
        gridLayout_5 = new QGridLayout(groupBox_2);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        label_17 = new QLabel(groupBox_2);
        label_17->setObjectName(QStringLiteral("label_17"));

        gridLayout_5->addWidget(label_17, 7, 0, 1, 1);

        com_Modulation = new QComboBox(groupBox_2);
        com_Modulation->addItem(QString());
        com_Modulation->addItem(QString());
        com_Modulation->addItem(QString());
        com_Modulation->addItem(QString());
        com_Modulation->addItem(QString());
        com_Modulation->setObjectName(QStringLiteral("com_Modulation"));

        gridLayout_5->addWidget(com_Modulation, 5, 1, 1, 1);

        lin_Lev = new QLineEdit(groupBox_2);
        lin_Lev->setObjectName(QStringLiteral("lin_Lev"));
        lin_Lev->setClearButtonEnabled(false);

        gridLayout_5->addWidget(lin_Lev, 3, 1, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);

        gridLayout_5->addWidget(label_5, 5, 0, 1, 1);

        lin_CastIP = new QLineEdit(groupBox_2);
        lin_CastIP->setObjectName(QStringLiteral("lin_CastIP"));

        gridLayout_5->addWidget(lin_CastIP, 7, 1, 1, 1);

        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QStringLiteral("label_13"));
        sizePolicy1.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy1);

        gridLayout_5->addWidget(label_13, 3, 2, 1, 1);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);

        gridLayout_5->addWidget(label_6, 4, 0, 1, 1);

        lin_Sym = new QLineEdit(groupBox_2);
        lin_Sym->setObjectName(QStringLiteral("lin_Sym"));

        gridLayout_5->addWidget(lin_Sym, 4, 1, 1, 1);

        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        sizePolicy1.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy1);

        gridLayout_5->addWidget(label_9, 2, 0, 1, 1);

        label_16 = new QLabel(groupBox_2);
        label_16->setObjectName(QStringLiteral("label_16"));
        sizePolicy1.setHeightForWidth(label_16->sizePolicy().hasHeightForWidth());
        label_16->setSizePolicy(sizePolicy1);

        gridLayout_5->addWidget(label_16, 6, 0, 1, 1);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        sizePolicy1.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy1);

        gridLayout_5->addWidget(label_8, 3, 0, 1, 1);

        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        sizePolicy1.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy1);

        gridLayout_5->addWidget(label_11, 1, 2, 1, 1);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        sizePolicy1.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy1);

        gridLayout_5->addWidget(label_7, 1, 0, 1, 1);

        lin_TSPort = new QLineEdit(groupBox_2);
        lin_TSPort->setObjectName(QStringLiteral("lin_TSPort"));

        gridLayout_5->addWidget(lin_TSPort, 8, 1, 1, 1);

        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        sizePolicy1.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy1);

        gridLayout_5->addWidget(label_12, 2, 2, 1, 1);

        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout_5->addWidget(label_15, 8, 0, 1, 1);

        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        sizePolicy1.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy1);

        gridLayout_5->addWidget(label_10, 4, 2, 1, 1);

        com_Protocol = new QComboBox(groupBox_2);
        com_Protocol->addItem(QString());
        com_Protocol->addItem(QString());
        com_Protocol->setObjectName(QStringLiteral("com_Protocol"));

        gridLayout_5->addWidget(com_Protocol, 6, 1, 1, 1);

        lin_Pla = new QLineEdit(groupBox_2);
        lin_Pla->setObjectName(QStringLiteral("lin_Pla"));
        lin_Pla->setReadOnly(true);

        gridLayout_5->addWidget(lin_Pla, 1, 1, 1, 1);

        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout_5->addWidget(label_14, 9, 0, 1, 1);

        com_sfrst = new QComboBox(groupBox_2);
        com_sfrst->addItem(QString());
        com_sfrst->addItem(QString());
        com_sfrst->setObjectName(QStringLiteral("com_sfrst"));

        gridLayout_5->addWidget(com_sfrst, 9, 1, 1, 1);

        com_Freq = new QComboBox(groupBox_2);
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->addItem(QString());
        com_Freq->setObjectName(QStringLiteral("com_Freq"));

        gridLayout_5->addWidget(com_Freq, 2, 1, 1, 1);


        gridLayout_3->addWidget(groupBox_2, 0, 1, 1, 1);

        tw_Set->addTab(tab_KidSetting, QString());

        gridLayout_6->addWidget(tw_Set, 1, 0, 1, 1);


        gridLayout_4->addWidget(UpdateWdiget, 1, 0, 1, 1);

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
        che_Mip->setText(QApplication::translate("tbsui", "Manual add ip", nullptr));
        too_Refresh->setText(QApplication::translate("tbsui", "Refresh", nullptr));
        too_Apply->setText(QApplication::translate("tbsui", "Apply  ", nullptr));
        too_Reboot->setText(QApplication::translate("tbsui", "Restart", nullptr));
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
        label_3->setText(QApplication::translate("tbsui", "Netmask:", nullptr));
        label_4->setText(QApplication::translate("tbsui", "Gateway:", nullptr));
        tw_Set->setTabText(tw_Set->indexOf(tab_IPSetting), QApplication::translate("tbsui", "IP Setting", nullptr));
        gbox_Tuners->setTitle(QApplication::translate("tbsui", "Modulator List:", nullptr));
        che_t0->setText(QApplication::translate("tbsui", "Modulator 0", nullptr));
        che_t1->setText(QApplication::translate("tbsui", "Modulator 1", nullptr));
        che_t2->setText(QApplication::translate("tbsui", "Modulator 2", nullptr));
        che_t3->setText(QApplication::translate("tbsui", "Modulator 3", nullptr));
        groupBox_2->setTitle(QString());
        label_17->setText(QApplication::translate("tbsui", "Multicast/unicast ip:", nullptr));
        com_Modulation->setItemText(0, QApplication::translate("tbsui", "16QAM", nullptr));
        com_Modulation->setItemText(1, QApplication::translate("tbsui", "32QAM", nullptr));
        com_Modulation->setItemText(2, QApplication::translate("tbsui", "64QAM", nullptr));
        com_Modulation->setItemText(3, QApplication::translate("tbsui", "128QAM", nullptr));
        com_Modulation->setItemText(4, QApplication::translate("tbsui", "256QAM", nullptr));

        lin_Lev->setText(QString());
        label_5->setText(QApplication::translate("tbsui", "Modulation:", nullptr));
        label_13->setText(QApplication::translate("tbsui", "(-35~0dBm)", nullptr));
        label_6->setText(QApplication::translate("tbsui", "Symbolrate:", nullptr));
        lin_Sym->setText(QApplication::translate("tbsui", "6875", nullptr));
        label_9->setText(QApplication::translate("tbsui", "Frequence:", nullptr));
        label_16->setText(QApplication::translate("tbsui", "Net protocol:", nullptr));
        label_8->setText(QApplication::translate("tbsui", "Level:", nullptr));
        label_11->setText(QApplication::translate("tbsui", "(bps)", nullptr));
        label_7->setText(QApplication::translate("tbsui", "Playrate:", nullptr));
        lin_TSPort->setText(QString());
        label_12->setText(QApplication::translate("tbsui", "MHZ", nullptr));
        label_15->setText(QApplication::translate("tbsui", "TS Port:", nullptr));
        label_10->setText(QApplication::translate("tbsui", "(2000-7200\n"
"kbps)", nullptr));
        com_Protocol->setItemText(0, QApplication::translate("tbsui", "UDP", nullptr));
        com_Protocol->setItemText(1, QApplication::translate("tbsui", "RTP", nullptr));

        lin_Pla->setText(QApplication::translate("tbsui", "0", nullptr));
        label_14->setText(QApplication::translate("tbsui", "Soft reset:", nullptr));
        com_sfrst->setItemText(0, QApplication::translate("tbsui", "NO", nullptr));
        com_sfrst->setItemText(1, QApplication::translate("tbsui", "YES", nullptr));

        com_Freq->setItemText(0, QApplication::translate("tbsui", ".", nullptr));
        com_Freq->setItemText(1, QApplication::translate("tbsui", "114.000", nullptr));
        com_Freq->setItemText(2, QApplication::translate("tbsui", "122.000", nullptr));
        com_Freq->setItemText(3, QApplication::translate("tbsui", "130.000", nullptr));
        com_Freq->setItemText(4, QApplication::translate("tbsui", "138.000", nullptr));
        com_Freq->setItemText(5, QApplication::translate("tbsui", "146.000", nullptr));
        com_Freq->setItemText(6, QApplication::translate("tbsui", "154.000", nullptr));
        com_Freq->setItemText(7, QApplication::translate("tbsui", "162.000", nullptr));
        com_Freq->setItemText(8, QApplication::translate("tbsui", "170.000", nullptr));
        com_Freq->setItemText(9, QApplication::translate("tbsui", "186.000", nullptr));
        com_Freq->setItemText(10, QApplication::translate("tbsui", "194.000", nullptr));
        com_Freq->setItemText(11, QApplication::translate("tbsui", "202.000", nullptr));
        com_Freq->setItemText(12, QApplication::translate("tbsui", "210.000", nullptr));
        com_Freq->setItemText(13, QApplication::translate("tbsui", "218.000", nullptr));
        com_Freq->setItemText(14, QApplication::translate("tbsui", "226.000", nullptr));
        com_Freq->setItemText(15, QApplication::translate("tbsui", "234.000", nullptr));
        com_Freq->setItemText(16, QApplication::translate("tbsui", "242.000", nullptr));
        com_Freq->setItemText(17, QApplication::translate("tbsui", "250.000", nullptr));
        com_Freq->setItemText(18, QApplication::translate("tbsui", "258.000", nullptr));
        com_Freq->setItemText(19, QApplication::translate("tbsui", "266.000", nullptr));
        com_Freq->setItemText(20, QApplication::translate("tbsui", "274.000", nullptr));
        com_Freq->setItemText(21, QApplication::translate("tbsui", "282.000", nullptr));
        com_Freq->setItemText(22, QApplication::translate("tbsui", "290.000", nullptr));
        com_Freq->setItemText(23, QApplication::translate("tbsui", "298.000", nullptr));
        com_Freq->setItemText(24, QApplication::translate("tbsui", "306.000", nullptr));
        com_Freq->setItemText(25, QApplication::translate("tbsui", "314.000", nullptr));
        com_Freq->setItemText(26, QApplication::translate("tbsui", "322.000", nullptr));
        com_Freq->setItemText(27, QApplication::translate("tbsui", "330.000", nullptr));
        com_Freq->setItemText(28, QApplication::translate("tbsui", "338.000", nullptr));
        com_Freq->setItemText(29, QApplication::translate("tbsui", "346.000", nullptr));
        com_Freq->setItemText(30, QApplication::translate("tbsui", "354.000", nullptr));
        com_Freq->setItemText(31, QApplication::translate("tbsui", "362.000", nullptr));
        com_Freq->setItemText(32, QApplication::translate("tbsui", "370.000", nullptr));
        com_Freq->setItemText(33, QApplication::translate("tbsui", "378.000", nullptr));
        com_Freq->setItemText(34, QApplication::translate("tbsui", "386.000", nullptr));
        com_Freq->setItemText(35, QApplication::translate("tbsui", "394.000", nullptr));
        com_Freq->setItemText(36, QApplication::translate("tbsui", "402.000", nullptr));
        com_Freq->setItemText(37, QApplication::translate("tbsui", "410.000", nullptr));
        com_Freq->setItemText(38, QApplication::translate("tbsui", "418.000", nullptr));
        com_Freq->setItemText(39, QApplication::translate("tbsui", "426.000", nullptr));
        com_Freq->setItemText(40, QApplication::translate("tbsui", "434.000", nullptr));
        com_Freq->setItemText(41, QApplication::translate("tbsui", "442.000", nullptr));
        com_Freq->setItemText(42, QApplication::translate("tbsui", "450.000", nullptr));
        com_Freq->setItemText(43, QApplication::translate("tbsui", "458.000", nullptr));
        com_Freq->setItemText(44, QApplication::translate("tbsui", "466.000", nullptr));
        com_Freq->setItemText(45, QApplication::translate("tbsui", "474.000", nullptr));
        com_Freq->setItemText(46, QApplication::translate("tbsui", "482.000", nullptr));
        com_Freq->setItemText(47, QApplication::translate("tbsui", "490.000", nullptr));
        com_Freq->setItemText(48, QApplication::translate("tbsui", "498.000", nullptr));
        com_Freq->setItemText(49, QApplication::translate("tbsui", "506.000", nullptr));
        com_Freq->setItemText(50, QApplication::translate("tbsui", "514.000", nullptr));
        com_Freq->setItemText(51, QApplication::translate("tbsui", "522.000", nullptr));
        com_Freq->setItemText(52, QApplication::translate("tbsui", "530.000", nullptr));
        com_Freq->setItemText(53, QApplication::translate("tbsui", "538.000", nullptr));
        com_Freq->setItemText(54, QApplication::translate("tbsui", "546.000", nullptr));
        com_Freq->setItemText(55, QApplication::translate("tbsui", "554.000", nullptr));
        com_Freq->setItemText(56, QApplication::translate("tbsui", "562.000", nullptr));
        com_Freq->setItemText(57, QApplication::translate("tbsui", "570.000", nullptr));
        com_Freq->setItemText(58, QApplication::translate("tbsui", "578.000", nullptr));
        com_Freq->setItemText(59, QApplication::translate("tbsui", "586.000", nullptr));
        com_Freq->setItemText(60, QApplication::translate("tbsui", "594.000", nullptr));
        com_Freq->setItemText(61, QApplication::translate("tbsui", "602.000", nullptr));
        com_Freq->setItemText(62, QApplication::translate("tbsui", "610.000", nullptr));
        com_Freq->setItemText(63, QApplication::translate("tbsui", "618.000", nullptr));
        com_Freq->setItemText(64, QApplication::translate("tbsui", "626.000", nullptr));
        com_Freq->setItemText(65, QApplication::translate("tbsui", "634.000", nullptr));
        com_Freq->setItemText(66, QApplication::translate("tbsui", "642.000", nullptr));
        com_Freq->setItemText(67, QApplication::translate("tbsui", "650.000", nullptr));
        com_Freq->setItemText(68, QApplication::translate("tbsui", "658.000", nullptr));
        com_Freq->setItemText(69, QApplication::translate("tbsui", "666.000", nullptr));
        com_Freq->setItemText(70, QApplication::translate("tbsui", "674.000", nullptr));
        com_Freq->setItemText(71, QApplication::translate("tbsui", "682.000", nullptr));
        com_Freq->setItemText(72, QApplication::translate("tbsui", "690.000", nullptr));
        com_Freq->setItemText(73, QApplication::translate("tbsui", "698.000", nullptr));
        com_Freq->setItemText(74, QApplication::translate("tbsui", "706.000", nullptr));
        com_Freq->setItemText(75, QApplication::translate("tbsui", "714.000", nullptr));
        com_Freq->setItemText(76, QApplication::translate("tbsui", "722.000", nullptr));
        com_Freq->setItemText(77, QApplication::translate("tbsui", "730.000", nullptr));
        com_Freq->setItemText(78, QApplication::translate("tbsui", "738.000", nullptr));
        com_Freq->setItemText(79, QApplication::translate("tbsui", "746.000", nullptr));
        com_Freq->setItemText(80, QApplication::translate("tbsui", "754.000", nullptr));
        com_Freq->setItemText(81, QApplication::translate("tbsui", "762.000", nullptr));
        com_Freq->setItemText(82, QApplication::translate("tbsui", "770.000", nullptr));
        com_Freq->setItemText(83, QApplication::translate("tbsui", "778.000", nullptr));
        com_Freq->setItemText(84, QApplication::translate("tbsui", "786.000", nullptr));
        com_Freq->setItemText(85, QApplication::translate("tbsui", "794.000", nullptr));
        com_Freq->setItemText(86, QApplication::translate("tbsui", "802.000", nullptr));
        com_Freq->setItemText(87, QApplication::translate("tbsui", "810.000", nullptr));
        com_Freq->setItemText(88, QApplication::translate("tbsui", "818.000", nullptr));
        com_Freq->setItemText(89, QApplication::translate("tbsui", "826.000", nullptr));
        com_Freq->setItemText(90, QApplication::translate("tbsui", "834.000", nullptr));
        com_Freq->setItemText(91, QApplication::translate("tbsui", "842.000", nullptr));
        com_Freq->setItemText(92, QApplication::translate("tbsui", "850.000", nullptr));
        com_Freq->setItemText(93, QApplication::translate("tbsui", "858.000", nullptr));

        tw_Set->setTabText(tw_Set->indexOf(tab_KidSetting), QApplication::translate("tbsui", "Modulator", nullptr));
    } // retranslateUi

};

namespace Ui {
    class tbsui: public Ui_tbsui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TBSUI_H
