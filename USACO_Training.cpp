#include "stdafx.h"


/*
ID: luyangk1
PROG: humble
LANG: C++
*/

#include <cstdio>
#include <set>

using namespace std;

int k, n, t[128];
set<int> s;

int main(int argc, char* argv[]) {
    freopen("humble.in", "r", stdin);
    freopen("humble.out", "w", stdout);

    //ifstream fin("humble.in");
    //ofstream fout("humble.out");

    s.insert(1);
    scanf("%d %d", &k, &n);
    for (int i = 0; i < k; i++) {
        scanf("%d", t + i);
        s.insert(t[i]);
    }

    int m = t[0] - 1, c = 0;
    while (c < n) {
        m++;
        for (int j = 0; j < k; j++) {
            if (m % t[j] == 0 && s.find(m / t[j]) != s.end()) {
                c += 1;
                s.insert(m);
                break;
            }
        }
    }

    printf("%d\n", m);

    return 0;
}