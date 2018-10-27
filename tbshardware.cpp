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
#ifdef Q_OS_WIN //windows
	SOCKET  sudpfd = 0;
#else 
	int sudpfd = 0;
#endif
	//while (1) {
	QMutexLocker locker(&m_Mutex);
	tbsmsg->type = 1;
	tbsmsg->isreadall = 0;
	tbsmsg->iserror = 0;
	tbsmsg->isread = 3;
	tbsmsg->btnL = 0;
	tbsmsg->btnR = 0;
	tbsmsg->btnRtext = QString("");
	tbsmsg->tilie = QString("information");
	tbsmsg->displaytext = QString("Device running now,please wait..");
	tbsmsg->devip = QString("");
	tbsmsg->devport = 0;
	tbsmsg->switchStatus = 0x0f;
	emit sigDisplayMsgUI(tbsmsg);
	switch (runmode) {
	case TBS_READ_FUNC:
		ret = readBuffer(readmode);
		break;
	case TBS_WRITE_FUNC:
		ret = writeBuffer(writemode);
		break;
	case TBS_UDPMULTICAST_FUNC:
		ret = udpMulticastClinet();
		if (-1 == ret) {
			break;
		}
		sudpfd = udpOpen(first_ip.ip, first_ip.port);
		if (sudpfd < 3) {
			ret = -1;
			break;
		}
		setudpfd(sudpfd);
		ret = readBuffer(READ_NET_PARM_FUNC);
		if (-1 == ret) {
			break;
		}
		if (0 == ret) {
			ret = 4;
		}
		break;
	case TBS_RESET_FUNC:
		ret = reset();
		if (0 == ret) {
			ret = 5;
		}
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
	sudpfd = udpClose(sudpfd);
	setudpfd(sudpfd);

	QMSLEEP(500);
	if (0 == ret) { //read success
		tbsmsg->type = 1;
		tbsmsg->isreadall = 0;
		tbsmsg->iserror = 0;
		tbsmsg->isread = 1;
		tbsmsg->btnL = 0;
		tbsmsg->btnR = 1;
		tbsmsg->btnRtext = QString("OK");
		tbsmsg->tilie = QString("information");
		tbsmsg->displaytext = QString("Success");
		tbsmsg->devip = QString("");
		tbsmsg->devport = 0;
		tbsmsg->switchStatus = 0x0f;
		emit sigDisplayMsgUI(tbsmsg);
	}
	else if (-1 == ret) {//rw failure
		tbsmsg->type = 1;
		tbsmsg->isreadall = 0;
		tbsmsg->iserror = 1;
		tbsmsg->isread = 2;
		tbsmsg->btnL = 0;
		tbsmsg->btnR = 1;
		tbsmsg->btnRtext = QString("OK");
		tbsmsg->tilie = QString("error");
		tbsmsg->displaytext = QString("Failure");
		tbsmsg->devip = QString("");
		tbsmsg->devport = 0;
		tbsmsg->switchStatus = 0x0f;
		emit sigDisplayMsgUI(tbsmsg);
	}
	else if (1 == ret) {
		tbsmsg->type = 1;
		tbsmsg->isreadall = 0;
		tbsmsg->iserror = 0;
		tbsmsg->isread = 2;
		tbsmsg->btnL = 0;
		tbsmsg->btnR = 0;
		tbsmsg->btnRtext = QString("");
		tbsmsg->tilie = QString("information");
		tbsmsg->displaytext = QString("Configuring now,please wait..");
		tbsmsg->devip = QString("");
		tbsmsg->devport = 0;
		tbsmsg->switchStatus = 0x0f;
		emit sigDisplayMsgUI(tbsmsg);
	}
	else if (2 == ret) {
		QMSLEEP(50000);
		tbsmsg->type = 1;
		tbsmsg->isreadall = 0;
		tbsmsg->iserror = 0;
		tbsmsg->isread = 0;
		tbsmsg->btnL = 0;
		tbsmsg->btnR = 1;
		tbsmsg->btnRtext = QString("OK");
		tbsmsg->tilie = QString("information");
		tbsmsg->displaytext = QString("Success");
		tbsmsg->devip = QString("");
		tbsmsg->devport = 0;
		tbsmsg->switchStatus = 0x0f;
		emit sigDisplayMsgUI(tbsmsg);
	}
	else if (3 == ret) {
		tbsmsg->type = 1;
		tbsmsg->isreadall = 0;
		tbsmsg->iserror = 0;
		tbsmsg->isread = 0;
		tbsmsg->btnL = 0;
		tbsmsg->btnR = 1;
		tbsmsg->btnRtext = QString("OK");
		tbsmsg->tilie = QString("information");
		tbsmsg->displaytext = QString("Success");
		tbsmsg->devip = QString("");
		tbsmsg->devport = 0;
		tbsmsg->switchStatus = 0x0f;
		emit sigDisplayMsgUI(tbsmsg);
	}
	else if (4 == ret) {
		tbsmsg->type = 1;
		tbsmsg->isreadall = 1;
		tbsmsg->iserror = 0;
		tbsmsg->isread = 1;
		tbsmsg->btnL = 0;
		tbsmsg->btnR = 1;
		tbsmsg->btnRtext = QString("OK");
		tbsmsg->tilie = QString("information");
		tbsmsg->displaytext = QString("Success");
		tbsmsg->devip = QString("");
		tbsmsg->devport = 0;
		tbsmsg->switchStatus = 0x0f;
		emit sigDisplayMsgUI(tbsmsg);
	}else if (5 == ret) { //rest
		tbsmsg->type = 1;
		tbsmsg->isreadall = 0;
		tbsmsg->iserror = 0;
		tbsmsg->isread = 3;
		tbsmsg->btnL = 0;
		tbsmsg->btnR = 1;
		tbsmsg->btnRtext = QString("OK");
		tbsmsg->tilie = QString("information");
		tbsmsg->displaytext = QString("Success");
		tbsmsg->devip = QString("");
		tbsmsg->devport = 0;
		tbsmsg->switchStatus = 0x0f;
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
	int ret = 1;
	switch (rmode) {
	case READ_NET_PARM_FUNC:
		ret = readIPParm();
		if (ret < 0) {
			return -1;
		}
		//break;
	case READ_MODULATOR_PARM_FUNC:
		if (1 == ret) {
			return readModulatorParm();
		}
		else {
			ret = readModulatorParm();
			if (0 == ret) {
				ret = 4;
			}
			return ret;
		}
		break;
	case READ_NULL_FUNC:
		return -1;
		break;
	default:
		return -1;
		break;
	}
	return 00;
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
	int ret = readREG(REG64_BY_UDP_FUNC, 0x4014, 8, tmp);
	//for (int i = 0; i < 8; i++) {
	//	qDebug("tmp[%d]:%02x  ret= %d", i, tmp[i],ret);
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
	//for (int i = 0; i < 27; i++) {
	//	qDebug() << tmp[i];
	//}
	rwparm.ip = QString("%1.%2.%3.%4")
		.arg(tmp[0x0])
		.arg(tmp[0x01])
		.arg(tmp[0x02])
		.arg(tmp[0x03]);
	TBSSWAP(tmp[0x04], tmp[0x05]);
	rwparm.port = *(u16*)(&tmp[0x04]);
	rwparm.Netmask = QString("%1.%2.%3.%4")
		.arg(tmp[0x10])
		.arg(tmp[0x11])
		.arg(tmp[0x12])
		.arg(tmp[0x13]);
	rwparm.gateway = QString("%1.%2.%3.%4")
		.arg(tmp[0x16])
		.arg(tmp[0x17])
		.arg(tmp[0x18])
		.arg(tmp[0x19]);
	rwparm.dhcp = tmp[0x1a];
	return ret;
}

int TBShardware::readModulatorParm(void)
{

	int ret = 0;
	int i = 0;
	u8 tmp[32] = { 0x41,0x54,0x5f,0x00,0xa3,
	0x00,0x00,0x00,0x00 };
	u8 tmpright0to1byte[2] = { 0x1d,0x1a };
	int tsportaddr[4] = { 0x4020,0x4024,0x4028,0x402c };
	u8 tsportdata[2] = { 0,0 };

	u8 playeratedata[4] = { 0,0,0,0 };
	u8 addrTrigger[4] = { 0,0,0,0 };
	u8  writeMcudata[2] = { 0 };

	ret = readREG(REG64_BY_UDP_FUNC,
		tsportaddr[rwparm.devno],
		2,
		tsportdata);

	if (-1 == ret) {
		return ret;
	}

	TBSSWAP(tsportdata[0], tsportdata[1]);
	rwparm.tsport = *(u16*)(&tsportdata[0]);

	tmp[0] = (u8)(0x00);
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
	tmp[11] = tmpright0to1byte[0];
	tmp[12] = tmpright0to1byte[1];

	writeMcudata[0] = 1;
	ret = writeREG(REG64_BY_UDP_FUNC, 0x4034, 1, writeMcudata);
	if (-1 == ret) {
		return -1;
	}

	QMSLEEP(1000);
	ret = writeREG(REG64_BY_UDP_FUNC, 0x0030, 1, (u8*)&rwparm.devno);
	if (-1 == ret) {
		return ret;
	}

	ret = writeREG(REG64_BY_UDP_FUNC, 0x0040, 5, &tmp[8]);
	if (-1 == ret) {
		return ret;
	}

	ret = writeREG(REG64_BY_UDP_FUNC, 0x0038, 8, &tmp[0]);
	if (-1 == ret) {
		return ret;
	}

	ret = checkStatus_TX(30);
	if (-1 == ret ) {
		return ret;
	}
	checkStatus_RX(30);
	if (-1 == ret) {
		return ret;
	}

	memset(tmp, 0, 32);
	addrTrigger[0] = 1;
	for (i = 0; i < 50; i++) {
		ret = readREG(REG64_BY_UDP_FUNC, 0x4030, 1, addrTrigger);
		if (0 == addrTrigger[0]) {
			//qDebug("readModulatorParm ok");
			break;
		}else {
			QMSLEEP(20);
		}
	}

	if ((i == 1000) || (-1 == ret)) {
		return -1;
	}

	ret = controlExternalMemory(READ, 0x20 + 0x20 * rwparm.devno, tmp, 32);
	if (-1 == ret) {
		return ret;
	}

	writeMcudata[0] = 0;
	ret = writeREG(REG64_BY_UDP_FUNC, 0x4034, 1, writeMcudata);
	if (-1 == ret) {
		return -1;
	}

	rwparm.fre = QString("%1%2%3%4%5%6%7")
		.arg((char)(tmp[0x00])).arg((char)(tmp[0x01]))
		.arg((char)(tmp[0x02])).arg((char)(tmp[0x03]))
		.arg((char)(tmp[0x04])).arg((char)(tmp[0x05]))
		.arg((char)(tmp[0x06]));

	TBSSWAP(tmp[0x0d], tmp[0x0e]);
	rwparm.sym = *(u16*)(&tmp[0x0d]);
	qDebug() <<"qam:"<<tmp[0x0f];
	rwparm.qam = tmp[0x0f]&0x0f;
	for (i = 0; i < 4; i++) {
		playeratedata[i] = tmp[0x13 - i];
	}
	rwparm.pla = QString("%1").arg(*(int*)(&playeratedata[0]));
	rwparm.lev = QString("%1%2%3%4%5")
		.arg((char)(tmp[0x15])).arg((char)(tmp[0x16]))
		.arg((char)(tmp[0x17])).arg((char)(tmp[0x18]))
		.arg((char)(tmp[0x19]));

	return ret;
}

int TBShardware::writeIPParm(void)
{
	u8 tmp[30] = { 0 };
	tmp[0x00] = rwparm.ip.section('.', 0, 0).trimmed().toInt();
	tmp[0x01] = rwparm.ip.section('.', 1, 1).trimmed().toInt();
	tmp[0x02] = rwparm.ip.section('.', 2, 2).trimmed().toInt();
	tmp[0x03] = rwparm.ip.section('.', 3, 3).trimmed().toInt();
	tmp[0x04] = ((rwparm.port >> 8) & 0xff);
	tmp[0x05] = ((rwparm.port) & 0xff);
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
	ret = controlExternalMemory(WRITE, 0x0010, &tmp[0x10], 11);
	if (-1 == ret) {
		return ret;
	}
	//mcu rst
	memset(tmp, 0xff, 8);
	ret = writeREG(REG64_BY_UDP_FUNC, 0x4014, 8, tmp);
	QMSLEEP(10);
	tmp[0] = 0;
	ret = writeREG(REG64_BY_UDP_FUNC, 0x4014, 8, tmp);
	if (0 == ret) {
		ret = 2;
	}
	return ret;
}

int TBShardware::writeModulatorParm(void)
{
	int ret = 0;
	int i = 0;
	int j = 0;
	u8 tmp[32] = { 0x41,0x54,0x5f,0x00,0xa3,0x00,0x00,0x00,0x00 };
	u8 tmpright0to1byte[2] = { 0x1d,0x1a };
	u8 tsportdata[2] = { 0,0 };
	int tsportaddr[4] = { 0x4020,0x4024,0x4028,0x402c };
	u8  writeMcudata[2] = { 0 };

	tsportdata[0] = ((rwparm.tsport >> 8) & 0xff);
	tsportdata[1] = ((rwparm.tsport) & 0xff);

	ret = writeREG(REG64_BY_UDP_FUNC, tsportaddr[rwparm.devno], 2, tsportdata);
	if (-1 == ret) {
		return ret;
	}
#if 1
	//QAM
	tmp[0] = (u8)(0x00);
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

	tmp[14] = tmpright0to1byte[0];
	tmp[15] = tmpright0to1byte[1];

	writeMcudata[0] = 1;
	ret = writeREG(REG64_BY_UDP_FUNC, 0x4034, 1, writeMcudata);
	if (-1 == ret) {
		return ret;
	}

	QMSLEEP(1000);
	ret = writeREG(REG64_BY_UDP_FUNC, 0x0030, 1, (u8*)&rwparm.devno);
	if (-1 == ret) {
		return ret;
	}

	ret = writeREG(REG64_BY_UDP_FUNC, 0x0040, 8, &tmp[8]);
	if (-1 == ret) {
		return ret;
	}

	ret = writeREG(REG64_BY_UDP_FUNC, 0x0038, 8, &tmp[0]);
	if (-1 == ret) {
		return ret;
	}

	ret = checkStatus_TX(30);
	if (-1 == ret) {
		return ret;
	}
	checkStatus_RX(30);
	if (-1 == ret) {
		return ret;
	}

	writeMcudata[0] = 0;
	ret = writeREG(REG64_BY_UDP_FUNC, 0x4034, 1, writeMcudata);
	if (-1 == ret) {
		return ret;
	}
	memset(tmp, 0, 32);
#endif

	QMSLEEP(2000);
#if 1
	//freq
	QString qfreq = QString::number(rwparm.fre.toFloat(), 'f', 3);
	tmp[0] = (u8)(00);
	tmp[1] = (u8)(11 + qfreq.length()); //num

	tmp[2] = 0x41; //0
	tmp[3] = 0x54;
	tmp[4] = 0x5f;

	tmp[5] = 0x00;
	tmp[6] = 0xa3;
	tmp[7] = 0x00;

	tmp[8] = 0x00;
	tmp[9] = 0x00;
	tmp[10] = 0x00;

	for (i = 0; i < qfreq.length(); i++) {
		tmp[11 + i] = (u8)(qfreq.at(i).toLatin1());
		qDebug("%d:%c",11+i, tmp[11 + i]);
	}
	tmp[11 + i] = tmpright0to1byte[0];
	tmp[11 + i + 1] = tmpright0to1byte[1];

	writeMcudata[0] = 1;
	ret = writeREG(REG64_BY_UDP_FUNC, 0x4034, 1, writeMcudata);
	if (-1 == ret) {
		return ret;
	}

	QMSLEEP(1000);
	ret = writeREG(REG64_BY_UDP_FUNC, 0x0030, 1, (u8*)&rwparm.devno);
	if (-1 == ret) {
		return ret;
	}

	ret = writeREG(REG64_BY_UDP_FUNC, 0x0048, 8, &tmp[16]);
	if (-1 == ret) {
		return ret;
	}

	ret = writeREG(REG64_BY_UDP_FUNC, 0x0040, 8, &tmp[8]);
	if (-1 == ret) {
		return ret;
	}

	ret = writeREG(REG64_BY_UDP_FUNC, 0x0038, 8, &tmp[0]);
	if (-1 == ret) {
		return ret;
	}

	ret = checkStatus_TX(30);
	if (-1 == ret) {
		return ret;
	}
	checkStatus_RX(30);
	if (-1 == ret) {
		return ret;
	}

	writeMcudata[0] = 0;
	ret = writeREG(REG64_BY_UDP_FUNC, 0x4034, 1, writeMcudata);
	if (-1 == ret) {
		return ret;
	}

	memset(tmp, 0, 32);
#endif
	QMSLEEP(2000);
#if 1 
	//level
	QString qlevel = QString::number(rwparm.lev.toFloat(), 'f', 1);
	tmp[0] = (u8)(0x00); //devno
	tmp[1] = (u8)(11 + qlevel.length()); //num

	tmp[2] = 0x41;
	tmp[3] = 0x54;
	tmp[4] = 0x5f;

	tmp[5] = 0x00;
	tmp[6] = 0xa4;

	tmp[7] = 0x00;
	tmp[8] = 0x00;
	tmp[9] = 0x00;
	tmp[10] = 0x00;

	for (i = 0; i < qlevel.length(); i++) {
		tmp[11 + i] = (u8)(qlevel.at(i).toLatin1());
	}

	tmp[11 + i] = tmpright0to1byte[0];
	tmp[11 + i + 1] = tmpright0to1byte[1];

	writeMcudata[0] = 1;
	ret = writeREG(REG64_BY_UDP_FUNC, 0x4034, 1, writeMcudata);
	if (-1 == ret) {
		return ret;
	}

	QMSLEEP(1000);
	ret = writeREG(REG64_BY_UDP_FUNC, 0x0030, 1, (u8*)&rwparm.devno);
	if (-1 == ret) {
		return ret;
	}

	ret = writeREG(REG64_BY_UDP_FUNC, 0x0048, 2, &tmp[16]);
	if (-1 == ret) {
		return ret;
	}

	ret = writeREG(REG64_BY_UDP_FUNC, 0x0040, 8, &tmp[8]);
	if (-1 == ret) {
		return ret;
	}

	ret = writeREG(REG64_BY_UDP_FUNC, 0x0038, 8, &tmp[0]);
	if (-1 == ret) {
		return ret;
	}

	ret = checkStatus_TX(30);
	if (-1 == ret) {
		return ret;
	}
	checkStatus_RX(30);
	if (-1 == ret) {
		return ret;
	}

	writeMcudata[0] = 0;
	ret = writeREG(REG64_BY_UDP_FUNC, 0x4034, 1, writeMcudata);
	if (-1 == ret) {
		return ret;
	}

	memset(tmp, 0, 32);
#endif

#if 1 
	QMSLEEP(2000);
	ret = readModulatorParm();
#endif
	if (0 == ret) {
		ret = 3;
	}

	return ret;
}

int TBShardware::udpMulticastClinet(void)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int ret = 0;
	int timevalue = 2000;
	getHostIpAddress();
#ifdef Q_OS_WIN //windows
	SOCKET  Mfd;
	SOCKET  mudpfd;
	WSADATA wsaData;
	WSAStartup(MAKEWORD(1, 1), &wsaData);
	int timeout = timevalue;

#else           //linux
	int Mfd;
	int mudpfd;
	struct timeval timeout = { 1,0 };
#endif
	struct sockaddr_in addr;
	char recvtmp[128] = { '\0' };
	char sendbuf[64] = { '\0' };
	char recvbuf[64] = { '\0' };
	u8 tmp[2] = { 0 };
	if ((Mfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
	{
		qDebug() << "fail to socket";
		return -1;
	}
	first_ip.ip = QString("192.168.0.0");
	first_ip.port = 0;
	first_ip.switchStatus = 0x0f;

	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr("239.255.0.9");
	addr.sin_port = htons(21571);//0x5443
	len = sizeof(addr);
	setsockopt(Mfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));
	setsockopt(Mfd, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout, sizeof(timeout));
	sendbuf[0] = 0xc0;//read
	sendbuf[1] = 0xff;
	sendbuf[2] = 0xff;
	sendbuf[3] = 0xff;
	sendbuf[4] = 0x54;
	sendbuf[5] = 0x42;
	sendbuf[6] = 0x53;
	sendbuf[7] = 0x50;
	sendbuf[8] = 0x52;
	sendbuf[9] = 0x4f;
	sendbuf[10] = 0x44;
	sendbuf[11] = 0x54;
	//c0ffffff54425350524f4454
	if (sendto(Mfd, sendbuf, strlen(sendbuf), 0, (struct sockaddr *) &addr, len) < 0)
	{
		qDebug() << " fail to sendto";
		return -1;
	}
	QMSLEEP(100);
	while (i < 16) {
		int n = recvfrom(Mfd, recvbuf, 64, 0, (struct sockaddr *)&addr, &len);
		if (n < 0) {
			qDebug() << QString("%1->%2->%3:scan ip dev over")
				.arg(__FILE__).arg(__LINE__).arg(__FUNCTION__);
			if (i > 0) {
				ret = 0;
			}
			else {
				ret = -1;
			}
			break;
		}
		else {

			/**
			sprintf(recvtmp, "TBS%02x%02x:%d.%d.%d.%d:%d"
				"/%02x:%02x:%02x:%02x:%02x:%02x",
				(u8)0x80, (u8)0x30, (u8)recvbuf[6], \
				(u8)recvbuf[7], (u8)recvbuf[8],
				(u8)recvbuf[9], *(u16*)&tmp[0],
				(u8)recvbuf[12], (u8)recvbuf[13],
				(u8)recvbuf[14], (u8)recvbuf[15],
				(u8)recvbuf[16], (u8)recvbuf[17]);

			if ((((u8)(0x80) != (u8)recvbuf[4]) &&
				((u8)(0x63) != (u8)recvbuf[4])) ||
				(((u8)(0x30) != (u8)recvbuf[5]) &&
				((u8)(0x16) != (u8)recvbuf[5])) ||
					(((u8)(0x00) != (u8)(recvbuf[12])) ||
				((u8)(0x22) != (u8)(recvbuf[13])) ||
						((u8)(0xab) != (u8)(recvbuf[14])))) {
				continue;
			**/

			qDebug("%02x %02x", (u8)recvbuf[4], (u8)recvbuf[5]);
			if (((u8)(0x82) != (u8)recvbuf[4])
				&& ((u8)(0x20) != (u8)recvbuf[5])) {
				continue;
			}

			for (k = 0; k < gatewaynum; k++) {
				if (true == hostip[k].contains(QString("%1.%2.%3")
					.arg((u8)recvbuf[6]).arg((u8)recvbuf[7])
					.arg((u8)recvbuf[8]), Qt::CaseSensitive)) {
					break;
				}
			}
			if (k == gatewaynum) {
				continue;
			}
			tmp[0] = (u8)recvbuf[11];
			tmp[1] = (u8)recvbuf[10];
			tbsmsg->devip = QString("%1.%2.%3.%4").arg((u8)recvbuf[6])
				.arg((u8)recvbuf[7])
				.arg((u8)recvbuf[8])
				.arg((u8)recvbuf[9]);

			tbsmsg->devport = *(u16*)(tmp);
			qDebug() << tbsmsg->devip << tbsmsg->devport;
			mudpfd = udpOpen(tbsmsg->devip, tbsmsg->devport);
			if (mudpfd < 3) {
				continue;
			}
			setudpfd(mudpfd);
			ret = readREG(REG64_BY_UDP_FUNC, 0x4014, 1, &tbsmsg->switchStatus);
			mudpfd = udpClose(mudpfd);
			setudpfd(mudpfd);
			if (ret < 0) {
				continue;
			}
			if (i == 0) {
				first_ip.ip = tbsmsg->devip;
				first_ip.port = tbsmsg->devport;
				first_ip.switchStatus = tbsmsg->switchStatus;
			}
			tbsmsg->type = 2;
			emit sigDisplayMsgUI(tbsmsg);
			QMSLEEP(100);
			i++;
		}
		}
	memset(recvbuf, 0, sizeof(recvbuf));
#ifdef Q_OS_WIN //windows
	closesocket(Mfd);
	WSACleanup();
#else           //linux
	::close(Mfd);
#endif
	return ret;
	}

int TBShardware::getHostIpAddress(void)
{
	QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
	// 获取第一个本主机的IPv4地址
	int nListSize = ipAddressesList.size();
	gatewaynum = 0;
	for (int i = 0; i < nListSize; ++i)
	{
		if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
			ipAddressesList.at(i).toIPv4Address() &&
			(ipAddressesList.at(i) != QHostAddress::Null)) {
			hostip[i] = ipAddressesList.at(i).toString();
			qDebug() << i << "local PC ip:" << hostip[i];
			gatewaynum++;
		}
	}
	// 如果没有找到，则以本地IP地址为IP
	if (0 == gatewaynum) {
		hostip[0] = QHostAddress(QHostAddress::LocalHost).toString();
		qDebug() << "local PC ip:" << hostip[0];
		gatewaynum = 1;
	}
	return 0;
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

int TBShardware::checkStatus_RX(int times)
{
	int i = 0;
	int ret = 0;
	u8 checkstatus[2] = { 0 };
	for (i = 0; i < times; i++) {
		ret = readREG(REG64_BY_UDP_FUNC, 0x0040, 2, checkstatus);
		if (ret < 0) {
			return -1;
		}
		qDebug() << "checkStatus(0x0040):" << checkstatus[0];
		if (1 == (checkstatus[0] & 0x01)) {
			break;
		}
		else {
			QMSLEEP(100);
		}

	}
	if (i == times) {
		return -1;
	}
	return ret;
}

int TBShardware::checkStatus_TX(int times)
{
	int i = 0;
	int ret = 0;
	u8 checkstatus[2] = { 0 };
	for (i = 0; i < times; i++) {
		ret = readREG(REG64_BY_UDP_FUNC, 0x0038, 2, checkstatus);
		if (ret < 0) {
			return -1;
		}
		qDebug() << "checkStatus(0x0038):" << checkstatus[1];
		if (0x1e == (checkstatus[1] & 0x1f)) {
			break;
		}
		else {
			QMSLEEP(100);
		}
	}
	if (i == times) {
		return -1;
	}
	return ret;
}

int TBShardware::reset()
{
	int ret = 0;
	u8 tmp[32] = {0};
	u8 writeMcudata[2] = {0};
 	tmp[0] = (u8)(0x00);
	tmp[1] = 0x07; //num

	tmp[2] = 0x41; //0
	tmp[3] = 0x54;
	tmp[4] = 0x5f;

	tmp[5] = 0xaa;
	tmp[6] = 0xa0;

	tmp[7] = 0x1d;
	tmp[8] = 0x1a;

	writeMcudata[0] = 1;
	ret = writeREG(REG64_BY_UDP_FUNC, 0x4034, 1, writeMcudata);
	if (-1 == ret) {
		return -1;
	}

	QMSLEEP(1000);
	ret = writeREG(REG64_BY_UDP_FUNC, 0x0030, 1, (u8*)&rwparm.devno);
	if (-1 == ret) {
		return ret;
	}

	ret = writeREG(REG64_BY_UDP_FUNC, 0x0040, 1, &tmp[8]);
	if (-1 == ret) {
		return ret;
	}
	ret = writeREG(REG64_BY_UDP_FUNC, 0x0038, 8, &tmp[0]);
	if (-1 == ret) {
		return ret;
	}
	checkStatus_TX(30);
	checkStatus_RX(30);
	writeMcudata[0] = 0;
	ret = writeREG(REG64_BY_UDP_FUNC, 0x4034, 1, writeMcudata);
	if (-1 == ret) {
		return -1;
	}
	return 0;
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

