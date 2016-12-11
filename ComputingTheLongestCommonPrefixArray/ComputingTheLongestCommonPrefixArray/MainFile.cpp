#include <iostream>
#include "WaveletTree.h"
#include "divsufsort.h"

using namespace std;

int main(int argc, char *argv[]) {
	

	/*Node n;
	
	n.BuildNode("arrd$rcbbraaaaaabba", {'$', 'a', 'b', 'c', 'd', 'r' }, 0, 5);*/
	//string S = "arrd$rcbbraaaaaabba";
	//cin >> S;

	string S;
	cin >> S;
	const char *str = S.c_str();

	int S_length = S.size();

	int *SA = (int *)malloc(S_length * sizeof(int));

	divsufsort((unsigned char *)str, SA, S_length, 1);

	for (int i = 0; i < S_length; ++i) {
		printf("SA[%2d] = %2d: ", i, SA[i]);
		for (int j = SA[i]; j < S_length; ++j) {
			printf("%c", str[j]);
		}
		printf("$\n");
	}

	WaveletTree tree("arrd$rcbbraaaaaabba");

	tree.BuildTree();

	int rank = tree.CalculateRank('a', 0);

	return 0;
}