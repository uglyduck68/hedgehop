#pragma once
#include "xIni.h"
#include "common/Iini.h"
#include <memory>
class SimSetting : Iini
{
public:
	SimSetting(void);
	~SimSetting(void);
	void Init();
	void NetInit();
	void SerialInit();
	void DDSInit();

	void SaveSetting();
	void LoadSetting();

public:

	unsigned short timeout;

/// TCP 
	std::string tcp_ip;
	unsigned short tcp_port;

/// UDP
	std::string udp_ip;
	unsigned short udp_port;

/// DDS
	std::string dds_ip;
	std::string QOS_Type;
	unsigned short domain;
	unsigned short dds_cnt;

/// Serial
	std::string serial_port;
	int baudRate;
	int dataBits;
	int parity;
	int stopBits;
	int flowCtrl;

private:
	std::shared_ptr<xIni> m_Ini;

};

extern SimSetting g_Setting;