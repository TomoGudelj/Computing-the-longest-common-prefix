#ifndef _WAVELETCLASS_H_
#define _WAVELETCLASS_H_

#include "Node.h"
#include <algorithm>
#include "CPPAppendix.h"
#include "IWaveletTree.h"
#include<unordered_map>
#include<utility> 
#include <functional>


class WaveletTree : public IWaveletTree
{
public:
	Node *m_pRoot;
	
	WaveletTree(std::string S);
	WaveletTree(std::string S, std::string alphabet);
	~WaveletTree();

	void BuildTree();
	int CalculateRank(char c, int index);
private:
	std::unordered_map<std::pair<char, int>, int, pair_hash> cache;

	
	Node *ConstructNode(std::string S, int begin, int end);
	bool HasTheSameCahr(std::string S);
	int Rank(Node *node, char c, int index, int begin, int end);
	int BinaryRank(Node *node, unsigned char CharBit, int index);
	
};



#endif