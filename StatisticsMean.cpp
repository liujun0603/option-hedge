#include"StatisticsMean.h"
#include<iostream>

using namespace std;

StatisticsMean::StatisticsMean()
	:_RunningSum(0UL),_SquaredRunningSum(0UL)
{
}

void StatisticsMean::DumpOneResult(double result)
{
	_IndexDone++;
	_RunningSum += result;
	_SquaredRunningSum += (result*result);
}

vector<vector<double>> StatisticsMean::GetResultsSoFar() const
{
	vector<vector<double>> Results(1);
	Results[0].resize(2);
	
	double mean= _RunningSum / _IndexDone;
	double SD = sqrt((_SquaredRunningSum-2*mean*_RunningSum+_IndexDone*mean*mean)/_IndexDone);
	Results[0][0] = mean;
	Results[0][1] = SD;
	return Results;
}

StatisticsMean* StatisticsMean::clone() const
{
	return new StatisticsMean(*this);
}