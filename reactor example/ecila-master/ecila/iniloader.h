#pragma once


#include "node.h"








NS_ECILA_START

class DECL_SPEC_DLL SectionData
{
public:
	 SectionData();
	~SectionData();

	void			Name		(const char_t *name);
	const char_t*	Find		(const char_t *key);
	bool_t			Register	(const char_t *key, const char_t *value);
	bool_t			UnRegister	(const char_t *key);
	void			Dump		(uint32_t tab_count = 0);


private:
	typedef std::map< std::string, std::string > MAP_T;
	typedef MAP_T::iterator						 ITER_T;

	MAP_T map_;
	std::string name_;
};








class DECL_SPEC_DLL IniLoader
:	public Node
{
public:

			 IniLoader();
	virtual ~IniLoader();

	CLASSNAME("IniLoader");

	bool_t        Load(const char_t *filename);
	const char_t* Property(const char_t *section, const char_t *key);


private:

	typedef std::map< std::string, SectionData* > MAP_T;
	typedef MAP_T::iterator						  ITER_T;

	MAP_T map_;
	SectionData *curr_section_data_;


	bool_t Parse			(char_t *line, int32_t len);
	bool_t ParseSection		(char_t *line, int32_t len);
	bool_t ParseProperty	(char_t *line, int32_t len);

	char_t* LTrim			(char_t *sp, int32_t len);
	char_t* RTrim			(char_t *ep, int32_t len);

	SectionData* Find		(const char_t *section);
	bool_t		 Register	(const char_t *section, SectionData *data);
	bool_t		 UnRegister	(const char_t *section);

	virtual void  DUMPSPEC();

};

NS_ECILA_END

