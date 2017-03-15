#ifndef CONVERGENCE_TABLE_H
#define CONVERGENCE_TABLE_H
#include "Statistics.h"
#include "wrapper.h"

class ConvergenceTable : public Statistics
{
public:

    //the complier will convert any StatisticsMC object 
	// to wapper<Statistics> and pass it to the constructor
	ConvergenceTable(const wrapper<Statistics>& Inner,unsigned long _Interval=1);

    virtual ConvergenceTable* clone() const;
    virtual void DumpOneResult(double result);
    virtual std::vector<std::vector<double>> GetResultsSoFar() const;
    
private:

    wrapper<Statistics> _Inner;
    std::vector<std::vector<double>> _ResultsSoFar;
	unsigned long _Interval;
	unsigned long _StoppingInterval;
    unsigned long _IndexDone;
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

