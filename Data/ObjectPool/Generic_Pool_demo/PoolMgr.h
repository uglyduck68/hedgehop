#ifndef POOL_MGR_H
#define POOL_MGR_H
/***********************************************************************
 * PoolMgr.h
 * Rohit Joshi
 * 08-25/2004
 * PoolMgr is a template based generic pool class which allows user to 
 * create object/Object pool.
 * It allows user to set the PoolSize, Object expiration time and
 * if temporary Object is allowed in case of pool is full
 * It is an singleton class
 * TODO: 1. Exception handling/error handling
         2. Support for Multithreading
		 3. Adding a sweeper thread in case of expiration time is defined
 ***********************************************************************/

#include <list>
#include <string>
#include "ObjectHolder.h"

#ifdef WIN32
  #include <windows.h>
  #include "MutexWin.h"
  #include <time.h>
  #define sleep(x) Sleep(x * 1000)
#else  // Linux/Unix
  #include <unistd.h>
  #include "Mutex.h"
#endif

using namespace std;

template<class T> 
class PoolMgr
{
    typedef ObjectHolder<T> ObjHolder;  //typedef for Object Holder
    typedef list<ObjHolder> ObjList;   // typedef for ObjeList
	static Mutex m_mPool;  // Mutex for Pool static instance
	Mutex m_mData;  // Mutex for Pool data

public:
    // Get the Instance of pool manager
    static PoolMgr<T>* GetInstance()
    {
        if(!m_pPoolMgr) {
			Lock<Mutex> gaurd(m_mPool);
			if(!m_pPoolMgr)
                m_pPoolMgr = new PoolMgr<T>();
        }
        return m_pPoolMgr;

    }
	// delete the pool
	static void DeletePool()
	{
		if(m_pPoolMgr) {
            Lock<Mutex> gaurd(m_mPool);
			if(m_pPoolMgr){
                delete m_pPoolMgr;
                m_pPoolMgr = NULL;
			}
		}
		
	}
	// Reset the pool
    void ResetPool()
    {
		{
			Lock<Mutex> gaurd(m_mData);
            m_pPoolMgr->m_oReserved.clear();
            m_pPoolMgr->m_oFree.clear();
            m_pPoolMgr->m_nPoolSize = 0;
            m_pPoolMgr->m_nWaitTime = 3;
            m_pPoolMgr->m_nExpirationTime = 600;
            m_pPoolMgr->m_bTempObjAllowed = true;
		}
		if(m_pPoolMgr) {
			Lock<Mutex> gaurd(m_mPool);
			delete m_pPoolMgr;
			m_pPoolMgr = NULL;
		}
       
    }
	// Initliaze pool
    void Init(unsigned nPoolSize, long nExpirationTime, 
              bool bTempObjAllowed, unsigned nWaitTime = 3)
    {
        if(m_nPoolSize == 0) 
		{
			Lock<Mutex> gaurd(m_mData);
            m_nPoolSize			= nPoolSize,
            m_nExpirationTime	= nExpirationTime,
            m_bTempObjAllowed	= bTempObjAllowed; 
            m_nWaitTime			= nWaitTime;
        }
		else 
		{
            cerr<< "You can't Initialize the pool again" << endl;
        }
    }
    
	// Checkout the Object from pool	
    T* Checkout()
    {
		Lock<Mutex> gaurd(m_mData);

		cout << "Checkout object " << endl;
        
		T* pObj = FindObject();
        
		if(pObj)
		{
            return pObj;
        }
        
		// not found the Obj
        if(m_oFree.size() + m_oReserved.size() < m_nPoolSize) {
            return CreateObject();
        }else if (m_bTempObjAllowed) {
            return CreateObject();
        }else if(m_nExpirationTime != -1){
            while(!pObj) {
                ProcessExpiredObjects();
                pObj = FindObject();
                sleep(m_nWaitTime);
            }
        }
        return NULL;           
    }
    // checkin the Object into pool                          
    void Checkin(T *pObj)
    {
		Lock<Mutex> gaurd(m_mData);
		cout << "Checkin object " << endl;
        
		if(ValidateObject(pObj)) {
            ObjHolder oTemp;
            oTemp.Set(pObj, (long)time(NULL));
            m_oFree.push_back(oTemp);
            oTemp.SetObject(NULL);
        }
        
		for(ObjList::iterator i = m_oReserved.begin(); i != m_oReserved.end(); ++i) 
		{
            if((*i).GetObj() == pObj) {
                (*i).SetObject(NULL);
                i = m_oReserved.erase(i);
                return;
            }
        }
    }
	 
private:
    //CreateObject
    T *CreateObject()
    {
        ObjHolder oHolder;
		oHolder.InitObject();
		T *pObj = oHolder.GetObj(); 
        if(pObj && pObj->IsUsable()) {
			oHolder.SetTimeStamp((long)time(NULL));
            m_oReserved.push_back(oHolder);
            oHolder.SetObject(NULL);
            return pObj;
        }else {
            cerr << "Could not create Object"<< endl;
            return NULL;
        }
    }
    //ProcessExpiredObject : It will move expired objects to free object pool
    void ProcessExpiredObjects()
    {
        std::cout << "Finding expired Object."<< std::endl;
        for(ObjList::iterator it = m_oReserved.begin();
            it != m_oReserved.end(); ++it) {
            ObjHolder &oHolder = *it;
            if((long)time(NULL) - oHolder.GetTimeStamp() >
                m_nExpirationTime) {
                T *pObj = oHolder.GetObj();
                if(ValidateObject(pObj) == true) {
                    m_oFree.push_back(oHolder); 
                    oHolder.SetObject(NULL);
                    std::cout << "Found expired Object. " << std::endl;
                }
                it = m_oReserved.erase(it);
            }
        }
    }
        
    // validate object if it is still usable
	// if not, try to make it usable
    bool ValidateObject(T *pObj)
    {
        bool bUseObj = false;
        if(pObj && pObj->IsUsable()) {
            bUseObj = true;
        }else if(pObj && pObj->MakeUsable()) {
            bUseObj = true;
        }
        return bUseObj;
    }

    // find the object from free resources
    T* FindObject()
    {
        // find existing free Object
        while(!m_oFree.empty()) 
		{
			
            ObjHolder &oObjMgr = m_oFree.front();
            T* pObj = oObjMgr.GetObj();
            bool bReturn = false;
        
			if(pObj && pObj->IsUsable()) 
			{
                bReturn = true;
            }
			else if (pObj && pObj->MakeUsable()) 
			{
                bReturn = true;
            }
            
			if(bReturn) 
			{
                oObjMgr.Set(pObj, (long)time(NULL));
                m_oReserved.push_back(oObjMgr);
                oObjMgr.SetObject(NULL);
                m_oFree.pop_front(); 
            
				return pObj;
            }
			else 
			{
                // delete the Object
                m_oFree.pop_front();
            }
        }

		return NULL;    
    }

    
	//private constructor
	PoolMgr()
    {
        m_nPoolSize = 0;
        m_nExpirationTime = 600;
        m_bTempObjAllowed = true;
        m_nWaitTime = 3;
    }   
	// user can not delete pool object   
    ~PoolMgr()
    {
    }
    unsigned m_nPoolSize;  // pool size : default 0
    unsigned m_nWaitTime; // wait time: How long calling function can wait to find object
    long m_nExpirationTime;  // Object expiration time: default 600
    bool m_bTempObjAllowed;  // if pool is full, is tempobject allowed
    ObjList m_oReserved; // reserved objects
    ObjList m_oFree;  // free objects
    static PoolMgr<T> *m_pPoolMgr; // static instance of PoolMgr  
           
};
//initialize static instance
template<class T> PoolMgr<T>* PoolMgr<T>::m_pPoolMgr = NULL; 
template<class T> Mutex PoolMgr<T>::m_mPool;
#endif //POOL_MGR_H
