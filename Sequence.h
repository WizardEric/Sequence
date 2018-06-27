#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <fstream>
#include<vector>

using std::string;

class Sequence
{
private:
	int Number[5];
	int file[100000];//把字母变成数字，我觉得这是一个很好的减少内存占用的方法。Leant from a outstanding student.
	enum FILENB
	{
		A = 1,
		T = 2,
		C = 3,
		G = 4,
	};
	int filelength;

public:
	Sequence(string filename);

	int length();

	int numberOf(char base);

	string longestConsecutive();

	string longestRepeated();
};

#endif
