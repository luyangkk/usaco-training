/*
ID: luyangk1
PROG: friday
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>

using namespace std;

int n, c[8] = {0}, w = 0, t, d;
int m[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(int argc, char* argv[]) {
	//freopen("ride.in", "r", stdin);
	//freopen("ride.out", "w", stdout);

	ifstream fin("friday.in");
	ofstream fout("friday.out");

	fin >> n;
	n += 1900;

	for (int y = 1900; y < n; y++) {
		t = w;
		m[2] = (y == 2000 || (y % 4 == 0 && y % 100 != 0)) ? 29 : 28;
		//fout << accumulate(m + 1, m + 13, 0) << "\n";

		for (int i = 0; i < 12; i++) {
			d = t + 13;
			c[d % 7 + 1]++;
			t += m[i + 1];
		}

		w += accumulate(m + 1, m + 13, 0);
		w %= 7;
		//fout << w + 1 << "\n";
	}

	fout << c[7] << " " << c[1] << " " << c[2] << " " << c[3] 
		 << " " << c[4] << " " << c[5] << " " << c[6] << "\n";
	
	return 0;
}