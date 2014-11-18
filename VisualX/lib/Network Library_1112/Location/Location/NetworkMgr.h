#pragma once
#include "LocationMgr.h"
class CNetworkMgr
{
public:
	CNetworkMgr(void);
	~CNetworkMgr(void);
	void Init();
	void Pause();
	void Start();
	void Release();
	void SendGPS(int no,bool flag=false);
	void Send3000();
private:
	int cnt;
	LocationMgr Loc;
};

