#ifndef _ALGORITHM_1_
#define _ALGORITHM_1_

#include "WaveletTree.h"
#include<iostream>
#include<vector>


class Algorithm_1
{
public:

	Algorithm_1();
	~Algorithm_1();

	std::vector<std::pair<int, int>> getIntervals(std::pair<int, int> interval, WaveletTree &tree);
	void getIntervals2(std::pair<int, int> interval, std::pair<int, int> main_interval, std::vector<std::pair<int, int>> & list, WaveletTree &tree);
	int rank_sum(char &c, WaveletTree tree);
	std::string uniqueChars(std::pair<int, int> interval, WaveletTree &tree);
};

#endif _ALGORITHM_1_
