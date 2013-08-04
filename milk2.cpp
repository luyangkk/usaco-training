/*
ID: luyangk1
PROG: milk2
LANG: C++
*/

//#include <iostream>
//#include <fstream>
#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class Compare{
public:
	bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs) {
		if (lhs.first < rhs.first) {
			return true;
		} else if (lhs.first > rhs.first) {
			return false;
		} else {
			return lhs.second < rhs.second ? true : false;
		}
	}
} cmp;

int main(int argc, char* argv[]) {
	freopen("milk2.in", "r", stdin);
	freopen("milk2.out", "w", stdout);

	//ifstream fin("beads.in");
	//ofstream fout("beads.out");

	int n;
	scanf("%d", &n);

	vector<pair<int, int> > v;
	for (int i = 0; i < n; i++) {
		pair<int, int> p;
		scanf("%d %d", &p.first, &p.second);
		v.push_back(p);
	}

	sort(v.begin(), v.end(), cmp);

	int longest_milking = v[0].second - v[0].first;
	int longest_idle = 0;
	pair<int, int> cur(v[0]);
	for (vector<pair<int, int> >::iterator iter = v.begin() + 1; 
		iter != v.end(); iter++) {
			int milking = 0;
			int idle = 0;
			if (iter->first <= cur.second && iter->second > cur.second) {
				milking = iter->second - cur.first;
				if (milking > longest_milking)
					longest_milking = milking;
				cur.second = iter->second;
			} else if (iter->first > cur.second) {
				idle = iter->first - cur.second;
				if (idle > longest_idle)
					longest_idle = idle;
				cur = *iter;
			} else if (iter->second > cur.second) {
				cur.second = iter->second;
			}
	}

	printf("%d %d\n", longest_milking, longest_idle);

	return 0;
}