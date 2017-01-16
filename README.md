# Computing the longest common prefix

Implementation of algorithm for computing the longest common prefix based on the Burrows-Wheeler transform.
This project is part of university subject bioinformatics.


http://www.fer.unizg.hr/predmet/bio/

#Installation

1) Install the [SDSL][SDSL] library. 
This library contains implementation of rank function used for testing original algorithm.

   ```sh
  git clone https://github.com/simongog/sdsl-lite.git
  cd sdsl-lite
  ./install.sh
  ```

2) Install this project.

   ```sh
  git clone https://github.com/TomoGudelj/Computing-the-longest-common-prefix
  ```


3) Compile this project with following instruction:

   ```sh
  cd ./Computing-The-Longest-Common-Prefix/ComputingTheLongestCommonPrefixArray/ComputingTheLongestCommonPrefixArray/
  g++ -std=c++11 -O3 -DNDEBUG *.cpp -o application -lsdsl -I ~/include -L ~/lib
  ```
4) To run the program, "alphabet.txt" file must be in the same directory as executable and it must contain alphabet used in input (including '$' character). 
Program reads from standard input, however, user can redirect desired file to input stream. Input must contain '$' character at the end.

To execute program, user can choose 2 options:

a) Run the student implementation of rank function:

   ```sh
  ./application <input_file.txt studentWT
  ```
b) Run the [SDSL][SDSL] implementation of rank function:

   ```sh
  ./application <input_file.txt sdslWT
  ```

[SDSL]: https://github.com/simongog/sdsl-lite/ "Succinct Data Structure Library"