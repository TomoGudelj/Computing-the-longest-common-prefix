#ifndef _SDSLWAVELETTREE_H_
#define _SDSLWAVELETTREE_H_
#include"IWaveletTree.h"

class SDSLWaveletTree : public IWaveletTree
{
public:
	SDSLWaveletTree(std::string S);
	SDSLWaveletTree(std::string S, std::string alphabet);
	~SDSLWaveletTree();

	void BuildTree();
	int CalculateRank(char c, int index);
private:

};


#endif // !_SDSLWAVELETTREE_H_
