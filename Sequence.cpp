#include "Sequence.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <fstream>
#include<vector>

using namespace std;

Sequence::Sequence(string filename)
{
	ifstream infile;
	infile.open(filename);
	if (!infile.is_open())
	{
		cerr << "Open "<< filename <<"failed"<<endl;
		exit(0);
	}
	char f = infile.get();
	int i = 0;
	while (f!= EOF)
	{
		switch (f)
		{
		case 'A':
			{
			Number[1]++;
			file[i++] = 1;
			break;
			}
		case 'C':
			{
			Number[2]++;
			file[i++] = 2;
			break;
			}
		case 'G':
			{
			Number[3]++;
			file[i++] = 3;
			break;
			}
			
		case 'T':
			{
			Number[4]++;
			file[i++] = 4;
			break;
			}
		default:
			break;
		}
		f = infile.get();
	}
}

int Sequence::length()
{
	filelength=Number[1] +Number[2] +Number[3] + Number[4];
	return filelength;
}
int Sequence::numberOf(char base)
{
	switch (base)
	{
	case 'A':
		{
		return Number[1];
		break;
		}
	case 'C':
		{
		return Number[2];
		break;
		}
	case 'G':
		{
		return Number[3];
		break;
		}
	case 'T':
		{
		return Number[4];
		break;
		}
	default:
		cout << "Wrong base"<<endl;
		break;
	}
}

string Sequence::longestConsecutive()
{
	string LC;
	int pos = 0;
	int maxlen = 1;
	int templen = 1;

	for (int i = 1; i < filelength; ++i)
	{
		if (file[i] == file[i - 1])
		{
			templen++;//获取当前位置连续数字的长度
			if (templen > maxlen)//如果其长度大于目前最长的，则替换
			{
				pos = file[i];
				maxlen = templen;
			}
		}
		else
		{
			templen = 1;
		}
	}//逐位找最长的字符，如果有比当前长的，就替换。

	switch (pos)
	{
	case 1:
		LC.assign(maxlen, 'A');
		break;
	case 2:
		LC.assign(maxlen, 'C');
		break;
	case 3:
		LC.assign(maxlen, 'G');
		break;
	case 4:
		LC.assign(maxlen, 'T');
		break;
	default:
		break;
	}//因为是数字，所以要重新把数字变为字母。default不输出

	return LC;
}

string Sequence::longestRepeated()
{
	string LR;

    vector<vector<int> > f( filelength + 1, vector<int>( filelength + 1, 0));
   int max = -1;
   int start=-1;
   for (int i = 1; i <=  filelength; i++)
   {
       for (int j = 1; j <=  filelength; j++) 
	   {
           if (file[i - 1] != file[j - 1]) 
			   f[i][j] = 0;
           else if (file[i - 1] == file[j - 1]) 
			   f[i][j] = f[i - 1][j - 1] + 1;
           if (max < f[i][j]) 
		   {
             max = f[i][j];
			 start=i;
           }
       }//寻找最长公共子串，记录其长度，及其开头位置
    }
				
		for (int i = start; i < start + max - 1; ++i)
	{
		switch (file[i])
		{
		case 1:
			LR[i] = 'A';
			break;
		case 2:
			LR[i] = 'C';
			break;
		case 3:
			LR[i] = 'G';
			break;
		case 4:
			LR[i] = 'T';
			break;
		default:
			break;
		}
	}//把file数组中的最长子串转化为字母

	return LR;
}
