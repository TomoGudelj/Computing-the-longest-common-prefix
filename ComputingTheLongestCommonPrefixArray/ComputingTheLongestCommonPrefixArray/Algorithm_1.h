#ifndef _ALGORITHM_1_
#define _ALGORITHM_1_

#include "WaveletTree.h"
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

class Algorithm_1
{
public:

	Algorithm_1(int n);
	~Algorithm_1();


	std::vector<Interval> getIntervals(Interval interval, WaveletTree &tree);
	int rank_sum(char &c, WaveletTree tree);
	std::string uniqueChars(Interval interval, WaveletTree &tree);
	void printLCP();
	void calculateLCP(WaveletTree tree);

private:
	std::vector<int> LCP;
	std::queue<QElement> Q;
};

#endif _ALGORITHM_1_
