#ifndef _WAVELETCLASS_H_
#define _WAVELETCLASS_H_

#include "Node.h"
#include <algorithm>
#include "CPPAppendix.h"

class WaveletTree
{
public:
	Node *m_pRoot;
	std::vector<char> m_alphabet;
	
	WaveletTree(std::string S);
	WaveletTree(std::string S, std::string alphabet);
	~WaveletTree();

	void BuildTree();
	int CalculateRank(char c, int index);
	std::string getm_S();
	std::vector<int> m_C;

private:
	std::string m_S;

	void CalculateAlphabet();
	bool AlreadyInAlphabet(char c);
	Node *ConstructNode(std::string S, int begin, int end);
	bool HasTheSameCahr(std::string S);
	int Rank(Node *node, char c, int index, int begin, int end);
	int BinaryRank(Node *node, unsigned char CharBit, int index);
	int rank_sum(char &c);
	void SumCharacterRanks();
};



#endif