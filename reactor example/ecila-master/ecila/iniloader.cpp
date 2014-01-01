#include "iniloader.h"
#include "file.h"








US_ECILA








///////////////////////////////////////////////////////////////////////////////
//
// SectionData
//
///////////////////////////////////////////////////////////////////////////////
SectionData::SectionData()
{
}








SectionData::~SectionData()
{
}








void SectionData::Name(const char_t *name)
{
	name_ = name;
}








const char_t* SectionData::Find(const char_t* key)
{
	ITER_T iter = map_.find(key);
	if(iter == map_.end()) { return 0; }

	return iter->second.c_str();
}








bool_t SectionData::Register(const char_t *key, const char_t *value)
{
	ITER_T iter = map_.find(key);
	if(iter != map_.end()) { ECILA_TRACE(); return FALSE; }

	map_[key] = value;
	return TRUE;
}








bool_t SectionData::UnRegister(const char_t *key)
{
	ITER_T iter = map_.find(key);
	if(iter == map_.end()) { ECILA_TRACE(); return FALSE; }

	map_.erase(iter);
	return TRUE;
}








void SectionData::Dump(uint32_t tab_count)
{
	for(uint32_t i=0; i<tab_count; i++)
	{
		ECILA_PRINT(("\t"));
	}

	ECILA_PRINT(("[+] %s\n", name_.c_str()));

	for(ITER_T iter = map_.begin(); iter != map_.end(); ++iter)
	{
		for(uint32_t i=0; i<tab_count + 1; i++)
		{
			ECILA_PRINT(("\t"));
		}
		
		ECILA_PRINT(("[-] %s = %s\n", iter->first.c_str(), iter->second.c_str()));
	}
}








///////////////////////////////////////////////////////////////////////////////
//
// IniLoader
//
///////////////////////////////////////////////////////////////////////////////
IniLoader::IniLoader()
{
	curr_section_data_ = 0;
}








IniLoader::~IniLoader()
{
	for(ITER_T iter = map_.begin(); iter != map_.end(); ++iter)
	{
		SectionData *sd = iter->second;
		ECILA_SAFE_DELETE(sd);
	}
	map_.clear();
}








bool_t IniLoader::Load(const char_t *filename)
{
	bool_t ret			= FALSE;
	int32_t len			= 0;
	int32_t line_num	= 0;
	char_t line[1024]	= {0, };

	File file;
	ret = file.Open(filename, "r");
	if(!ret) { ECILA_TRACE(); return FALSE; }

	while(file.ReadLine(line, sizeof(line), len))
	{
		line_num++;

		std::string orignal_line = line;
		ret = Parse(line, len);
		if(!ret)
		{
			ECILA_ERROR(("[IniLoader::Load] ini:%s, linenum:%d, line:%s", filename, line_num, orignal_line.c_str()));
			break;
		}
	}

	ret = file.Close();
	if(!ret) { ECILA_TRACE(); return FALSE; }

	curr_section_data_ = 0;
	return TRUE;
}








const char_t* IniLoader::Property(const char_t *section, const char_t* key)
{
	SectionData *data = Find(section);
	if(!data) { ECILA_TRACE(); return 0; }

	return data->Find(key);
}








void IniLoader::DUMPSPEC()
{
	for(ITER_T iter = map_.begin(); iter != map_.end(); ++iter)
	{
		SectionData *sc = iter->second;
		if(!sc) continue;

		iter->second->Dump(Depth()+1);
	}
}








bool_t IniLoader::Parse(char_t *line, int32_t len)
{
	char_t *sp = line;
	char_t *ep = &line[len];

	sp = LTrim(sp, len);
	ep = RTrim(ep, len);
	int32_t line_len = ep - sp;

	if(line_len == 0) { return TRUE; }

	if		(sp[0] == '#' || sp[0] == ';')	{ return TRUE; }
	else if (sp[0] == '[')					{ return ParseSection(sp, line_len); }
	else									{ return ParseProperty(sp, line_len); }
}








bool_t IniLoader::ParseSection(char_t *line, int32_t len)
{
	if(len < 3) { ECILA_TRACE(); return FALSE; }

	bool_t f_end_sb		= FALSE;
	char_t *sp			= &line[1];
	char_t *ep			= &line[len];

	sp = LTrim(sp, len);
	int32_t section_len = ep - sp;

	for(int32_t i=0; i<section_len; i++)
	{
		if(sp[i] == '[')					{ ECILA_TRACE(); return FALSE; }
		if(sp[i] == '#' || sp[i] == ';')	{ sp[i] = '\0'; ep = &sp[i]; break; }
		if(sp[i] == ']')					{ sp[i] = '\0'; ep = &sp[i]; f_end_sb = TRUE; break; }
	}

	if(!f_end_sb) { ECILA_TRACE(); return FALSE; }
	
	ep = RTrim(ep, ep - sp);
	if(ep - sp < 1) { ECILA_TRACE(); return FALSE; }


	//register
	SectionData *data = Find(sp);
	if(!data)
	{
		data = new SectionData();
		if(!data) { ECILA_TRACE(); return FALSE; }

		bool_t ret = Register(sp, data);
		if(!ret) { ECILA_TRACE(); return FALSE; }
	}

	curr_section_data_ = data;
	return TRUE;
}








bool_t IniLoader::ParseProperty(char_t *line, int32_t len)
{
	char_t *ksp			= line;
	char_t *vep			= &line[len];
	char_t *tp			= strstr(line, "=");

	if(!curr_section_data_ || !tp || tp - ksp < 1 || vep - tp < 1) { ECILA_TRACE(); return FALSE; }
	char_t *kep			= tp; *tp = '\0';
	char_t *vsp			= tp + 1;


	//parse key
	int32_t key_len = kep - ksp;
	for(int32_t i=0; i<key_len; i++)
	{
		if(ksp[i] == '#' || ksp[i] == ';')	{ ksp[i] = '\0'; kep = &ksp[i]; break; }    
	}

	kep = RTrim(kep, kep - ksp);
	if(kep - ksp < 1) { ECILA_TRACE(); return FALSE; }



	//parse value
	vsp = LTrim(vsp, vep - vsp);
	int32_t value_len = vep - vsp;
	for(int32_t i=0; i<value_len; i++)
	{
		if(vsp[i] == '#' || vsp[i] == ';')	{ vsp[i] = '\0'; vep = &vsp[i]; break; }    
	}

	vep = RTrim(vep, vep - vsp);
	if(vep - vsp < 1) { ECILA_TRACE(); return FALSE; }



	//register
	char_t *key		= ksp;
	char_t *value	= vsp;
	bool_t ret = curr_section_data_->Register(key, value);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	return TRUE;
}








char_t* IniLoader::LTrim(char_t *sp, int32_t len)
{
	char *str = sp;
	for(int32_t i=0; i<len; i++)
	{
		if(str[i] == ' ' || str[i] == '\t')	{ continue; }
		else								{ str = &str[i]; break; }
	}

	return str;
}








char_t* IniLoader::RTrim(char_t *ep, int32_t len)
{
	char *str = ep;
	for(int32_t i=0; i<len; i++)
	{
		str--;

		if(*str == ' ' || *str == '\t' || *str == '\r' || *str == '\n')	{ continue; }
		else															{ str++; *str = '\0'; break; }
	}

	return str;
}








SectionData* IniLoader::Find(const char_t *section)
{
	ITER_T iter = map_.find(section);
	if(iter == map_.end()) { return 0; }

	return iter->second;
}








bool_t IniLoader::Register(const char_t *section, SectionData *data)
{
	ITER_T iter = map_.find(section);
	if(iter != map_.end()) { ECILA_TRACE(); return FALSE; }

	data->Name(section);
	map_[section] = data;
	return TRUE;
}








bool_t IniLoader::UnRegister(const char_t *section)
{
	ITER_T iter = map_.find(section);
	if(iter == map_.end()) { ECILA_TRACE(); return FALSE; }

	SectionData *data = iter->second;
	ECILA_SAFE_DELETE(data);

	map_.erase(iter);
	return TRUE;
}


