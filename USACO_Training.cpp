/*
ID: luyangk1
PROG: humble
LANG: C++
*/

#include <cstdio>

using namespace std;

int k, n, p[128], m[128], h[100008], min, v, w;

int main(int argc, char* argv[]) {
    freopen("humble.in", "r", stdin);
    freopen("humble.out", "w", stdout);

    //ifstream fin("humble.in");
    //ofstream fout("humble.out");

	scanf("%d %d", &k, &n);
	for (int i = 0; i < k; i++) {
		scanf("%d", p + i);
		m[i] = 0;
	}

	h[0] = 1;
	for (int i = 1; i <= n; i++) {
		min = 0x7fffffff;
		for (int j = 0; j < k; j++) {
			v = p[j] * h[m[j]];
			while (m[j] < (i - 1) && v <= h[i - 1]) {
				m[j]++;
				v = p[j] * h[m[j]];
			}

			if (v < min) {
				min = v;
				w = j;
			}
		}

		h[i] = min;
		m[w]++;

	}

	printf("%d\n", h[n]);

    return 0;
}