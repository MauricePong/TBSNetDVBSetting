#include "setmactool.h"
#include "ui_setmactool.h"

SetMACTool::SetMACTool(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetMACTool)
{
    ui->setupUi(this);
	setWindowFlags(windowFlags()&
		~Qt::WindowMinMaxButtonsHint 
		|Qt::WindowMinimizeButtonHint);
	initUI();
}

SetMACTool::~SetMACTool()
{
    delete ui;
}

QString SetMACTool::readNetMacSFile()
{
	QFile f("netmac");
	QString qstnetmac;
	if (!f.open(QIODevice::ReadOnly | QIODevice::Text)) {
		qDebug("read file erro");
		return QString("00:22:ab:00:00:00");
	}
	else {
		QTextStream macInput(&f);
		while (!macInput.atEnd()) {
			qstnetmac = macInput.readLine();
			qDebug() << qstnetmac;
			f.close();
			return qstnetmac;
		}
	}
	
	QString("00:22:ab:00:00:00");
}

int SetMACTool::writeNetMacFile(QString mac)
{
	QFile f("netmac");
	if (!f.open(QIODevice::WriteOnly | QIODevice::Text)) {
		qDebug("write file erro");
		return -1;
	}
	else {
		QTextStream macoutput(&f);
		macoutput << mac;
	}
	f.close();
	return 0;
}

int SetMACTool::initUI(void)
{
	uiudpfd = 0;
	iserror = -1;
	devno = 0;
	netnum = 0;
	com_IP_soltEN_flg = 0;
	tbsrwparm.switchStatus = 0x0f;
	msgbox = NULL;
	msgbox = new TBSMesgDlg();
	tbshd = NULL;
	tbshd = new TBShardware();
	tbshd->moveToThread(&m_Thread);
	connect(&m_Thread, SIGNAL(started()), tbshd, SLOT(start()));
	connect(tbshd, SIGNAL(sigDisplayMsgUI(TBS_Msg_Type*)),
		this, SLOT(soltsDisplayMsgUI(TBS_Msg_Type*)));

	tbsrwparm.devno = devno;
	tbshd->setHardWareParm(tbsrwparm);
	tbshd->setRunMode(TBS_UDPMULTICAST_FUNC);
	m_Thread.start();
	return 0;
}

void SetMACTool::soltsDisplayMsgUI(TBS_Msg_Type * msg)
{
	if (NULL == msgbox) {
		return;
	}

	if (0 == msg->type) {
		return;
	}

	if (1 == msg->type) {
		msgbox->setWinTitle(msg->tilie);
		msgbox->displayText(msg->displaytext);
		msgbox->hideBtn(msg->btnL, msg->btnR, msg->btnRtext);
		if ((0 == msg->btnL) && (0 == msg->btnR)) {
			msgbox->setModal(false);
			msgbox->show();
		}
		else {
			msgbox->setModal(true);
			msgbox->exec();
		}
	}
	else if (2 == msg->type) {
		qDebug() << "netnum:" << netnum << msg->devip << msg->devport;
		nettag[netnum].ip = msg->devip;
		nettag[netnum].port = msg->devport;
		nettag[netnum].switchStatus = msg->switchStatus;
		ui->com_LocalIP->addItem(nettag[netnum].ip, netnum);
		ui->com_LocalIP->setCurrentIndex(0);;
		netnum++;
	}
	else if(3 == msg->type){
		if ((1 == msg->isread)) {
			uiudpfd = tbshd->udpClose(uiudpfd);
			tbshd->setudpfd(uiudpfd);
			if (0 == com_IP_soltEN_flg) {
				connect(ui->com_LocalIP, SIGNAL(currentIndexChanged(int)),
					this, SLOT(slot_com_IP_currentIndexChanged(int)));
				com_IP_soltEN_flg = 1;
			}
		}
		msgbox->setWinTitle(msg->tilie);
		msgbox->displayText(msg->displaytext);
		msgbox->hideBtn(msg->btnL, msg->btnR, msg->btnRtext);
		if ((0 == msg->btnL) && (0 == msg->btnR)) {
			msgbox->setModal(false);
			msgbox->show();
		}
		else {
			msgbox->setModal(true);
			msgbox->exec();
		}
	}

}

void SetMACTool::on_btn_Macapply_clicked()
{
	qDebug() << "111111111111";
}

void SetMACTool::slot_com_LocalIP_currentIndexChanged(int idx)
{
}
