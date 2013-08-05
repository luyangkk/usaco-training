/*
ID: luyangk1
PROG: inflate
LANG: C++
*/

#include <cstdio>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

using namespace std;

int m, n, w[10003], c[10003], dp[10003];

int main(int argc, char* argv[]) {
    freopen("inflate.in", "r", stdin);
    freopen("inflate.out", "w", stdout);

    //ifstream fin("preface.in");
    //ofstream fout("preface.out");


	scanf("%d %d", &m, &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", w + i, c + i);
	}

	for (int i = 0; i < n; i++) {
		for (int j = c[i]; j <= m; j++) {
			dp[j] = MAX(dp[j - c[i]] + w[i], dp[j]);
		}
	}

	printf("%d\n", dp[m]);

    return 0;
}