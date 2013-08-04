/*
ID: luyangk1
PROG: milk
LANG: C++
*/

//#include <stdio.h>

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

class Cmp {
public:
	bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs) {
		return (lhs.first < rhs.first ? true : false);
	}
} cmp;

int main(int argc, char* argv[]) {
	//freopen("milk.in", "r", stdin);
	//freopen("milk.out", "w", stdout);

	ifstream fin("milk.in");
	ofstream fout("milk.out");

	int n, m;
	fin >> n >> m;
	
	vector<pair<int, int> > v;
	pair<int, int> f;
	for (int i = 0; i < m; i++) {
		fin >> f.first >> f.second;
		v.push_back(f);
	}
	sort(v.begin(), v.end(), cmp);

	int p = 0;
	for (vector<pair<int, int> >::iterator iter = v.begin(); 
		iter != v.end(); iter++) {
		if (n > iter->second) {
			p += iter->first * iter->second;
			n -= iter->second;
		} else {
			p += iter->first * n;
			n = 0;
			break;
		}
	}

	fout << p << endl;

	return 0;
}