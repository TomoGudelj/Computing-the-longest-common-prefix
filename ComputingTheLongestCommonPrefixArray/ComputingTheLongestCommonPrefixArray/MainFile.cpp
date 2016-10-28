#include <iostream>
#include "WaveletTree.h"

using namespace std;

int main(int argc, char *argv[]) {
	

	/*Node n;
	
	n.BuildNode("arrd$rcbbraaaaaabba", {'$', 'a', 'b', 'c', 'd', 'r' }, 0, 5);*/
	string S = "arrd$rcbbraaaaaabba";
	cin >> S;

	WaveletTree tree("arrd$rcbbraaaaaabba");

	tree.BuildTree();

	int rank = tree.CalculateRank('a', 18);

	return 0;
}