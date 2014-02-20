/*
ID: luyangk1
PROG: stamps
LANG: C++
*/

#include <cstdio>
#include <algorithm>

using namespace std;

int k, n, s[64], dp[2000000], c;

int main(int argc, char* argv[]) {
    freopen("stamps.in", "r", stdin);
    freopen("stamps.out", "w", stdout);

	scanf("%d %d", &k, &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", s + i);
	}

	sort(s, s + n);

	dp[0] = 1;
	for (int i = 1; ; i++) {
		int m = 0x7fffffff;
		for (int j = 0; j < n; j++) {
			int p = i - s[j];
			if (p < 0) {
				break;
			}

			if (dp[p] == 0 || dp[p] == k + 1) {
				continue;
			}

			if (dp[p] + 1 < m) {
				m = dp[p] + 1;
			}
		}

		if (m == 0x7fffffff) {
			break;
		}

		dp[i] = m;
		c++;
	}

	printf("%d\n", c);

    return 0;
}