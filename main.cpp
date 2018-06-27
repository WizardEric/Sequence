nclude "Sequence.h"
#include <stdlib.h>

using namespace std;


int main()
{
	Sequence S("dna.txt");
	cout << "Length: " << S.length() << endl;
	cout << "A     : " << S.numberOf('A') << endl;
	cout << "T     : " << S.numberOf('T') << endl;
	cout << "C     : " << S.numberOf('C') << endl;
	cout << "G     : " << S.numberOf('G') << endl << endl;
	cout << "Longest Consecutive:" << endl;
	cout << S.longestConsecutive() << endl << endl;
	cout << "Longest Repeated:" << endl;
	cout << S.longestRepeated();

	return 0;
}
