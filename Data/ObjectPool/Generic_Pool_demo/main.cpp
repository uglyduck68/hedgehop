#include <iostream>
#include "PoolMgr.h"
#include "GenericObject.h"

using namespace std;

// poll test
int main()
{
	// get the pool instance
    PoolMgr<GenericObject> *pMgr = PoolMgr<GenericObject>::GetInstance();
	// initialize the pool
    pMgr->Init(10,600, false);
	// checkout the object
	GenericObject *pObj = pMgr->Checkout();
	if(pObj)
        pMgr->Checkin(pObj); // checkin the object
	// reset the pool
    pMgr->ResetPool();
	// delete the pool
	PoolMgr<GenericObject>::DeletePool();

    
	cout << "Enter any key to exit :";
    cin.get();
}
