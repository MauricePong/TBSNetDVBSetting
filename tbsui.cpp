#pragma execution_character_set("utf-8")
#include "tbsui.h"
#include "iconhelper.h"
#include "ui_tbsui.h"
#define  ITMEL(n)   ITMEL##n

tbsui::tbsui(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::tbsui)
{
	ui->setupUi(this);
	this->initForm();
	//init_sql();
}

tbsui::~tbsui()
{
	if (tbshd)
	{
		//tbshd->stop();
		connect(&m_Thread, SIGNAL(finished()), tbshd, SLOT(deleteLater()));
		connect(&m_Thread, SIGNAL(finished()), this, SLOT(threadFinished()));
		m_Thread.quit();
		m_Thread.wait();
	}
	if (msgbox) {
		delete msgbox;
		msgbox = NULL;
	}
	//database.close();
	//delete sql_query;
	delete ui;
}

void tbsui::init_sql(void)
{
	//1.create sql
	if (QSqlDatabase::contains("qt_sql_default_connection"))
	{
		database = QSqlDatabase::database("qt_sql_default_connection");
	}
	else
	{
		database = QSqlDatabase::addDatabase("QSQLITE");
		database.setDatabaseName("TBSMAC.db");
	}

	//2.open sql
	if (!database.open())
	{
		qDebug() << "Error: Failed to connect database." << database.lastError();
	}

	//3.create from
	sql_query = new QSqlQuery();
	QString create_sql = "create table macValue (id int,MAC varchar(20))";
	sql_query->prepare(create_sql);
	if (!sql_query->exec())
	{
		qDebug() << "Error: Fail to create table." << sql_query->lastError();
	}
	else
	{
		qDebug() << "Table created!";
	}

	//4.select_sql

	QString select_sql = "select * from macValue";
	if (!sql_query->exec(select_sql))
	{
		qDebug() << sql_query->lastError();
	}
	else
	{
		if (!(sql_query->next()))
		{
			//5.insert_sql
			QString insert_sql = "insert into macValue values (?, ?)";
			sql_query->prepare(insert_sql);
			sql_query->addBindValue(1);
			sql_query->addBindValue("00:22:ab:00:00:00");
			if (!sql_query->exec())
			{
				qDebug() << sql_query->lastError();
			}
			else
			{
				qDebug() << "inserted one!";
			}
			//	sql_query->addBindValue(2);
			//	sql_query->addBindValue("00:22:ab:00:00:00");
			//	if (!sql_query->exec())
			//	{
			//		qDebug() << sql_query->lastError();
			//	}
			//	else
			//	{
			//		qDebug() << "inserted two!";
			//	}

		}
	}

	qDebug() << "init sql over";

}

void tbsui::updateMac_sql(QString qstrMac)
{
	QString update_sql = "update macValue set MAC = :MAC where id = :id";
	sql_query->prepare(update_sql);
	sql_query->bindValue(":MAC", qstrMac.toStdString().data());
	sql_query->bindValue(":id", 1);
	if (!sql_query->exec())
	{
		qDebug() << sql_query->lastError();
	}
	else
	{
		qDebug() << "one updated!";
	}
	//	sql_query->bindValue(":MAC", nqstrMac.toStdString().data());
	//	sql_query->bindValue(":id", 2);
	//	if (!sql_query->exec())
	//		qDebug() << sql_query->lastError();
	//	}
	//	else
	//	{
	//		qDebug() << "two updated!";
	//	}
}


bool tbsui::eventFilter(QObject *watched, QEvent *event)
{
	if (event->type() == QEvent::MouseButtonDblClick) {
		if (watched == ui->widgetTitle) {
			on_btnMenu_Max_clicked();
			return true;
		}
	}

	return QWidget::eventFilter(watched, event);
}

void tbsui::initForm()
{
	this->setProperty("form", true);
	this->setProperty("canMove", true);
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);
	//QPixmap icon(":/image/logo.png");
	QPixmap icon(":/qss/psblack/uilogo/logo.png");
	ui->labIco->setPixmap(icon);
	ui->labIco->resize(icon.width(), icon.height());
	//IconHelper::Instance()->setIcon(ui->labIco, QChar(0xf099), 30);
	IconHelper::Instance()->setIcon(ui->btnMenu_Min, QChar(0xf068));
	IconHelper::Instance()->setIcon(ui->btnMenu_Max, QChar(0xf067));
	IconHelper::Instance()->setIcon(ui->btnMenu_Close, QChar(0xf00d));
	// IconHelper::Instance()->setIcon(ui->lab_enico, QChar(0xf069), 30);
	 //ui->widgetMenu->setVisible(false);
	ui->widgetTitle->installEventFilter(this);
	ui->widgetTitle->setProperty("form", "title");
	ui->widgetTop->setProperty("nav", "top");
	//ui->labTitle->setText("TBS CAPTURE");
	ui->labTitle->setFont(QFont("Microsoft Yahei", 20));
	this->setWindowTitle(ui->labTitle->text());
	//ui->stackedWidget->setStyleSheet("QLabel{font:10pt;}");
	//单独设置指示器大小
	int addWidth = 20;
	int addHeight = 10;
	int rbtnWidth = 15;
	int ckWidth = 13;
	int scrWidth = 12;
	int borderWidth = 3;
	QStringList qss;
	qss.append(QString("QComboBox::drop-down,QDateEdit::drop-down,QTimeEdit::drop-down,QDateTimeEdit::drop-down{width:%1px;}").arg(addWidth));
	qss.append(QString("QComboBox::down-arrow,QDateEdit[calendarPopup=\"true\"]::down-arrow,QTimeEdit[calendarPopup=\"true\"]::down-arrow,"
		"QDateTimeEdit[calendarPopup=\"true\"]::down-arrow{width:%1px;height:%1px;right:2px;}").arg(addHeight));
	qss.append(QString("QRadioButton::indicator{width:%1px;height:%1px;}").arg(rbtnWidth));
	qss.append(QString("QCheckBox::indicator,QGroupBox::indicator,QTreeWidget::indicator,QListWidget::indicator{width:%1px;height:%1px;}").arg(ckWidth));
	qss.append(QString("QScrollBar:horizontal{min-height:%1px;border-radius:%2px;}QScrollBar::handle:horizontal{border-radius:%2px;}"
		"QScrollBar:vertical{min-width:%1px;border-radius:%2px;}QScrollBar::handle:vertical{border-radius:%2px;}").arg(scrWidth).arg(scrWidth / 2));
	qss.append(QString("QWidget#widget_top>QToolButton:pressed,QWidget#widget_top>QToolButton:hover,"
		"QWidget#widget_top>QToolButton:checked,QWidget#widget_top>QLabel:hover{"
		"border-width:0px 0px %1px 0px;}").arg(borderWidth));
	qss.append(QString("QWidget#widgetleft>QPushButton:checked,QWidget#widgetleft>QToolButton:checked,"
		"QWidget#widgetleft>QPushButton:pressed,QWidget#widgetleft>QToolButton:pressed{"
		"border-width:0px 0px 0px %1px;}").arg(borderWidth));
	this->setStyleSheet(qss.join(""));
	//	connect(ui->tree_Dev, SIGNAL(itemClicked(QTreeWidgetItem*, int)), this, SLOT(showSelectedImage(QTreeWidgetItem*, int)));
		//th = new threadTbs();
		//th->start();
	QList<QCheckBox*> ches = ui->gbox_Tuners->findChildren<QCheckBox *>();
	foreach(QCheckBox *che, ches) {
		che->setCheckable(true);
		connect(che, SIGNAL(clicked()), this, SLOT(tunersCheckboxClick()));
	}
	ui->tw_Set->setCurrentIndex(0);
	width_s = this->size().width();
	height_s = this->size().height();
	width = width_s;
	height = height_s;
	uiudpfd = 0;
	iserror = -1;
	devno = 0;
	tbsrwparm.switchStatus = 0x0f;
	msgbox = NULL;
	msgbox = new TBSMesgDlg();
	tbshd = NULL;
	tbshd = new TBShardware();
	tbshd->moveToThread(&m_Thread);
	connect(&m_Thread, SIGNAL(started()), tbshd, SLOT(start()));
	connect(tbshd, SIGNAL(sigDisplayMsgUI(TBS_Msg_Type*)), this, SLOT(soltsDisplayMsgUI(TBS_Msg_Type*)));
	//m_Thread.start();
	//connect(&m_Thread, SIGNAL(finished()), tbshd, SLOT(deleteLater()));
	//connect(&m_Thread, SIGNAL(finished()), this, SLOT(threadFinished()));
	//qDebug() << QString("%1->%2->%3->%4")
	//	.arg(__FILE__)
	//	.arg(__LINE__)
	//	.arg(__FUNCTION__)
	//	.arg((int)QThread::currentThreadId());

}


void tbsui::on_btnMenu_Min_clicked()
{
	showMinimized();
}

void tbsui::on_btnMenu_Max_clicked()
{
	static bool max = false;
	static QRect location = this->geometry();

	if (max) {
		this->setGeometry(location);
		width = width_s;
		height = height_s;
	}
	else {
		location = this->geometry();
		this->setGeometry(qApp->desktop()->availableGeometry());
		width = this->size().width();
		height = this->size().height();
	}

	this->setProperty("canMove", max);
	max = !max;
}

void tbsui::on_btnMenu_Close_clicked()
{
	if (tbshd)
	{
		connect(&m_Thread, SIGNAL(finished()), tbshd, SLOT(deleteLater()));
		connect(&m_Thread, SIGNAL(finished()), this, SLOT(threadFinished()));
		//tbshd->stop();
		m_Thread.quit();
		m_Thread.wait();
		tbshd = NULL;
	}
	if (msgbox) {
		delete msgbox;
		msgbox = NULL;
	}
	close();
}

void tbsui::on_too_Read_clicked()
{
#if 1
	int i = 0;
	const int waittime = 1000;
	int  index = ui->tw_Set->currentIndex();
	QString uiipAndport = ui->lin_IPPort->text();
	QString qstip = uiipAndport.section(':', 0, 0).trimmed();
	int intport = uiipAndport.section(':', 1, 1).trimmed().toInt();
	uiudpfd = tbshd->udpOpen(qstip, intport);
	if (uiudpfd < 3) {
		QToolTip::showText(ui->lin_IPPort->mapToGlobal(QPoint(100, 0)),
			"Network communication failed, please re-enter");
		ui->lin_IPPort->setStyleSheet("QLineEdit{border:1px solid red }");
		uiudpfd = 0;
		tbshd->setudpfd(uiudpfd);
		return;
	}
	else {
		tbshd->setudpfd(uiudpfd);
		tbshd->setRunMode(TBS_READ_FUNC);
		tbshd->setReadMode(READ_SWITCH_STATUS_FUNC);
		m_Thread.quit();
		m_Thread.wait();
		m_Thread.start();
		for (i = 0; i < waittime; i++) {
			if (-1 != iserror) {
				break;
			}
			else {
				QMSLEEP(1);
			}
		}
		if ((0 != iserror) || (waittime == i)) {
			QToolTip::showText(ui->lin_IPPort->mapToGlobal(QPoint(100, 0)),
				"Network communication failed, please re-enter");
			ui->lin_IPPort->setStyleSheet("QLineEdit{border:1px solid red }");
			iserror = -1;
			uiudpfd = tbshd->udpClose(uiudpfd);
			tbshd->setudpfd(uiudpfd);
			return;
		}
		else {
			iserror = -1;
			ui->lin_IPPort->setStyleSheet(
				"QLineEdit{border:1px solid gray border-radius:1px}");
			tbshd->setudpfd(uiudpfd);
			tbsrwparm = tbshd->getHardWareParm();
			qDebug() << "tbsrwparm.switchStatus:" << tbsrwparm.switchStatus;
			ui->che_t0->setDisabled((tbsrwparm.switchStatus >> 0) & 0x01);
			ui->che_t1->setDisabled((tbsrwparm.switchStatus >> 1) & 0x01);
			ui->che_t2->setDisabled((tbsrwparm.switchStatus >> 2) & 0x01);
			ui->che_t3->setDisabled((tbsrwparm.switchStatus >> 3) & 0x01);
		}
	}
	if (0 == index) {
		tbshd->setRunMode(TBS_READ_FUNC);
		tbshd->setReadMode(READ_NET_PARM_FUNC);
		m_Thread.quit();
		m_Thread.wait();
		m_Thread.start();
		for (i = 0; i < waittime; i++) {
			if (-1 != iserror) {
				break;
			}
			else {
				QMSLEEP(1);
			}
		}
		if (0 == iserror) {
			tbsrwparm = tbshd->getHardWareParm();
			ui->che_dhcp->setChecked(tbsrwparm.dhcp);
			ui->lin_LIP->setText(tbsrwparm.ip);
			ui->lin_Lport->setText(QString("%1").arg(tbsrwparm.port));
			ui->Lin_Netmask->setText(tbsrwparm.Netmask);
			ui->lin_Gateway->setText(tbsrwparm.gateway);
		}
	}
	else if(1 == index) {
		if (0 == ((tbsrwparm.switchStatus >> devno) & 0x01)) {
			tbshd->setRunMode(TBS_READ_FUNC);
			tbshd->setReadMode(READ_MODULATOR_PARM_FUNC);
			tbsrwparm.devno = devno;

			m_Thread.quit();
			m_Thread.wait();
			m_Thread.start();
			for (i = 0; i < waittime; i++) {
				if (-1 != iserror) {
					break;
				}
				else {
					QMSLEEP(1);
				}
			}
			if (0 == iserror) {
				tbsrwparm = tbshd->getHardWareParm();
				ui->lin_Pla->setText(tbsrwparm.pla);
				ui->lin_TSPort->setText(QString("%1").arg(tbsrwparm.tsport));
			}
		}
	}
	iserror = -1;
	uiudpfd = tbshd->udpClose(uiudpfd);
	tbshd->setudpfd(uiudpfd);
#endif
}

void tbsui::on_too_Apply_clicked()
{
#if 1
	int i = 0;
	const int waittime = 1000;
	int  index = ui->tw_Set->currentIndex();
	qDebug() << index;
	QString uiipAndport = ui->lin_IPPort->text();
	QString qstip = uiipAndport.section(':', 0, 0).trimmed();
	int intport = uiipAndport.section(':', 1, 1).trimmed().toInt();
	uiudpfd = tbshd->udpOpen(qstip, intport);
	if (uiudpfd < 3) {
		QToolTip::showText(ui->lin_IPPort->mapToGlobal(QPoint(100, 0)),
			"Network communication failed, please re-enter");
		ui->lin_IPPort->setStyleSheet("QLineEdit{border:1px solid red }");
		uiudpfd = 0;
		tbshd->setudpfd(uiudpfd);
		return;
	}
	else {
		tbshd->setudpfd(uiudpfd);
		tbshd->setRunMode(TBS_READ_FUNC);
		tbshd->setReadMode(READ_SWITCH_STATUS_FUNC);
		m_Thread.quit();
		m_Thread.wait();
		m_Thread.start();
		for (i = 0; i < waittime; i++) {
			if (-1 != iserror) {
				break;
			}
			else {
				QMSLEEP(1);
			}
		}
		if ((0 != iserror) || (waittime == i)) {
			QToolTip::showText(ui->lin_IPPort->mapToGlobal(QPoint(100, 0)),
				"Network communication failed, please re-enter");
			ui->lin_IPPort->setStyleSheet("QLineEdit{border:1px solid red }");
			iserror = -1;
			uiudpfd = tbshd->udpClose(uiudpfd);
			tbshd->setudpfd(uiudpfd);
			return;
		}
		else {
			iserror = -1;
			ui->lin_IPPort->setStyleSheet(
				"QLineEdit{border:1px solid gray border-radius:1px}");
			tbshd->setudpfd(uiudpfd);
			tbsrwparm = tbshd->getHardWareParm();
			ui->che_t0->setDisabled((tbsrwparm.switchStatus >> 0) & 0x01);
			ui->che_t1->setDisabled((tbsrwparm.switchStatus >> 1) & 0x01);
			ui->che_t2->setDisabled((tbsrwparm.switchStatus >> 2) & 0x01);
			ui->che_t3->setDisabled((tbsrwparm.switchStatus >> 3) & 0x01);
		}
	}

	if (0 == index) {
		tbshd->setRunMode(TBS_WRITE_FUNC);
		tbshd->setReadMode(WRITE_NET_PARM_FUNC);
		tbsrwparm.dhcp = ui->che_dhcp->isChecked();
		tbsrwparm.ip = ui->lin_LIP->text();
		tbsrwparm.port = ui->lin_Lport->text().toInt();
		tbsrwparm.Netmask = ui->Lin_Netmask->text();
		tbsrwparm.gateway = ui->lin_Gateway->text();

		tbshd->setHardWareParm(tbsrwparm);
		m_Thread.quit();
		m_Thread.wait();
		m_Thread.start();
		for (i = 0; i < waittime; i++) {
			if (-1 != iserror) {
				break;
			}
			else {
				QMSLEEP(1);
			}
		}
	}
	else if (1 == index) {
		if (0 == ((tbsrwparm.switchStatus >> devno) & 0x01)) {
			tbshd->setRunMode(TBS_WRITE_FUNC);
			tbshd->setReadMode(WRITE_MODULATOR_PARM_FUNC);
			tbsrwparm.devno = devno;
			tbsrwparm.qam = ui->com_Modulation->currentIndex();
			tbsrwparm.sym = ui->lin_Sym->text().toInt();
			//tbsrwparm.pla = ui->lin_Pla->text();
			tbsrwparm.fre = ui->lin_Fre->text();
			tbsrwparm.lev = ui->lin_Lev->text();
			tbsrwparm.tsport = ui->lin_TSPort->text().toInt();

			tbshd->setHardWareParm(tbsrwparm);
			m_Thread.quit();
			m_Thread.wait();
			m_Thread.start();
			for (i = 0; i < waittime; i++) {
				if (-1 != iserror) {
					break;
				}
				else {
					QMSLEEP(1);
				}
			}
		}
	}
	iserror = -1;
	uiudpfd = tbshd->udpClose(uiudpfd);
	tbshd->setudpfd(uiudpfd);
#endif
}

void tbsui::threadFinished()
{
	qDebug() << QString("%1->%2->%3")
		.arg(__FILE__)
		.arg(__LINE__)
		.arg(__FUNCTION__);
}

void tbsui::soltsDisplayMsgUI(TBS_Msg_Type* msg)
{
	if (NULL == msgbox) {
		return;
	}
	if (0 == msg->type) {
		return;
	}
	else if (1 == msg->type) {
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
		msgbox->setModal(false);
		msgbox->hide();
	}
	iserror = msg->iserror;
}

void tbsui::tunersCheckboxClick()
{
	QCheckBox *c = (QCheckBox *)sender();
	QString name = c->text();
	QList<QCheckBox *> ches = ui->gbox_Tuners->findChildren<QCheckBox *>();
	foreach(QCheckBox *ch, ches) {
		if (ch == c) {
			ch->setChecked(true);
		}
		else {
			ch->setChecked(false);
		}
	}

	if (name == "Tuner 0") {
		devno = 0;
	}
	else if (name == "Tuner 1") {
		devno = 1;
	}
	else if (name == "Tuner 2") {
		devno = 2;
	}
	else if (name == "Tuner 3") {
		devno = 3;
	}
}

void tbsui::on_sli_H_valueChanged(int value)
{
	qDebug() << value;
	this->setStyleSheet(QString("font:%1pt;").arg(value));
	ui->labTitle->setFont(QFont("Microsoft Yahei", 20 - 10 + value));
	//qDebug()<<width<<"*"<<height;
	this->resize(width, height);
	QString qst = QString("QCheckBox::indicator{ width: %1px; height: %1px; }").arg(4 + value);//改变大小
}

