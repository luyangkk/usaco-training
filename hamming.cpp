/*
ID: luyangk1
PROG: hamming
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

int n, b, d, f, g[1024], m;

inline unsigned ham_dist(unsigned x, unsigned y) {
    unsigned dist = 0, val = x ^ y;
 
    /* Count the number of set bits */
    while(val) {
        ++dist; 
        val &= val - 1;
    }
 
    return dist;
}

void print_ans() {
    int p = 1, c = 0;
    for (int i = 0; i < m; i++) {
        if (g[i] != 1) continue;
        if (p == 1) 
            printf("%d", i);
        else 
            printf(" %d", i);
        c++;
        if (p == 10 || c == n) {
            printf("\n");
            p = 0;
        }
        p++;
    }
}

void dfs(int cur, int c) {
    if (c == n) {
        print_ans();
        f = 1;
        return;
    }

    if (cur >= m || f == 1) return;

    int k = 1;
    for (int i = 0; i < m; i++) {
        if (g[i]) {
            if (ham_dist(cur, i) < d) {
                k = 0;
                break;
            }
        }
    }
    
    if (k) {
        g[cur] = 1;
        dfs(cur + 1, c + 1);
        g[cur] = 0;
    }
    dfs(cur + 1, c);
}

int main(int argc, char* argv[]) {
    freopen("hamming.in", "r", stdin);
    freopen("hamming.out", "w", stdout);

    scanf("%d %d %d", &n, &b, &d);
    m = 1 << b;
    dfs(0, 0);

    return 0;
}