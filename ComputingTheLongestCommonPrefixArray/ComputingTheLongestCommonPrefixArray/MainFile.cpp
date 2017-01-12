#include <iostream>
#include <fstream>

#include <chrono>
#include <ctime>
#include <ratio>

//#define USE_MEMORY_METER
#ifdef USE_MEMORY_ANALYZER
#include <sys/resource.h>
#endif
#include "WaveletTree.h"
#include "divsufsort.h"
#include "BWT.h"
#include "Algorithm.h"
#include "SDSLWaveletTree.h"

using namespace std;

int main(int argc, char *argv[]) {

    if(argc != 2)
    {
        cout << "Missing parameters (expected 2)" << endl;
        return 1;
    }

	////////////////////////////// Suffix array ///////////////////////////
	string S;
	cin >> S;

	const char *str = S.c_str();

	int S_length = S.size();
	Algorithm alg1(S_length);

	int *SA = (int *)malloc(S_length * sizeof(int));

	divsufsort((unsigned char *)str, SA, S_length, 1);
	////////////////////////////// End Suffix array ///////////////////////////

	////////////////////////////// Wavelet tree ///////////////////////////
	BWT bwt;

	// create waveletTree
	bwt.CalculateBWT(S, SA);


	fstream file;
	string alphabet;

	file.open("alphabet.txt");

	if (!file.is_open())
	{
		cout << "Missing alphabet.txt" << endl;
		return 1;
	}

	file >> alphabet;
	sort(alphabet.begin(), alphabet.end());

        IWaveletTree *tree;//(bwt.BWT_string, alphabet);
        if(string("studentWT") == argv[1]) //student implementation
        {
            tree = new WaveletTree(bwt.BWT_string, alphabet);
            cout << "student" << endl;
        }
        else //SDSL alhorithm
        {
            tree = new SDSLWaveletTree(bwt.BWT_string, alphabet);
            cout << "sdsl" << endl;
        }

        chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();

        tree->BuildTree();

	////////////////////////////// End Wavelet tree ///////////////////////////

	////////////////////////////// Algorithm ///////////////////////////



	alg1.calculateLCP(*tree);

	chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
	chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
	std::cout << "It took me " << time_span.count() << " seconds." << endl;

	///////////////////////// end Algorithm ///////////////////////////


 /*
	 *  Measure memory usage of current process...
	 *  Measuring RSS... Resident Set Size
	 *  the portion of memory occupied by a process
	 *  that is held in main memory (RAM)
	 *
	 *  @param usage    Structure that is holding data of the memory usage
	 */

#ifdef USE_MEMORY_ANALYZER

	struct rusage usage;
	getrusage(RUSAGE_SELF, &usage);
	cout << "Memory usage: " << usage.ru_maxrss / ((float)1024) << " MB of RAM" << endl;

#endif
	//	alg1.printLCP();

	cout << "LCP array is in output.txt" << endl;
	alg1.writeLCP("output.txt");

	return 0;
}


