#ifndef STATISTICS_H
#define STATISTICS_H

#include <vector>

class Statistics
{
public:

	Statistics();

    virtual void DumpOneResult(double result);
    virtual std::vector<std::vector<double>> GetResultsSoFar() const;
    virtual Statistics* clone() const;
    virtual ~Statistics(){}

protected:
	unsigned long _IndexDone;

private:
	double _CurrentResult;
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

