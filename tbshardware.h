#pragma once
#include "tbsbase.h"
class RD_WT_PARM;
/*
 QString msg = QString("%1 -> %2 threadid:[%3]")
			.arg(__FILE__)
			.arg(__FUNCTION__)
			.arg((int)QThread::currentThreadId());
* */

class TBShardware : public QObject, public TBSbase
{
	Q_OBJECT

public:
	TBShardware();
	~TBShardware();
	int readBuffer(int rmode);
	int writeBuffer(int wmode);
	//read
	int readSwitchStatus(void);
	int readIPParm(void);
	int readModulatorParm(void);
	//write
	int writeIPParm(void);
	int writeModulatorParm(void);


	int getRunMode();
	void setRunMode(int mode);
	int getReadMode();
	void setReadMode(int mode);
	int getWriteMode();
	void setWriteMode(int mode);
#ifdef Q_OS_WIN //windows
	SOCKET gethdudpfdMode();
	void sethdudpfdMode(SOCKET f_hdudpfd);
	SOCKET  openNetSocket(QString ip, int port);
	SOCKET  closeNetSocket(SOCKET  socketfd);

#else
	int gethdudpfdMode();
	void sethdudpfdMode(int f_hdudpfd);
	int  openNetSocket(QString ip, int port);
	int  closeNetSocket(int  socketfd);
#endif
	RD_WT_PARM getHardWareParm(void);
	void setHardWareParm(RD_WT_PARM rw);
signals:
	void sigDisplayMsgUI(TBS_Msg_Type *);
public slots:
	void start();
	void stop();
private:
	QMutex m_Mutex;
	bool m_bRun;
	int runmode;
	int readmode;
	int writemode;
	TBS_Msg_Type *tbsmsg;
	RD_WT_PARM rwparm;
};
