#ifndef _IWAVELETTREE_H_
#define _IWAVELETTREE_H_

#include<vector>
#include"CPPAppendix.h"

class IWaveletTree
{
public:
	IWaveletTree();
	~IWaveletTree();

	virtual int CalculateRank(char c, int index) = 0;
	int rank_sum(char &c);
	void SumCharacterRanks();

	std::vector<int> m_C;
	std::vector<char> m_alphabet;
protected:
	std::string m_S;

};


#endif
