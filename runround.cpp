/*
ID: luyangk1
PROG: runround
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
//#include <string>
//#include <sstream>
//#include <map>
//#include <deque>
//#include <vector>
//#include <algorithm>
//#include <functional>

int m, f[16], d[16], k[10];
char s[16];

int is_rr_num(int m) {
    sprintf(s, "%d", m);
    int l = strlen(s);

    memset(k, 0, sizeof(k));
    for (int i = 0; i < l; i++) {
        d[i] = s[i] - '0';
        if (d[i] == 0 || k[d[i]] != 0)
            return 0;
        k[d[i]] = 1;
    }

    memset(f, 0, sizeof(f));
    int cur = 0;
    while (f[cur] == 0) {
        f[cur] = 1;
        cur = (cur + d[cur]) % l;
    }

    for (int i = 0; i < l; i++)
        if (f[i] != 1)
            return 0;

    return cur == 0 ? 1 : 0;
}

int main(int argc, char* argv[]) {
    freopen("runround.in", "r", stdin);
    freopen("runround.out", "w", stdout);

    //ifstream fin("preface.in");
    //ofstream fout("preface.out");

    scanf("%d", &m);

    while (++m <= 999999999) {
        if (is_rr_num(m)) {
            printf("%d\n", m);
            break;
        }
    }

    return 0;
}