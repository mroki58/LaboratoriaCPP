#include "Line.h"


LArraySmartPtr & LArraySmartPtr::operator=(LArraySmartPtr & smartptr)
{
    this->release();
    _refCount = smartptr._refCount;
    _ptr = smartptr._ptr;
    ++(*_refCount);
    return *this;
}

LArray & LArraySmartPtr::operator*()
{
    return *_ptr;
}

LArray * LArraySmartPtr::operator->()
{
    return _ptr;
}

LArraySmartPtr::~LArraySmartPtr()
{
    this->release();
}

void LArraySmartPtr::release()
{
    if(--(*_refCount)==0)
    {
        delete _refCount;
        delete _ptr;
    }
}


