#ifndef STATISTICS_MEAN_H
#define STATISTICS_MEAN_H

#include"Statistics.h"

class StatisticsMean : public Statistics
{
public:

	StatisticsMean();
	virtual void DumpOneResult(double result);
	virtual std::vector<std::vector<double>> GetResultsSoFar() const;
	virtual StatisticsMean* clone() const;

private:
	double _RunningSum;
	double _SquaredRunningSum;
};

#endif