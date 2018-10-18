#include "tbshardware.h"

TBShardware::TBShardware()
{
	m_bRun = true;
	runmode = 0;
	readmode = 0;
	writemode = 0;
	tbsmsg = new TBS_Msg_Type();
	tbsmsg->type = 0;
	tbsmsg->iserror = -1;
	tbsmsg->btnL = 0;
	tbsmsg->btnR = 0;
	tbsmsg->btnRtext = QString("OK");
	tbsmsg->tilie = QString("");
	tbsmsg->displaytext = QString("");
}

TBShardware::~TBShardware()
{
	if (tbsmsg) {
		delete tbsmsg;
	}
}
void TBShardware::start()
{
	int ret = -1;
	//while (1) {
	QMutexLocker locker(&m_Mutex);
	switch (runmode) {
	case TBS_READ_FUNC:
		ret = readBuffer(readmode);
		break;
	case TBS_WRITE_FUNC:
		ret = writeBuffer(writemode);
		break;
	case TBS_NULL_FUNC:
		ret = -1;
		break;
	default:
		ret = -1;
		break;
	}
	runmode = 0;
	readmode = 0;
	writemode = 0;

	if (0 == ret) {
		tbsmsg->type = 1;
		tbsmsg->iserror = 0;
		tbsmsg->btnL = 0;
		tbsmsg->btnR = 1;
		tbsmsg->btnRtext = QString("OK");
		tbsmsg->tilie = QString("information");
		tbsmsg->displaytext = QString("Success");
		emit sigDisplayMsgUI(tbsmsg);
	}
	else if (-1 == ret) {
		tbsmsg->type = 1;
		tbsmsg->iserror = 1;
		tbsmsg->btnL = 0;
		tbsmsg->btnR = 1;
		tbsmsg->btnRtext = QString("OK");
		tbsmsg->tilie = QString("error");
		tbsmsg->displaytext = QString("Failure");
		emit sigDisplayMsgUI(tbsmsg);
	}
	else if (1 == ret) {
		tbsmsg->type = 1;
		tbsmsg->iserror = 0;
		tbsmsg->btnL = 0;
		tbsmsg->btnR = 0;
		tbsmsg->btnRtext = QString("");
		tbsmsg->tilie = QString("information");
		tbsmsg->displaytext = QString("Configuring now,please wait..");
		emit sigDisplayMsgUI(tbsmsg);
	}
	else if (2 == ret) {
		tbsmsg->type = 2;
		tbsmsg->iserror = 0;
		emit sigDisplayMsgUI(tbsmsg);
	}
	else if (-2 == ret) {
		tbsmsg->type = 2;
		tbsmsg->iserror = 1;
		emit sigDisplayMsgUI(tbsmsg);
	}
	else if (3 == ret) {
		tbsmsg->type = 1;
		tbsmsg->iserror = 0;
		tbsmsg->btnL = 0;
		tbsmsg->btnR = 0;
		tbsmsg->btnRtext = QString("");
		tbsmsg->tilie = QString("information");
		tbsmsg->displaytext = QString("Configuring now,please wait..");
		emit sigDisplayMsgUI(tbsmsg);
		QMSLEEP(10000);
		tbsmsg->type = 1;
		tbsmsg->iserror = 0;
		tbsmsg->btnL = 0;
		tbsmsg->btnR = 1;
		tbsmsg->btnRtext = QString("OK");
		tbsmsg->tilie = QString("information");
		tbsmsg->displaytext = QString("Success");
		emit sigDisplayMsgUI(tbsmsg);
	}

	//	if (false == m_bRun) {
	//		break;
	//	}
		//qDebug() << QString("%1->%2->%3->%4")
		//	.arg(__FILE__)
		//	.arg(__LINE__)
		//	.arg(__FUNCTION__)
		//	.arg((int)QThread::currentThreadId());
}

void TBShardware::stop()
{
	QMutexLocker locker(&m_Mutex);
	m_bRun = false;
}

int TBShardware::readBuffer(int rmode)
{
	switch (rmode) {
	case READ_SWITCH_STATUS_FUNC:
		return readSwitchStatus();
		break;
	case READ_NET_PARM_FUNC:
		return readIPParm();
		break;
	case READ_MODULATOR_PARM_FUNC:
		return readModulatorParm();
		break;
	case READ_NULL_FUNC:
		return -1;
		break;
	default:
		return -1;
		break;
	}
	return 0;
}

int TBShardware::writeBuffer(int wmode)
{
	switch (wmode) {
	case WRITE_NET_PARM_FUNC:
		return writeIPParm();
		break;
	case WRITE_MODULATOR_PARM_FUNC:
		return writeModulatorParm();
		break;
	case WRITE_NULL_FUNC:
		return -1;
		break;
	default:
		return -1;
		break;
	}
	return 0;
}

int TBShardware::readSwitchStatus(void)
{
	u8 tmp[8] = { 0 };
	int ret = readREG(REG64_BY_UDP_FUNC, 0x4018, 8, tmp);
	//for (int i = 0; i < 8; i++) {
	//	qDebug("tmp[%d]:%02x", i, tmp[i]);
	//}
	rwparm.switchStatus = (tmp[0] & 0x0f);
	if (-1 == ret) {
		return -2;
	}
	else if (0 == ret) {
		return 2;
	}
	return 0;
}

int TBShardware::readIPParm(void)
{
	u8 tmp[27] = { 0 };
	int ret = controlExternalMemory(READ, 0x0000, tmp, 27);
	rwparm.ip = QString("%1.%2.%3.%4").arg(tmp[0])
		.arg(tmp[1]).arg(tmp[2]).arg(tmp[3]);
	TBSSWAP(tmp[4], tmp[5]);
	rwparm.port = *(u16*)(&tmp[4]);
	rwparm.Netmask = QString("%1.%2.%3.%4").arg(tmp[10])
		.arg(tmp[11]).arg(tmp[12]).arg(tmp[13]);
	rwparm.gateway = QString("%1.%2.%3.%4").arg(tmp[16])
		.arg(tmp[17]).arg(tmp[18]).arg(tmp[19]);
	rwparm.dhcp = tmp[26];
	return ret;
}

int TBShardware::readModulatorParm(void)
{
	int ret = 0;
	u8 tmp[32] = { 0x41,0x54,0x5f,0x00,0xa3,
	0x00,0x00,0x00,0x00 };
	u8 tmpright0to1byte[2] = { 0x1d,0x1a };
	int tsportaddr[4] = { 0x4020,0x4024,0x4028,0x402c };
	u8 tsportdata[2] = { 0,0 };
	ret = readREG(REG64_BY_UDP_FUNC, tsportaddr[rwparm.devno], 2, tsportdata);
	if (-1 == ret) {
		return ret;
	}
	TBSSWAP(tsportdata[0], tsportdata[1]);
	rwparm.tsport = *(u16*)(&tsportdata[0]);

	tmp[0] = (u8)(rwparm.devno); //devno
	tmp[1] = (u8)(11); //num

	tmp[2] = 0x41; //0
	tmp[3] = 0x54;
	tmp[4] = 0x5f;

	tmp[5] = 0x00;
	tmp[6] = 0xad;

	tmp[7] = 0x00;
	tmp[8] = 0x00;
	tmp[9] = 0x00;
	tmp[10] = 0x00;

	ret = writeREG(REG64_BY_UDP_FUNC, 0x0048, 2, tmpright0to1byte);
	if (-1 == ret) {
		return ret;
	}
	ret = writeREG(REG64_BY_UDP_FUNC, 0x0040, 8, &tmp[3]);
	if (-1 == ret) {
		return ret;
	}
	ret = writeREG(REG64_BY_UDP_FUNC, 0x0038, 3, &tmp[0]);
	if (-1 == ret) {
		return ret;
	}
	return 0;
}

int TBShardware::writeIPParm(void)
{
	u8 tmp[30] = { 0 };
	tmp[0] = rwparm.ip.section('.', 0, 0).trimmed().toInt();
	tmp[1] = rwparm.ip.section('.', 1, 1).trimmed().toInt();
	tmp[2] = rwparm.ip.section('.', 2, 2).trimmed().toInt();
	tmp[3] = rwparm.ip.section('.', 3, 3).trimmed().toInt();
	tmp[4] = ((rwparm.port >> 8) & 0xff);
	tmp[5] = ((rwparm.port) & 0xff);
	int ret = controlExternalMemory(WRITE, 0x0000, tmp, 6);
	if (-1 == ret) {
		return ret;
	}
	tmp[0x10] = rwparm.Netmask.section('.', 0, 0).trimmed().toInt();
	tmp[0x11] = rwparm.Netmask.section('.', 1, 1).trimmed().toInt();
	tmp[0x12] = rwparm.Netmask.section('.', 2, 2).trimmed().toInt();
	tmp[0x13] = rwparm.Netmask.section('.', 3, 3).trimmed().toInt();
	tmp[0x14] = 0;
	tmp[0x15] = 0;
	tmp[0x16] = rwparm.gateway.section('.', 0, 0).trimmed().toInt();
	tmp[0x17] = rwparm.gateway.section('.', 1, 1).trimmed().toInt();
	tmp[0x18] = rwparm.gateway.section('.', 2, 2).trimmed().toInt();
	tmp[0x19] = rwparm.gateway.section('.', 3, 3).trimmed().toInt();
	tmp[0x1a] = rwparm.dhcp;
	ret = controlExternalMemory(WRITE, 0x0010, tmp, 11);
	//mcu rst
	memset(tmp, 0xff, 8);
	ret = writeREG(REG64_BY_UDP_FUNC, 0x4014, 8, tmp);
	QMSLEEP(10);
	tmp[0] = 0;
	ret = writeREG(REG64_BY_UDP_FUNC, 0x4014, 8, tmp);
	if (0 == ret) {
		ret = 3;
	}
	return ret;
}

int TBShardware::writeModulatorParm(void)
{
	int ret = 0;
	int i = 0;
	int j = 0;
	u8 tmp[32] = { 0x41,0x54,0x5f,0x00,0xa3,
		0x00,0x00,0x00,0x00 };
	u8 tmpright0to1byte[2] = { 0x1d,0x1a };

	int tsportaddr[4] = { 0x4020,0x4024,0x4028,0x402c };
	u8 tsportdata[2] = { 0,0 };
	tsportdata[0] = ((rwparm.tsport >> 8) & 0xff);
	tsportdata[1] = ((rwparm.tsport) & 0xff);

	ret = writeREG(REG64_BY_UDP_FUNC, tsportaddr[rwparm.devno], 2, tsportdata);
	if (-1 == ret) {
		return ret;
	}

	//QAM
	tmp[0] = (u8)(rwparm.devno); //devno
	tmp[1] = 0x0e; //num

	tmp[2] = 0x41; //0
	tmp[3] = 0x54;
	tmp[4] = 0x5f;

	tmp[5] = 0xaa;
	tmp[6] = 0xa5;

	tmp[7] = 0x00;
	tmp[8] = 0x00;
	tmp[9] = 0x00;
	tmp[10] = 0x00;

	tmp[11] = (u8)(rwparm.qam & 0x0ff);
	tmp[12] = (u8)((rwparm.sym >> 8) & 0x0ff);
	tmp[13] = (u8)(rwparm.sym & 0x0ff);
	ret = writeREG(REG64_BY_UDP_FUNC, 0x0048, 2, tmpright0to1byte);
	if (-1 == ret) {
		return ret;
	}
	ret = writeREG(REG64_BY_UDP_FUNC, 0x0040, 8, &tmp[6]);
	if (-1 == ret) {
		return ret;
	}
	ret = writeREG(REG64_BY_UDP_FUNC, 0x0038, 6, &tmp[0]);
	if (-1 == ret) {
		return ret;
	}
	memset(tmp, 0, 32);

	//freq
	tmp[0] = (u8)(rwparm.devno); //devno
	tmp[1] = (u8)(11 + rwparm.fre.length()); //num

	tmp[2] = 0x41; //0
	tmp[3] = 0x54;
	tmp[4] = 0x5f;

	tmp[5] = 0x00;
	tmp[6] = 0xa3;

	tmp[7] = 0x00;
	tmp[8] = 0x00;
	tmp[9] = 0x00;
	tmp[10] = 0x00;

	for (i = 0; i < rwparm.fre.length(); i++) {
		tmp[i] = rwparm.fre.at(i).toLatin1();
	}
	ret = writeREG(REG64_BY_UDP_FUNC, 0x0048, 2, tmpright0to1byte);
	if (-1 == ret) {
		return ret;
	}
	ret = writeREG(REG64_BY_UDP_FUNC, 0x0040, 8, &tmp[i - 7]);
	if (-1 == ret) {
		return ret;
	}
	ret = writeREG(REG64_BY_UDP_FUNC, 0x0038, (i - 7), &tmp[0]);
	if (-1 == ret) {
		return ret;
	}

	//level
	tmp[0] = (u8)(rwparm.devno); //devno
	tmp[1] = (u8)(11 + rwparm.lev.length()); //num

	tmp[2] = 0x41; //0
	tmp[3] = 0x54;
	tmp[4] = 0x5f;

	tmp[5] = 0x00;
	tmp[6] = 0xa4;

	tmp[7] = 0x00;
	tmp[8] = 0x00;
	tmp[9] = 0x00;
	tmp[10] = 0x00;

	for (i = 0; i < rwparm.lev.length(); i++) {
		tmp[i] = rwparm.lev.at(i).toLatin1();
	}
	ret = writeREG(REG64_BY_UDP_FUNC, 0x0048, 2, tmpright0to1byte);
	if (-1 == ret) {
		return ret;
	}
	ret = writeREG(REG64_BY_UDP_FUNC, 0x0040, 8, &tmp[i - 7]);
	if (-1 == ret) {
		return ret;
	}
	ret = writeREG(REG64_BY_UDP_FUNC, 0x0038, (i - 7), &tmp[0]);
	if (-1 == ret) {
		return ret;
	}
	//sys rst
	tmp[0] = (u8)(rwparm.devno); //devno
	tmp[1] = 0x07; //num

	tmp[2] = 0x41; //0
	tmp[3] = 0x54;
	tmp[4] = 0x5f;

	tmp[5] = 0xaa;
	tmp[6] = 0xa0;

	ret = writeREG(REG64_BY_UDP_FUNC, 0x0048, 2, tmpright0to1byte);
	if (-1 == ret) {
		return ret;
	}
	ret = writeREG(REG64_BY_UDP_FUNC, 0x0040, 5, &tmp[2]);
	if (-1 == ret) {
		return ret;
	}
	ret = writeREG(REG64_BY_UDP_FUNC, 0x0038, 7, &tmp[0]);
	if (-1 == ret) {
		return ret;
	}
	if (0 == ret) {
		ret = 3;
	}
	return ret;
}

int TBShardware::getRunMode()
{
	return runmode;
}


void TBShardware::setRunMode(int mode)
{
	runmode = mode;
}

int TBShardware::getReadMode()
{
	return readmode;
}

void TBShardware::setReadMode(int mode)
{
	readmode = mode;
}

int TBShardware::getWriteMode()
{
	return writemode;
}

void TBShardware::setWriteMode(int mode)
{
	writemode = mode;
}

#ifdef Q_OS_WIN //windows
SOCKET TBShardware::gethdudpfdMode()
{
	return getudpfd();
}

void TBShardware::sethdudpfdMode(SOCKET f_hdudpfd)
{
	setudpfd(f_hdudpfd);
}
SOCKET TBShardware::openNetSocket(QString ip, int port)
{
	return udpOpen(ip, port);
}
SOCKET TBShardware::closeNetSocket(SOCKET socketfd)
{
	return udpClose(socketfd);
}
#else
int TBShardware::gethdudpfdMode()
{
	return getudpfd();
}
void TBShardware::sethdudpfdMode(int f_hdudpfd)
{
	setudpfd(f_hdudpfd);
}
int TBShardware::openNetSocket(QString ip, int port)
{
	return udpOpen(ip, port);
}
int TBShardware::closeNetSocket(int socketfd)
{
	return udpClose(socketfd);
}
#endif




RD_WT_PARM  TBShardware::getHardWareParm(void)
{
	return rwparm;
}

void TBShardware::setHardWareParm(RD_WT_PARM  rw)
{
	rwparm = rw;
}

