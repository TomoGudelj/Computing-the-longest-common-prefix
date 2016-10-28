#ifndef _WAVELETCLASS_H_
#define _WAVELETCLASS_H_

#include "Node.h"
#include <algorithm>

class WaveletTree
{
public:
	Node *m_pRoot;
	
	WaveletTree(std::string S);
	~WaveletTree();

	void BuildTree();

private:
	std::vector<char> m_alphabet;
	std::string m_S;

	void CalculateAlphabet();
	bool AlreadyInAlphabet(char c);
	Node *ConstructNode(std::string S, int begin, int end);
	bool HasTheSameCahr(std::string S);
};



#endif