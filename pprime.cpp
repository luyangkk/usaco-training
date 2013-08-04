/*
ID: luyangk1
PROG: pprime
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

int a, b;

bool is_prime(int n) {
     if (n == 1) return false;
     else if (n < 4) return true;
     else if (n % 2 == 0) return false;
     else if (n < 9) return true;
     else if (n % 3 == 0) return false;
     else {
        double r = pow(n, 0.5);
        int f = 5;
        while (f <= r) {
            if (n % f == 0) return false;
            if (n % (f + 2) == 0) return false;
            f += 6;
        }
     }

     return true;
}

void gen(int i, int isodd) {
    char buf[30];
    char *p, *q;
    long n;

    sprintf(buf, "%d", i);

    p = buf+strlen(buf);
    q = p - isodd;

    while(q > buf)
	*p++ = *--q;
    *p = '\0';

    n = atol(buf);
    if(a <= n && n <= b && is_prime(n))
	printf("%ld\n", n);
}

void genoddeven(int lo, int hi) {
    int i;

    for(i=lo; i<=hi; i++)
        gen(i, 1);

    for(i=lo; i<=hi; i++)
        gen(i, 0);
}

void generate() {
    genoddeven(1, 9);
    genoddeven(10, 99);
    genoddeven(100, 999);
    genoddeven(1000, 9999);
}

int main(int argc, char* argv[]) {
    freopen("pprime.in", "r", stdin);
    freopen("pprime.out", "w", stdout);

    scanf("%d %d", &a, &b);
  
    generate();

    return 0;
}

/*
ID: luyangk1
PROG: pprime
LANG: C++
*/

/*#include <cstdio>
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

#define MAXP 100000000

using namespace std;

char flag[MAXP / 8 + 5];
int n = 2, a, b;
vector<int> p;

void set_flag(int x) {
    int i = x >> 3;
    int j = x % 8;
    flag[x >> 3] |= 1 << (x % 8);
}

bool get_flag(int x) {
    return flag[x >> 3] & (1 << x % 8);
}

void foo() {
    for (int i = 2; i <= b; i++) {
        if (i != 2 && i % 2 == 0) continue;
        for (int j = i + 1; j <= b; j++) {
            if (get_flag(j) == 0 && j % i == 0) set_flag(j);
        }
    }
}

int main(int argc, char* argv[]) {
    freopen("pprime.in", "r", stdin);
    freopen("pprime.out", "w", stdout);

    scanf("%d %d", &a, &b);

    foo();

    char s[32];
    for (int i = a; i <= b; i++) {
        if (get_flag(i)) continue;

        sprintf(s, "%d", i);
        int l = strlen(s), f = 1;
        for (int j = 0; j < (l >> 1); j++) {
            if (s[j] != s[l - 1 - j]) {
                f = 0;
                break;
            }
        }

        if (f) {
            printf("%d\n", i);
        }
    }

    return 0;
}*/