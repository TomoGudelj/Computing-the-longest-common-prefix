#include "IWaveletTree.h"


IWaveletTree::IWaveletTree(std::string S)
{
	this->m_S = S;

	CalculateAlphabet();
}

IWaveletTree::IWaveletTree(std::string S, std::string alphabet)
{
	this->m_S = S;

	for (auto &x : alphabet)
	{
		m_alphabet.push_back(x);
	}
}

IWaveletTree::~IWaveletTree()
{
}

int IWaveletTree::rank_sum(char &c)
{
	int pos = IndexOf(m_alphabet, c);

	if (pos - 1 < 0)
	{
		return 0;
	}
	return m_C[pos - 1] + CalculateRank(m_alphabet[pos - 1], m_S.size() - 1);
}

void IWaveletTree::SumCharacterRanks()
{
	for (auto &c : m_alphabet)
	{
		m_C.push_back(rank_sum(c));
	}
}

void IWaveletTree::CalculateAlphabet()
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

bool IWaveletTree::AlreadyInAlphabet(char c)
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