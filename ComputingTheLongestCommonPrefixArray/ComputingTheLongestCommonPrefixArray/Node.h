#ifndef _NODECLASS_H_
#define _NODECLASS_H_

#include <string>
#include <vector>
#include <math.h>

class Node
{
public:
	std::vector<unsigned char> m_Bits;
	int m_nSize;
	Node *m_pLeftChild;
	Node *m_pRightChild;
	bool IsLeaf;

	Node();
	~Node();

	void BuildNode(std::string S, std::vector<char> alphabet, int begin, int end);
	std::string CalculateNewString(std::string S, std::vector<char> alphabet, int begin, int end);
	unsigned char GetRepresentingBit(char c, std::vector<char> alphabet, int begin, int end);

	
private:
	bool IsInFirstHalf(std::vector<char> alphabet, int begin, int middle, int end, char c);
};

#endif
