/*
ID: luyangk1
PROG: barn1
LANG: C++
*/

//#include <stdio.h>

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int m, s, c, total;
vector<int> stalls, diff;

int main(int argc, char* argv[]) {
	//freopen("milk.in", "r", stdin);
	//freopen("milk.out", "w", stdout);

	ifstream fin("barn1.in");
	ofstream fout("barn1.out");

	fin >> m >> s >> c;

	if (m >= c) {
		fout << c << endl;
		return 0;
	}

	int k;
	for (int i = 0; i < c; i++) {
		fin >> k;
		stalls.push_back(k);
	}
	sort(stalls.begin(), stalls.end(), less<int>());
	total = stalls.back() - stalls.front() + 1;

	for (vector<int>::iterator iter = stalls.begin() + 1; 
		iter != stalls.end(); iter++) {
		diff.push_back(*iter - *(iter - 1));
	}
	sort(diff.begin(), diff.end(), greater<int>());

	m--;
	vector<int>::iterator iter = diff.begin();
	for (int i = 0; i < m; i++) {
		total -= (*iter - 1);
		iter++;
	}

	fout << total << endl;

	return 0;
}