/*
ID: luyangk1
PROG: gift1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

map<string, int> init, cur;
string seq[15];

int main(int argc, char* argv[]) {
	/*freopen("ride.in", "r", stdin);
	freopen("ride.out", "w", stdout);*/

	ifstream fin("gift1.in");
	ofstream fout("gift1.out");

	int np, money, ng;
	string name;

	fin >> np;
	for (int i = 0; i < np; i++) {
		fin >> name;
		init[name] = 0;
		cur[name] = 0;
		seq[i] = name;
	}

	for (int i = 0; i < np; i++) {
		fin >> name >> money >> ng;
		init[name] = money;
		if (ng == 0)
			continue;

		cur[name] += money % ng;
		for (int j = 0; j < ng; j++) {
			fin >> name;
			cur[name] += money / ng;
		}
	}
	
	for (int i = 0; i < np; i++) {
		string &s = seq[i];
		fout << s << " " << cur[s] - init[s] << "\n";
	}

	return 0;
}