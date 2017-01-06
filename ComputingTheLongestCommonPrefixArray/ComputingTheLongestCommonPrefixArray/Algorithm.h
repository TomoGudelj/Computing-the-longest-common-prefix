#ifndef _ALGORITHM_H_
#define _ALGORITHM_H_

#include "WaveletTree.h"
#include "CPPAppendix.h"
#include<iostream>
#include<vector>
#include<queue>
#include<fstream>

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
	void calculateLCP(IWaveletTree &tree);
	void writeLCP(const std::string &filename);

private:
	std::vector<int> LCP;
	std::queue<QElement> Q;

	std::vector<Interval> getIntervals(Interval interval, IWaveletTree &tree);
	std::string uniqueChars(Interval interval, IWaveletTree &tree);
};

#endif //_ALGORITHM_1_
