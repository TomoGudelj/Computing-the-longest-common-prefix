#include "Algorithm_1.h"


using namespace std;

Algorithm_1::Algorithm_1(int n)
{
	// init LCP
	LCP.push_back(-1);
	for (int i = 1; i <= n-1; i++) 
		LCP.push_back(INVALID);
	LCP.push_back(-1);
	
	//init Q
	QElement first_struct;
	first_struct.l = 0;
	first_struct.interval.i = 0;
	first_struct.interval.j = n - 1;

	Q.push(first_struct);

}
Algorithm_1::~Algorithm_1()
{

}

void Algorithm_1::calculateLCP(WaveletTree tree)
{
	
	while (Q.size() > 0)
	{
		const QElement& q_el = Q.front();
		Q.pop();
		vector<Interval> list = getIntervals(q_el.interval, tree);
		
		for (const Interval& cw_interval : list) {
			int index = cw_interval.j + 1; //check indexing
			int lcp_value = LCP[index]; 

			if (lcp_value == INVALID) {
				QElement new_q_el;
				new_q_el.interval.i = cw_interval.i;
				new_q_el.interval.j = cw_interval.j;
				new_q_el.l = q_el.l + 1;
				Q.push(new_q_el);

				LCP[index] = q_el.l;

			}

		}
		
	}
	
}
string Algorithm_1::uniqueChars(Interval interval, WaveletTree &tree)
{
	string uniqueChars;
	int n = tree.m_alphabet.size();
	for (int k = 0; k < n; k++) {
		if (tree.CalculateRank(tree.m_alphabet[k], interval.j) -
			tree.CalculateRank(tree.m_alphabet[k], interval.i - 1) > 0) {

			uniqueChars += tree.m_alphabet[k];
		}
	}
	return uniqueChars;
}

vector<Interval> Algorithm_1::getIntervals(Interval interval, WaveletTree &tree)
{

	vector<Interval> list;
	string unique;
	Interval main_interval;

	unique = uniqueChars(interval, tree);
	int n = unique.size();

	for (int i = 0; i < n; i++) 
	{
		char c = unique[i];
		int a = tree.CalculateRank(c, interval.i - 1);
		int b = tree.CalculateRank(c, interval.j );
		int C = rank_sum(c, tree);
		Interval new_interval;

		new_interval.i = a + C + 1;
		new_interval.j = C + b;

		//indexes from 0
		new_interval.i -= 1;
		new_interval.j -= 1;

		list.push_back(new_interval);
	}

	return list;
	
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

void Algorithm_1::printLCP() {
	cout << "LCP:" << endl;
	for (int &el : LCP)
		cout << el << " ";
}