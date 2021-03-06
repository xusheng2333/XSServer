#ifndef __CEPOLL_H__
#define __CEPOLL_H__
#include<sys/epoll.h>

class CMyUser;

class CMyEpoll
{
	static const int SRV_PORT = 6666;
	static const int CONN_MAX = 10;
	int m_nfd;	
	int m_nepfd;
	bool m_bNotify;
	epoll_event m_evs[CONN_MAX];
	CMyUser* pMyUser;	

	bool myepoll_work(int nCnt);

public:
	CMyEpoll();
	~CMyEpoll();
	bool myepoll_init();
	bool myepoll_process();
	void myepoll_end();
	int get_user_num();
};

#endif
