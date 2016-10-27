#include "Node.h"

using namespace std;

Node::Node()
{
}

Node::~Node()
{
}

bool Node::IsInFirstHalf(vector<char> alphabet, int begin, int middle, int end, char c) 
{
	for (int i = begin; i <= end; i++)
	{
		if (c == alphabet[i] && i <= middle)
		{
			return true;
		}
		else if (c == alphabet[i] && i > middle)
		{
			return false;
		}
	}

	return false;
}

void Node::BuildNode(string S, vector<char> alphabet, int begin, int end)
{
	this->m_nSize = S.size();

	int middle = floor((begin + 1 + end + 1) / 2.f) - 1;

	char shiftBy = 7;
	char byte = 0;

	int counter = 0;
	for (auto c : S) 
	{
		char bit;

		if (IsInFirstHalf(alphabet, begin, middle, end, c))
		{
			bit = 0;
		}
		else
		{
			bit = 1;
		}

		byte = byte | (bit << shiftBy);

		shiftBy--;
		counter++;

		if (shiftBy < 0)
		{
			shiftBy = 7;
			
			this->m_Bits.push_back(byte);

			byte = 0;
		}
		else if (counter == S.size()) {
			this->m_Bits.push_back(byte); //push rest of bits
		}
	}
	
}