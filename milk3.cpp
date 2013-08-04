/*
ID: luyangk1
PROG: milk3
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

int c[3], s[212121], ans[30], l;

void dfs(int state) {
    if (s[state] == 1)
        return;

    s[state] = 1;
    int d[] = {state % 100,  state / 100 % 100, state / 10000 % 100};

    if (d[0] == 0) {
        ans[l++] = d[2];
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j || d[j] == c[j] || d[i] == 0) continue;
            int k = min(c[j] - d[j], d[i]);
            d[i] -= k, d[j] += k;
            dfs(d[0] + d[1] * 100 + d[2] * 10000);
            d[i] += k, d[j] -= k;
        }
    }
}

int main(int argc, char* argv[]) {
    freopen("milk3.in", "r", stdin);
    freopen("milk3.out", "w", stdout);

    scanf("%d %d %d", c, c + 1, c + 2);
    dfs(c[2] * 10000);
    sort(ans, ans + l);

    printf("%d", ans[0]);
    for (int i = 1; i < l; i++)
        printf(" %d", ans[i]);
    printf("\n");

    return 0;
}