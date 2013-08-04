/*
ID: luyangk1
PROG: crypt1
LANG: C++
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>

//#include <iostream>

//#include <fstream>
#include <set>
#include <vector>
#include <algorithm>
//#include <functional>

using namespace std;

int n, r, f[8], v[12];
set<int> s;

bool is_valid(int r) {
    while (r) {
        int i = r % 10;
        if (s.find(i) == s.end())
            return false;
        r /= 10;
    }

    return true;
}

void foo(int k) {
    if (k == 6) {
        int a = v[f[1]] * 100 + v[f[2]] * 10 + v[f[3]];
        int b = v[f[4]];
        int c = v[f[5]];
        int r1 = a * b, r2 = a * c, r3 = r1 + r2 * 10;

        if (is_valid(r1) && is_valid(r2) && is_valid(r3) 
            && !(r1 / 1000) && !(r2 / 1000) && !(r3 / 10000))
            r++;

        return;
    }

    for (int i = 0; i < n; i++) {
        f[k]++;
        foo(k + 1);
    }

    f[k] = 0;
}

int main(int argc, char* argv[]) {
    freopen("crypt1.in", "r", stdin);
    freopen("crypt1.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", v + i);
        s.insert(v[i]);
    }
    
    foo(1);

    printf("%d\n", r);

    return 0;
}