#include "Node.h"

using namespace std;

Node::Node()
{
	this->IsLeaf = false;
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

string Node::CalculateNewString(string S, std::vector<char> alphabet, int begin, int end)
{
	string NewS = "";

	for (auto c : S)
	{
		if (IsInFirstHalf(alphabet, begin, end, end, c))
		{
			NewS += c;
		}
	}

	return NewS;
}

unsigned char Node::GetRepresentingBit(char c, std::vector<char> alphabet, int begin, int end)
{
	int middle = floor((begin + 1 + end + 1) / 2.f) - 1;
	unsigned char CharBit = 0;

	for (int i = 0; i < alphabet.size(); i++)
	{
		if (alphabet[i] == c)
		{
			if (i <= middle)
			{
				CharBit = 0;
				break;
			}
			else
			{
				CharBit = 1;
				break;
			}
		}
	}

	return CharBit;
}

void Node::BuildNode(string S, vector<char> alphabet, int begin, int end)
{
	if (begin == end)
	{
		return;
	}

	this->m_nSize = S.size();

	int middle = floor((begin + 1 + end + 1) / 2.f) - 1;

	char shiftBy = 7;
	unsigned char byte = 0;

	int counter = 0;
	for (auto &c : S) 
	{
		unsigned char bit;

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