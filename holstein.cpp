/*
ID: luyangk1
PROG: holstein
LANG: C++
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>
//#include <cmath>
//#include <cctype>

//#include <iostream>
//#include <fstream>
//#include <set>
//#include <deque>
#include <vector>
#include <algorithm>
//#include <functional>

using namespace std;

int t, r[32], g, s[16][32], f[16], d[16], b[32], c = 0x7fffffff;

void dfs(int cur, int n) {
    if (cur > g || n >= c) return;
    
    int flag = 1;
    for (int i = 0; i < t; i++) {
        if (b[i] < r[i]) {
            flag = 0;
            break;
        }
    }

    if (flag) {
        c = n; 
        memcpy(d, f, sizeof(int) * g);
        return;
    }

    f[cur] = 1;
    for (int i = 0; i < t; i++) b[i] += s[cur][i];
    dfs(cur + 1, n + 1);
    for (int i = 0; i < t; i++) b[i] -= s[cur][i];
    f[cur] = 0;
    dfs(cur + 1, n);
}

int main(int argc, char* argv[]) {
    freopen("holstein.in", "r", stdin);
    freopen("holstein.out", "w", stdout);

    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d", r + i);
    }
    scanf("%d", &g);
    for (int i = 0; i < g; i++) {
        for (int j = 0; j < t; j++) {
            scanf("%d", &s[i][j]);
        }
    }

    dfs(0, 0);

    printf("%d", c);
    for (int i = 0; i < g; i++) {
        if (d[i] == 1)
            printf(" %d", i + 1);
    }
    printf("\n");

    return 0;
}