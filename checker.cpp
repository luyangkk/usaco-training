/*
ID: luyangk1
PROG: checker
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

int n, c = 0, ans = 0, b[15][15];
//int d[][8] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}, {-1, -1}, {1, 1}, {-1, 1}, {1, -1}};
int d[][2] = {{1, -1}, {1, 0}, {1, 1}};
inline void cover(int x, int y, int v) {
    for (int k = 0; k < 3; k++) {
        for (int i = x + d[k][0], j = y + d[k][1];
            j >= 0 && i < n && j < n; 
            i += d[k][0], j += d[k][1]) {  
            if (b[i][j] < 0) continue;
            b[i][j] += v;
        }
    }
}

void dfs(int m) {
    if (m == n) {
        ans++;
        if (c > 2) return; 
        for (int i = 0; i < n; i++) {
            if (b[0][i] < 0)
                printf("%d", i + 1);
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (b[i][j] < 0) {
                    printf(" %d", j + 1);
                }
            }
        }
        printf("\n");
        c++;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (b[m][i] != 0) continue;
        cover(m, i, 1);
        b[m][i] = -10000000;
        dfs(m + 1);
        b[m][i] = 0;
        cover(m, i, -1);
    }
}

int main(int argc, char* argv[]) {
    freopen("checker.in", "r", stdin);
    freopen("checker.out", "w", stdout);

    scanf("%d", &n);
    dfs(0);
    printf("%d\n", ans);

    return 0;
}