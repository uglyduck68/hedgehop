#ifndef GENERIC_OBJECT_H
#define GENERIC_OBJECT_H

/***********************************************************************
 * GenericObject.h
 * Rohit Joshi
 * 08-25/2004
 * This is sample Genric object class. User who implemented his object
 * class must have following methods defined or inherit from this class
 * Init() :      Initliaze the Object
 * Release():    Release the resources 
 * IsUsable():   Check if object is usable
 * MakeUsable(): Make the object usable. 
 ***********************************************************************/
class GenericObject
{
    public:
	    //constructor
	    GenericObject() {}
	    //destrctor
	    ~GenericObject() {}
		//Initliaze object
        virtual void Init() {}
		//Release the resource related to object
        virtual void Release() {}
        // Check if object is still usable
        virtual bool IsUsable()
        {
            return true;
        }
		// If object is not usable, make it usable
        virtual bool MakeUsable()
        {
            if(!IsUsable()) {
                Init();
            }
            return true;
        }
};
#endif // GENERIC_OBJECT_H
