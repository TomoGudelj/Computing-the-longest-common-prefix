#ifndef _BWTCLASS_H_
#define _BWTCLASS_H_

#include <string>
#include <vector>

class BWT
{
public:

	std::string BWT_string;

	BWT();
	~BWT();

	void CalculateBWT(std::string S, int *SA);
private:
};


#endif
