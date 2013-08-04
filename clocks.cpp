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
#include <functional>v 

using namespace std;

int n, c = 0, cnt = 0, vis[3][32], b[15];

void print() {
    for (int i = 0; i < n - 1; i++) 
        printf("%d ", b[i] + 1);
    printf("%d\n", b[n - 1]);
    c++;
}

void dfs(int cur) {
    if (cur == n) {
        cnt++;
        if (c < 3) print();        
        return;
    }

    for (int i = 0; i < n; i++) {
        if (vis[0][i] || vis[1][cur + i] || vis[2][cur - i + n]) 
            continue;

        b[cur] = i;
        vis[0][i] = vis[1][cur + i] = vis[2][cur - i + n] = 1;
        dfs(cur + 1);
        vis[0][i] = vis[1][cur + i] = vis[2][cur - i + n] = 0;
    }
}

int main(int argc, char* argv[]) {
    freopen("checker.in", "r", stdin);
    freopen("checker.out", "w", stdout);

    scanf("%d", &n);
    dfs(0);
    printf("%d\n", cnt);

    return 0;
}