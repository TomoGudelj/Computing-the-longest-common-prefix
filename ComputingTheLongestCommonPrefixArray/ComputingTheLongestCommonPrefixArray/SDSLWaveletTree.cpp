#include "SDSLWaveletTree.h"
using namespace sdsl;

using namespace std;

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
    construct_im(m_wt, m_S, 1);
    SumCharacterRanks();

}

int SDSLWaveletTree::CalculateRank(char c, int index)
{
    //cout << "CalculateRank: " <<  m_wt.size() << " " << c << endl;
    auto it = cache.find(make_pair(c, index));
    if (it != cache.end())
            return it->second;
    auto r =  m_wt.rank((long long)(index + 1), c);

    cache.insert(make_pair(make_pair(c, index), r));

    return r;
    //return  m_wt.rank((long long)(index + 1), c);
}
