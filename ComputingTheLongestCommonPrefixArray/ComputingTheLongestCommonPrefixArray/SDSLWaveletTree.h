#ifndef _SDSLWAVELETTREE_H_
#define _SDSLWAVELETTREE_H_

class SDSLWaveletTree
{
public:
	SDSLWaveletTree();
	~SDSLWaveletTree();

	void BuildTree();
	int CalculateRank(char c, int index);
private:

};


#endif // !_SDSLWAVELETTREE_H_
