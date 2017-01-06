#include "WaveletTree.h"

using namespace std;


WaveletTree::WaveletTree(string S) : IWaveletTree(S)
{

}

WaveletTree::WaveletTree(string S, string alphabet) : IWaveletTree(S, alphabet)
{
	
}

WaveletTree::~WaveletTree()
{
}

void WaveletTree::BuildTree() 
{
	this->m_pRoot = ConstructNode(this->m_S, 0, this->m_alphabet.size() - 1);
	SumCharacterRanks();
}

int WaveletTree::BinaryRank(Node *node, unsigned char CharBit, int index) 
{
	int NewIndex = -1;
	int ArrayIndex = 0;
	vector<unsigned char> Bits;
	Bits.resize(node->m_Bits.size());
	copy(node->m_Bits.begin(), node->m_Bits.end(), Bits.begin());

	for (int i = 0; i <= index; i++)
	{
		unsigned char bit = 1 << 7;

		bit = bit & Bits[ArrayIndex];

		bit = bit >> 7;

		if (CharBit == bit)
		{
			NewIndex++;
		}

		Bits[ArrayIndex] = Bits[ArrayIndex] << 1;

		if ((i + 1) % 8 == 0)
		{
			ArrayIndex++;
		}
	}


	//NewIndex--; //uzimamo index a ne broj elemenata
	return NewIndex;
}

int WaveletTree::CalculateRank(char c, int index)
{
	auto it = cache.find(make_pair(c, index));
	if (it != cache.end())
		return it->second;
	auto r = Rank(this->m_pRoot, c, index, 0, m_alphabet.size() - 1);

	cache.insert(make_pair(make_pair(c, index), r));

	return r;
}

int WaveletTree::Rank(Node *node, char c, int index, int begin, int end)
{
	int rank;

	int middle = floor((begin + 1 + end + 1) / 2.f) - 1;

	if (node->IsLeaf)
	{
		return index + 1;
	}

	unsigned char CharBit = node->GetRepresentingBit(c, this->m_alphabet, begin, end);

	int NewIndex = BinaryRank(node, CharBit, index);

	if (CharBit)
	{
		rank = Rank(node->m_pRightChild, c, NewIndex, middle + 1, end);
	}
	else
	{
		rank = Rank(node->m_pLeftChild, c, NewIndex, begin, middle);
	}

	return rank;
}

Node *WaveletTree::ConstructNode(string S, int begin, int end) 
{
	Node *node = new Node();

	if (begin == end && HasTheSameCahr(S))
	{
		node->IsLeaf = true;
		
		if (S.size() != 0)
		{
			node->m_Bits.push_back(S[0]);
		}

		return node;
	}

	node->BuildNode(S, this->m_alphabet, begin, end);

	int middle = floor((begin + 1 + end + 1) / 2.f) - 1;

	string LeftS = node->CalculateNewString(S, this->m_alphabet, begin, middle);
	string RightS = node->CalculateNewString(S, this->m_alphabet, middle + 1, end);

	node->m_pLeftChild = ConstructNode(LeftS, begin, middle);
	node->m_pRightChild = ConstructNode(RightS, middle + 1, end);

	return node;
}

bool WaveletTree::HasTheSameCahr(string S)
{
	if (S.size() == 0)
	{
		return true;
	}
	
	for (auto c : S)
	{
		if (c != S[0])
		{
			return false;
		}
	}

	return true;
}



//int WaveletTree::rank_sum(char &c) {
//	int sum = 0;
//
//	vector<char>::iterator it;
//	it = find(m_alphabet.begin(), m_alphabet.end(), c);
//	int pos = distance(m_alphabet.begin(), it);
//
//	for (int i = 0; i < pos; i++) {
//		//size_t n = count(m_S.begin(), m_S.end(), m_alphabet[i]);//private to public!
//		size_t n = CalculateRank(m_alphabet[i], m_S.size() - 1);
//		sum += n;
//	}
//
//	return sum;
//}

