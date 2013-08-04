/*
ID: luyangk1
PROG: numtri
LANG: C++
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
//#include <cctype>

//#include <iostream>
//#include <fstream>
//#include <set>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int r, n[1005][1005], dp[1005];

int main(int argc, char* argv[]) {
    freopen("numtri.in", "r", stdin);
    freopen("numtri.out", "w", stdout);

    scanf("%d", &r);
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= i; j++) {
            scanf("%d", &n[i][j]);
        }
    }

    for (int i = r; i > 0; i--) {
        for (int j = 1; j <= i; j++) {
            dp[j] = max(dp[j], dp[j + 1]) + n[i][j];
        }
    }

    printf("%d\n", dp[1]);

    return 0;
}