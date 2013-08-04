/*
ID: luyangk1
PROG: sort3
LANG: C++
*/

#include <cstdio>
//#include <cstring>
//#include <cstdlib>
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

int n, d[1024], c[4];
int c12, c13, c21, c23, c31, c32;

int main(int argc, char* argv[]) {
    freopen("sort3.in", "r", stdin);
    freopen("sort3.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", d + i);
        c[d[i]]++;
    }

    for (int i = 1; i <= c[1]; i++) {
        if (d[i] == 2) c12++;
        if (d[i] == 3) c13++;
    }
    for (int i = c[1] + 1; i <= c[1] + c[2]; i++) {
        if (d[i] == 1) c21++;
        if (d[i] == 3) c23++;
    }
    for (int i = c[1] + c[2] + 1; i <= n; i++) {
        if (d[i] == 2) c32++;
        if (d[i] == 1) c31++;
    }

    printf("%d\n", c21 + c31 + (c21 > c12 ? c23 + c21 - c12 : c32 + c12 - c21));

    return 0;
}