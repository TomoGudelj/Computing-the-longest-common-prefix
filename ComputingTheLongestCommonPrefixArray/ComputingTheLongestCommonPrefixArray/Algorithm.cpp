#include "Algorithm.h"


using namespace std;

Algorithm::Algorithm(int n)
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
Algorithm::~Algorithm()
{

}

void Algorithm::calculateLCP(IWaveletTree &tree)
{
	QElement q_el;
	while (Q.size() > 0)
	{
		q_el = Q.front();
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
string Algorithm::uniqueChars(Interval interval, IWaveletTree &tree)
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

vector<Interval> Algorithm::getIntervals(Interval interval, IWaveletTree &tree)
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
		int b = tree.CalculateRank(c, interval.j);
		int C = tree.m_C[IndexOf(tree.m_alphabet, c)];//popravljeno
		Interval new_interval;

		//cout << c << " " << interval.i - 1 << endl;
		//cout << c << " " << interval.j << endl;

		new_interval.i = a + C + 1;
		new_interval.j = C + b;

		//indexes from 0
		new_interval.i -= 1;
		new_interval.j -= 1;

		list.push_back(new_interval);
	}

	return list;
	
}

void Algorithm:: writeLCP(const string &filename){

		fstream file;
		file.open(filename,ios::out);
		if (file.is_open() ){

			for (const int &el: LCP){
				file << el << " ";		
			}
			//file << endl;
			file.close();		
		}

		
		
}
	


void Algorithm::printLCP() {
	cout << "LCP:" << endl;
	for (int &el : LCP)
		cout << el << " ";
}
