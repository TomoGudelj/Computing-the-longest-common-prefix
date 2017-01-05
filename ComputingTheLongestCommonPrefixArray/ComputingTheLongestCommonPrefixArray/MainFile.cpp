#include <iostream>

#include <chrono>
#include <ctime>
#include <ratio>

#include "WaveletTree.h"
#include "divsufsort.h"
#include "BWT.h"
#include "Algorithm_1.h"

using namespace std;

int main(int argc, char *argv[]) {
	

	/*Node n;
	
	n.BuildNode("arrd$rcbbraaaaaabba", {'$', 'a', 'b', 'c', 'd', 'r' }, 0, 5);*/
	//string S = "arrd$rcbbraaaaaabba";
	//cin >> S;
	//string S = "annasanannas$";
	string S = "GTAAGTATTTTTCAGCTTTTCATTCTGACTGCAACGGGCAATATGTCTCTGTGTGGATTAAAAAAAGAGTGTCTGATAGCAGCTTCTGAACTGGTTACCT$";
	//cin >> S;

	const char *str = S.c_str();

	int S_length = S.size();

	int *SA = (int *)malloc(S_length * sizeof(int));

	divsufsort((unsigned char *)str, SA, S_length, 1);

	/*
	for (int i = 0; i < S_length; ++i) {
		printf("SA[%2d] = %2d: ", i, SA[i]);
		for (int j = SA[i]; j < S_length; ++j) {
			printf("%c", str[j]);
		}
		printf("$\n");
	}
	*/

	BWT bwt;
	// create waveletTree
	bwt.CalculateBWT(S, SA);

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
	WaveletTree tree(bwt.BWT_string);
	tree.BuildTree();

	
	////////////////////////////// Algorithm 1 ///////////////////////////
	Algorithm_1 alg1(S_length);
	alg1.calculateLCP(tree);
	chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();

	chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
	std::cout << "It took me " << time_span.count() << " seconds." << endl;

	alg1.printLCP();
	///////////////////////// end Algorithm 1 ///////////////////////////

	getchar();

	return 0;
}


