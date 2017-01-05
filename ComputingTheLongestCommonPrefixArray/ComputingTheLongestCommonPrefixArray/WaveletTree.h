#ifndef _WAVELETCLASS_H_
#define _WAVELETCLASS_H_

#include "Node.h"
#include <algorithm>
#include "CPPAppendix.h"
#include<unordered_map>
#include<utility> 
#include <functional>
struct pair_hash {
	template <class T1, class T2>
	std::size_t operator () (const std::pair<T1, T2> &p) const {
		auto h1 = std::hash<T1>{}(p.first);
		auto h2 = std::hash<T2>{}(p.second);

		// Mainly for demonstration purposes, i.e. works but is overly simple
		// In the real world, use sth. like boost.hash_combine
		return h1 ^ h2;
	}
};

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
	std::unordered_map<std::pair<char, int>, int, pair_hash> cache;

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