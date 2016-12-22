#include "Algorithm_1.h"


using namespace std;

Algorithm_1::Algorithm_1()
{
	
}
Algorithm_1::~Algorithm_1()
{

}

string Algorithm_1::uniqueChars(pair<int, int> interval, WaveletTree &tree)
{
	string uniqueChars;
	int n = tree.m_alphabet.size();
	for (int k = 0; k < n; k++) {
		if (tree.CalculateRank(tree.m_alphabet[k], interval.second) -
			tree.CalculateRank(tree.m_alphabet[k], interval.first - 1) > 0) {

			uniqueChars += tree.m_alphabet[k];
		}
	}
	return uniqueChars;
}

vector<pair<int, int> > Algorithm_1::getIntervals(pair<int,int> interval, WaveletTree &tree)
{

	vector<pair<int, int>> list;
	string unique;
	pair<int, int> main_interval;

	unique = uniqueChars(interval, tree);
	int n = unique.size();

	for (int i = 0; i < n; i++) 
	{
		char c = unique[i];
		int a = tree.CalculateRank(c, interval.first - 1);
		int b = tree.CalculateRank(c, interval.second);
		int C = rank_sum(c, tree);
		list.push_back(make_pair( a + C + 1, C + b));
	}

	//getIntervals2(interval, main_interval, list, tree );
	
	return list;
	
}


void Algorithm_1::getIntervals2(pair<int, int> interval, pair<int, int> main_interval, vector<pair<int, int>> & list, WaveletTree &tree)
{
	int i,j, l, r;
	char c;
	//l = main_interval.first;
	i = interval.first;
	j = interval.second;
	l = main_interval.first;
	r = main_interval.second;

	if (l == r) 
	{
		c = tree.m_alphabet[l];		
		int char_rank = rank_sum(c, tree);
		list.push_back(make_pair(char_rank + i, char_rank + j));
	}
	else
	{

	}

}

int Algorithm_1::rank_sum(char &c, WaveletTree tree) {
	int sum = 0;
	string str = tree.getm_S();

	vector<char>::iterator it;
	it = find(tree.m_alphabet.begin(), tree.m_alphabet.end(), c);
	int pos = distance(tree.m_alphabet.begin(), it);

	for (int i = 0; i < pos; i++) {		
		size_t n = count(str.begin(), str.end(),tree.m_alphabet[i]);//private to public!
		sum += n;
	}

	return sum;
}