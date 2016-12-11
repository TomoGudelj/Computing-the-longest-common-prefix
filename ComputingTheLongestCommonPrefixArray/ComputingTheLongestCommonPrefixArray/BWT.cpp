#include "BWT.h"

using namespace std;

BWT::BWT()
{
	BWT_string = "";
}
BWT::~BWT()
{

}

void BWT::CalculateBWT(std::string S, int *SA)
{
	int S_size = S.size();

	for (int i = 0; i < S_size; i++)
	{
		if (SA[i] != 0)
		{
			BWT_string += S[SA[i] - 1];
		}
		else
		{
			BWT_string += '$';
		}
	}
}