#include "SDSLWaveletTree.h"
using namespace sdsl;

SDSLWaveletTree::SDSLWaveletTree(std::string S) : IWaveletTree(S)
{
   // m_wt = new wt_huff<>();
}

SDSLWaveletTree::SDSLWaveletTree(std::string S, std::string alphabet) : IWaveletTree(S, alphabet)
{
    //m_wt = new wt_huff<>();
}

SDSLWaveletTree::~SDSLWaveletTree()
{

}

void SDSLWaveletTree::BuildTree()
{
    SumCharacterRanks();

    construct_im(m_wt, m_S, 1);
}

int SDSLWaveletTree::CalculateRank(char c, int index)
{
    m_wt.rank(index, c);
}
