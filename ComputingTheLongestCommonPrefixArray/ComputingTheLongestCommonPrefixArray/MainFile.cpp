#include <iostream>
#include "WaveletTree.h"

using namespace std;

int main(int argc, char *argv[]) {
	

	/*Node n;

	n.BuildNode("arrd$rcbbraaaaaabba", {'$', 'a', 'b', 'c', 'd', 'r' }, 0, 5);*/

	WaveletTree tree("arrd$rcbbraaaaaabba");

	tree.BuildTree();

	return 0;
}