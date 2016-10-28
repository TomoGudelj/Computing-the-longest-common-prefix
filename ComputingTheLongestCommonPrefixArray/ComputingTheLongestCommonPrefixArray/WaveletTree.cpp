#include "WaveletTree.h"

using namespace std;

WaveletTree::WaveletTree(std::string S)
{
	this->m_S = S;
}

WaveletTree::~WaveletTree()
{
}

void WaveletTree::BuildTree() 
{
	CalculateAlphabet();

	this->m_pRoot = ConstructNode(this->m_S, 0, this->m_alphabet.size() - 1);
}

int WaveletTree::BinaryRank(Node *node, unsigned char CharBit, int index) 
{
	int NewIndex = 0;
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


	NewIndex--; //uzimamo index a ne broj elemenata
	return NewIndex;
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

void WaveletTree::CalculateAlphabet() 
{
	for (auto &c : m_S)
	{
		if (!AlreadyInAlphabet(c))
		{
			m_alphabet.push_back(c);
		}
	}

	sort(m_alphabet.begin(), m_alphabet.end());
}

bool WaveletTree::AlreadyInAlphabet(char c)
{
	for (auto &x : m_alphabet)
	{
		if (x == c)
		{
			return true;
		}
	}

	return false;
}
