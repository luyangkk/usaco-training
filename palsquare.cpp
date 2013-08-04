/*
ID: luyangk1
PROG: palsquare
LANG: C++
*/

#include <cstdio>
#include <cstring>
//#include <iostream>
//#include <fstream>
//#include <vector>
//#include <utility>
#include <string>
//#include <set>
#include <algorithm>

using namespace std;

char *c[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", 
			 "C", "D", "E", "F", "G", "H", "I", "J"};

bool convert(int x, int b, string &s, bool v) {
	s.clear();
	while (1) {
		if (x < b) {
			s += c[x];
			break;
		}
		s += c[x % b];
		x = (x - x % b) / b;
	}
		
	if (!v)
		return true;

	int l = s.length() / 2;
	for (int i = 0; i < l; i++) {
		if (s[i] != s[s.length() - 1 - i])
			return false;
	}

	return true;
} 

int main(int argc, char* argv[]) {
	freopen("palsquare.in", "r", stdin);
	freopen("palsquare.out", "w", stdout);

	//ifstream fin("namenum.in");
	//ofstream fout("namenum.out");

	int b;
	scanf("%d", &b);
	for (int i = 1; i <= 300; i++) {
		string n1, n2;
		if (convert(i * i, b, n2, true)) {
			convert(i, b, n1, false);
			reverse(n1.begin(), n1.end());
			printf("%s %s\n", n1.c_str(), n2.c_str());
		}
	}

	return 0;
}