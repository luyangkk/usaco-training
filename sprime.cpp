/*
ID: luyangk1
PROG: sprime
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

int n, d[8], d1[] = {2, 3, 5, 7}, d2[] = {1, 3, 7, 9};

bool is_prime(int n) {
     if (n == 1) return false;
     else if (n < 4) return true;
     else if (n % 2 == 0) return false;
     else if (n < 9) return true;
     else if (n % 3 == 0) return false;
     else {
        double r = pow(n , 0.5);
        int f = 5;
        while (f <= r) {
            if (n % f == 0) return false;
            if (n % (f + 2) == 0) return false;
            f += 6;
        }
     }

     return true;
}

void dfs(int m, int l) {
    if (l == n) {
        printf("%d\n", m);
        return;
    }

    for (int i = 0; i < 4; i++) {
        int k = m * 10 + d2[i];
        if (!is_prime(k)) continue;
        dfs(k, l + 1);
    } 
}

int main(int argc, char* argv[]) {
    freopen("sprime.in", "r", stdin);
    freopen("sprime.out", "w", stdout);

    scanf("%d", &n);

    for (int i = 0; i < 4; i++) {
        dfs(d1[i], 1);
    }

    return 0;
}