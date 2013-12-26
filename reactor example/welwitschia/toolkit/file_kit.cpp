#include "file_kit.h"
#ifdef OS_LINUX
	#include <unistd.h>
	#include <fnmatch.h>
#endif

namespace wel
{
#define FILE_ITEM_END     (-1)
#define STR_INVALID_NAME  T("?/")
	
	tString ExtractFileName( const tString &strFileName )
	{
		int pos = -1;

		for(pos=(int)strFileName.length()-1; pos>-1; pos--)
		{
			if( T('.') == strFileName[pos] )
			{
				break;
			}
		}//end for

		tString retStr( strFileName.substr( 0, pos ) );
		
		return retStr;
	}

	BOOL ChangeCurrentDir( const tString &strCurrentDir )
	{
#ifdef OS_WIN32
		return ::SetCurrentDirectory( strCurrentDir.c_str() );
#else
		return 0 == ::chdir( strCurrentDir.c_str() );
#endif
	}

	BOOL GetCurrentDir( tString &strCurrentDir )
	{
		BOOL bRet = FALSE;
#ifdef OS_WIN32
		TCHAR patch[MAX_PATH];
		if ( GetCurrentDirectory(MAX_PATH, patch) )
		{
			strCurrentDir = patch;
			bRet = TRUE;
		}
#else
		TCHAR patch[MAX_PATH];
		if ( getcwd(patch, MAX_PATH) )
		{
			strCurrentDir = patch;
			bRet = TRUE;
		}
#endif
		return bRet;
	}


	//============================华丽的分割线<功能函数/类>==================


	CFileItem::CFileItem()
		:m_bFolder(FALSE),
		m_bValid(FALSE),
		m_pParnt(NULL)
	{

	}

	tString CFileItem::GetFullPath() const
	{
		if ( NULL == m_pParnt )
		{
			return T("");
		}

		return m_pParnt->GetFilePath() + m_strName;
	}

	bool CFileItem::FindNext( CFileItem &FileItem ) const
	{
		if ( NULL == m_pParnt )
		{
			return false;
		}

		return m_pParnt->FindNext( FileItem );
	}

	CFileItem& CFileItem::operator ++ ()
	{
		if ( NULL != m_pParnt )
		{
			m_pParnt->FindNext( *this );
		}

		return *this;
	}

	CFileItem& CFileItem::operator ++ (int)
	{
		if ( NULL != m_pParnt )
		{
			m_pParnt->FindNext( *this );
		}

		return *this;
	}

	//==============================华丽的分割线<CFileItem/CFolder>=================

	CFolder::CFolder()
	{
#ifdef OS_WIN32
		m_hFind = INVALID_HANDLE_VALUE;
#elif defined(OS_LINUX)
		m_pDir  = NULL;
#endif
	}
	CFolder::CFolder(tString strFilePath)
		:m_strFilePath(strFilePath)
	{
#ifdef OS_WIN32
		m_hFind = INVALID_HANDLE_VALUE;
#elif defined(OS_LINUX) 
		m_pDir  = NULL;
#endif
	}
	CFolder::~CFolder()
	{
		this->Close();
	}

#ifdef OS_LINUX
	bool CFolder::Find( CFileItem &FileItem )
	{
		if ( NULL == m_pDir )
		{
			return false;
		}

		if ( m_strFilter == T("*.*") )
		{
			struct dirent *pDirent = ::readdir(m_pDir);
			if ( NULL == pDirent )
			{
				FileItem.m_bValid  = FALSE;
				FileItem.m_strName = STR_INVALID_NAME;
				return false;
			}
			else
			{
				FileItem.m_bFolder = pDirent->d_type & 4;
				FileItem.m_strName = pDirent->d_name;
				return true;
			}
		}

		struct dirent *pDirent;
		while ( NULL != (pDirent = ::readdir(m_pDir)) )
		{
			if ( 0 == fnmatch(m_strFilter.c_str(), pDirent->d_name, FNM_PERIOD) )
			{
				FileItem.m_bFolder = pDirent->d_type & 4;
				FileItem.m_strName = pDirent->d_name;
				return true;
			}
		}//end while

		FileItem.m_bValid  = FALSE;
		FileItem.m_strName = STR_INVALID_NAME;
		return false;
	}
#endif

	bool CFolder::FindFirst( CFileItem &FileItem )
	{
		return false;
	}

	bool CFolder::FindFirst( CFileItem &FileItem, const tString &strFilePath, tString strFilter )
	{
		this->Close();

		m_strFilePath = strFilePath;
		m_strFilter   = strFilter;

#ifdef OS_WIN32
		WIN32_FIND_DATA FileData;
		m_hFind = ::FindFirstFile( (m_strFilePath+strFilter).c_str(), &FileData );
		if ( INVALID_HANDLE_VALUE == m_hFind )
		{
			FileItem.m_bValid  = FALSE;
			FileItem.m_strName = STR_INVALID_NAME;
			return false;
		}		
		FileItem.m_bFolder = FileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY;
		FileItem.m_strName = FileData.cFileName;
#elif defined(OS_LINUX)
		m_pDir = ::opendir( (m_strFilePath/*+strFilter*/).c_str() );
		if ( NULL == m_pDir )
		{
			FileItem.m_bValid  = FALSE;
			FileItem.m_strName = STR_INVALID_NAME;
			return false;
		}

		if ( !this->Find(FileItem) )
		{
			return false;
		}
#endif // OS

		FileItem.m_bValid  = TRUE;
		FileItem.m_pParnt  = this;

		return true;
	}

	bool CFolder::FindNext( CFileItem &FileItem )
	{
#ifdef OS_WIN32
		WIN32_FIND_DATA FileData;
		if ( !::FindNextFile( m_hFind, &FileData ) )
		{
			FileItem.m_bValid  = FALSE;
			FileItem.m_strName = STR_INVALID_NAME;
			return false;
		}

		FileItem.m_bValid  = TRUE;
		FileItem.m_bFolder = FileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY;
		FileItem.m_strName = FileData.cFileName;
#elif defined(OS_LINUX)
		if ( !this->Find(FileItem) )
		{
			return false;
		}
#endif

		FileItem.m_pParnt  = this;

		return true;
	}

	void CFolder::Close()
	{
#ifdef OS_WIN32
		if ( INVALID_HANDLE_VALUE != m_hFind )
		{
			::FindClose(m_hFind);
			m_hFind = INVALID_HANDLE_VALUE;
		}
#elif defined(OS_LINUX)
		if ( NULL != m_pDir )
		{
			::closedir(m_pDir);
			m_pDir = NULL;
		}
#endif
	}

}//end namespace ToolKit
