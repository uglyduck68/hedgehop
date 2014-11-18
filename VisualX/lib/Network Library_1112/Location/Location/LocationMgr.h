#pragma once
typedef struct POS { double x; double y; } POS;
class LocationMgr
{
public:
	LocationMgr();
	~LocationMgr(void);
	POS& GetLocation(int n);
};

