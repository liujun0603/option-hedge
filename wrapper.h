//
//
//                              wrapper.h
//
//
//wrapper: used as a container for a polymorphic object that provides a clone method
// (the base class maybe abstract and/or more importantly,
// the size of the polymorphic type is unknown, functions like PayOffBridge)
// also handle memory allocation (like bridge)
//; act like a pointer to a single object and owns the
// object at all times (if we copy the wrapper, also the object, like bridge)

#ifndef WRAPPER_H
#define WRAPPER_H

template<class T>
class wrapper
{
public:

    //this default constructor must be provided, otherwise
	// std::vector<Wrapper<MCStatistics>> StatisticsGatherers(10) would not compile
	// because the constructor for vector would look for
	// the default constructor for Wrapper<MCStatistics>
	wrapper()
    {
		_DataPtr =0;
	}

	//put the copy constructor, destructor, and assignement operator here
	// , we do not need to repeat these properties
	// when coding another class working with a wrapper object

	//rule of three : if any one of destructor, assignment operator
	// and copy constructor is needed, then all three are
    wrapper(const T& inner)
    {
		_DataPtr = inner.clone();
    }

    wrapper(const wrapper<T>& original)
    {
		//a _DataPtr points to nothing cannot be cloned
		_DataPtr = (original._DataPtr != 0) ? original._DataPtr->clone() : 0;
    }

	wrapper& operator=(const wrapper<T>& original)
    {
        if (this != &original)
        {
			//a _DataPtr points to nothing cannot be deleted
			if (_DataPtr!=0)
                delete _DataPtr;
            _DataPtr = (original._DataPtr !=0) ? original._DataPtr->clone() : 0;
        }
        return *this;
    }

	//when the wrapper ceases to exist, the object being pointed needs to be deleted
	~wrapper()
	{
		if (_DataPtr != 0)
			delete _DataPtr;
	}

    //dereference the wrapper to obtain the underlying object
	//dereference both const the non-const objects
	// non-const member function cannot be applied to const object
	//inline: ensure that there is no performance overhead
	// induced by going via a wrapper
	T& operator*()
    {
        return *_DataPtr; 
    }

    const T& operator*() const
    {
        return *_DataPtr; 
    }

    //special rules for overloading -> ensure that any method
	// following -> is correctly invoked for the pointer returned
	const T* const operator->() const
    {
        return _DataPtr;
    }

    T* operator->()
    {
        return _DataPtr;
    }

private:
    T* _DataPtr;
};
#endif

/*
 *
 * Copyright (c) 2002
 * Mark Joshi
 *
 * Permission to use, copy, modify, distribute and sell this
 * software for any purpose is hereby
 * granted without fee, provided that the above copyright notice
 * appear in all copies and that both that copyright notice and
 * this permission notice appear in supporting documentation.
 * Mark Joshi makes no representations about the
 * suitability of this software for any purpose. It is provided
 * "as is" without express or implied warranty.
*/

