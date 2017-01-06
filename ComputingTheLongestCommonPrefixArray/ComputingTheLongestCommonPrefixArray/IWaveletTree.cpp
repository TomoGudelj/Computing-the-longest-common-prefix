#include "IWaveletTree.h"

IWaveletTree::IWaveletTree()
{
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