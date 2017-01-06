#ifndef _SDSLWAVELETTREE_H_
#define _SDSLWAVELETTREE_H_
#include"IWaveletTree.h"

#include <algorithm>
#include "CPPAppendix.h"
#include<unordered_map>
#include<utility>
#include <functional>

#include <sdsl/wavelet_trees.hpp>



class SDSLWaveletTree : public IWaveletTree
{
public:
	SDSLWaveletTree(std::string S);
	SDSLWaveletTree(std::string S, std::string alphabet);
	~SDSLWaveletTree();

	void BuildTree();
	int CalculateRank(char c, int index);
private:
        sdsl::wt_huff<> m_wt;
        std::unordered_map<std::pair<char, int>, int, pair_hash> cache;

};


#endif // !_SDSLWAVELETTREE_H_
