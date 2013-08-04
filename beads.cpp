/*
ID: luyangk1
PROG: beads
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
	//freopen("ride.in", "r", stdin);
	//freopen("ride.out", "w", stdout);

	ifstream fin("beads.in");
	ofstream fout("beads.out");

	int n, max = 0;
	string s;
	fin >> n >> s;
	int l1 = s.length(), l2 = l1 * 2;

	s += s;
	for (int i = 1; i < l2; i++) {
		int c1 = 0;
		char b = s[i - 1];
		for (int j = i - 1; j >= 0 && i - j <= l1; j--) {
			if (s[j] != 'w') {
				b = s[j];
				break;
			}
		}
		for (int j = i - 1; j >= 0; j--) {
			if (i - j <= l1 && (s[j] == b || s[j] == 'w'))
				c1++; 
			else
				break;
		}

		int c2 = 0;
		b = s[i];
		for (int j = i; j < l2 && j - i + 1 <= l1 - c1; j++) {
			if (s[j] != 'w') {
				b = s[j];
				break;
			}
		}
		for (int j = i; j < l2; j++) {
			if (j - i + 1 <= l1 - c1 && (s[j] == b || s[j] == 'w'))
				c2++;
			else
				break;
		}
		if (c1 + c2 > max)
			max = c1 + c2;
	}

	fout << max << "\n";

	return 0;
}