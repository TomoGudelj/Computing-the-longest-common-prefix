#ifndef _NODECLASS_H_
#define _NODECLASS_H_

#include <string>
#include <vector>
#include <math.h>

class Node
{
public:
	std::vector<char> m_Bits;
	int m_nSize;
	Node *m_pLeftChild;
	Node *m_pRightChild;

	Node();
	~Node();

	void BuildNode(std::string S, std::vector<char> alphabet, int begin, int end);
	
private:
	bool IsInFirstHalf(std::vector<char> alphabet, int begin, int middle, int end, char c);
};

#endif
