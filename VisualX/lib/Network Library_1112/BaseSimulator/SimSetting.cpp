_appName
#include "stdafx.h"
#include "SimSetting.h"


SimSetting::SimSetting(void)
{
	m_Ini.reset(new xIni("NetSettings.ini"));
}


SimSetting::~SimSetting(void)
{
	m_Ini.reset();
}

void SimSetting::Init()
{
	NetInit();
	SerialInit();
	DDSInit();
}
void SimSetting::NetInit()
{
	/// TCP / UDP Socket Init
	udp_ip = "127.0.0.1";
	udp_port = 0;
	tcp_ip = "127.0.0.1";
	tcp_port = 0;
	timeout = 0;
}

void SimSetting::SerialInit()
{
	serial_port = "COM1";
	baudRate = 0;
	dataBits = 0;
	parity = 0;
	stopBits = 0;
	flowCtrl = 0;
}

void SimSetting::DDSInit()
{
	domain = 1;
	QOS_Type = "Reliable";
	dds_ip = "127.0.0.1";
	dds_cnt = 1;
}
void SimSetting::LoadSetting()
{
	m_Ini->Transfer(false,"NETWORK","TIMEOUT",timeout,1);

	m_Ini->Transfer(false,"SERIAL","PORT",(char*)serial_port.c_str(),16,"COM1");
	m_Ini->Transfer(false,"SERIAL","BAUDRATE",baudRate,0);
	m_Ini->Transfer(false,"SERIAL","DATABITS",dataBits,0);
	m_Ini->Transfer(false,"SERIAL","PARITY",parity,0);
	m_Ini->Transfer(false,"SERIAL","STOPBITS",stopBits,0);
	m_Ini->Transfer(false,"SERIAL","FLOWCTRL",flowCtrl,0);


	m_Ini->Transfer(false,"UDP","IP",(char*)udp_ip.c_str(),16,"0"); //false load true save
	m_Ini->Transfer(false,"UDP","PORT",udp_port,0);

	m_Ini->Transfer(false,"TCP","IP",(char*)tcp_ip.c_str(),16,"0");
	m_Ini->Transfer(false,"TCP","PORT",tcp_port,0);

	m_Ini->Transfer(false,"DDS","IP",(char*)dds_ip.c_str(),16,"0");
	m_Ini->Transfer(false,"DDS","QOS",(char*)QOS_Type.c_str(),16,"Reliable");
	m_Ini->Transfer(false,"DDS","DOMAIN",domain,1);
	m_Ini->Transfer(false,"DDS","DDSCNT",dds_cnt,1);
}
void SimSetting::SaveSetting()
{
	m_Ini->Transfer(true,"NETWORK","TIMEOUT",timeout,1000);

	m_Ini->Transfer(true,"SERIAL","PORT",(char*)serial_port.c_str(),16,"COM1");
	m_Ini->Transfer(true,"SERIAL","BAUDRATE",baudRate,0);
	m_Ini->Transfer(true,"SERIAL","DATABITS",dataBits,0);
	m_Ini->Transfer(true,"SERIAL","PARITY",parity,0);
	m_Ini->Transfer(true,"SERIAL","STOPBITS",stopBits,0);
	m_Ini->Transfer(true,"SERIAL","FLOWCTRL",flowCtrl,0);

	m_Ini->Transfer(true,"UDP","IP",(char*)udp_ip.c_str(),16,"127.0.0.1"); //false load true save
	m_Ini->Transfer(true,"UDP","PORT",udp_port,7777);

	m_Ini->Transfer(true,"TCP","IP",(char*)tcp_ip.c_str(),16,"127.0.0.1");
	m_Ini->Transfer(true,"TCP","PORT",tcp_port,8888);


	m_Ini->Transfer(true,"DDS","IP",(char*)dds_ip.c_str(),16,"127.0.0.1");
	m_Ini->Transfer(true,"DDS","QOS",(char*)QOS_Type.c_str(),16,"Reliable");
	m_Ini->Transfer(true,"DDS","DOMAIN",domain,1);
	m_Ini->Transfer(true,"DDS","DDSCNT",dds_cnt,1);
}
