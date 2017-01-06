#ifndef _IWAVELETTREE_H_
#define _IWAVELETTREE_H_

#include<vector>
#include<string>
#include"CPPAppendix.h"
#include<algorithm>

class IWaveletTree
{
public:
	IWaveletTree(std::string S);
	IWaveletTree(std::string S, std::string alphabet);
	~IWaveletTree();
	
	virtual void BuildTree() = 0;
	virtual int CalculateRank(char c, int index) = 0;
	int rank_sum(char &c);
	void SumCharacterRanks();

	std::vector<int> m_C;
	std::vector<char> m_alphabet;
protected:
	std::string m_S;

	void CalculateAlphabet();
	bool AlreadyInAlphabet(char c);
};


#endif
