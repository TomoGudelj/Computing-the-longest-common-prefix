#include <iostream>

#include <chrono>
#include <ctime>
#include <ratio>

#include "WaveletTree.h"
#include "divsufsort.h"
#include "BWT.h"
#include "Algorithm.h"

using namespace std;

int main(int argc, char *argv[]) {

	////////////////////////////// Suffix array ///////////////////////////
	string S;
	cin >> S;

	const char *str = S.c_str();

	int S_length = S.size();

	int *SA = (int *)malloc(S_length * sizeof(int));

	divsufsort((unsigned char *)str, SA, S_length, 1);
	////////////////////////////// End Suffix array ///////////////////////////

	////////////////////////////// Wavelet tree ///////////////////////////
	BWT bwt;

	// create waveletTree
	bwt.CalculateBWT(S, SA);

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
	WaveletTree tree(bwt.BWT_string);
	tree.BuildTree();
	////////////////////////////// End Wavelet tree ///////////////////////////

	////////////////////////////// Algorithm ///////////////////////////
	Algorithm alg1(S_length);
	alg1.calculateLCP(tree);
	chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();

	chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
	std::cout << "It took me " << time_span.count() << " seconds." << endl;

	alg1.printLCP();
	///////////////////////// end Algorithm ///////////////////////////

	return 0;
}


