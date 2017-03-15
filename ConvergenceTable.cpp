
#include"ConvergenceTable.h"
#include<iostream>

ConvergenceTable::ConvergenceTable(const wrapper<Statistics>& Inner,unsigned long Interval)
: _Inner(Inner)
{
    _Interval=Interval;
	_StoppingInterval = Interval;
    _IndexDone=0;
}

ConvergenceTable* ConvergenceTable::clone() const
{
    return new ConvergenceTable(*this);
}

void ConvergenceTable::DumpOneResult(double result)
{
    _Inner->DumpOneResult(result);
    ++_IndexDone;
    
    if (_IndexDone == _StoppingInterval)
    {
        _StoppingInterval+=_Interval;
        std::vector<std::vector<double>> thisResult(_Inner->GetResultsSoFar());

        for (unsigned long i=0; i < thisResult.size(); i++)
        {
            thisResult[i].push_back(_IndexDone);
            _ResultsSoFar.push_back(thisResult[i]);
        }
    }
    return;
}

std::vector<std::vector<double>> ConvergenceTable::GetResultsSoFar() const
{
    std::vector<std::vector<double>> tmp(_ResultsSoFar);

    //get from inner one more result, which has not been stored in ConvergenceTable::_ResultSoFar
	/*if (_IndexDone!= _StoppingInterval)
    {
        std::vector<std::vector<double>> thisResult(_Inner->GetResultsSoFar());

        for (unsigned long i=0; i < thisResult.size(); i++)
        {
            thisResult[i].push_back(_IndexDone);
            tmp.push_back(thisResult[i]);
        }
    }*/
    return tmp;
}

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


