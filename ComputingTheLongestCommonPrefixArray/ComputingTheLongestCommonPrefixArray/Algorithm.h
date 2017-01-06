#ifndef _ALGORITHM_H_
#define _ALGORITHM_H_

#include "WaveletTree.h"
#include "CPPAppendix.h"
#include<iostream>
#include<vector>
#include<queue>

#define INVALID -2

struct Interval {
	int i, j;
};

struct QElement {
	Interval interval;
	int l;
};

class Algorithm
{
public:

	Algorithm(int n);
	~Algorithm();

	void printLCP();
	void calculateLCP(WaveletTree tree);

private:
	std::vector<int> LCP;
	std::queue<QElement> Q;

	std::vector<Interval> getIntervals(Interval interval, WaveletTree &tree);
	std::string uniqueChars(Interval interval, WaveletTree &tree);
};

#endif //_ALGORITHM_1_
