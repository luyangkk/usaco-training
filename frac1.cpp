/*
ID: luyangk1
PROG: frac1
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

class frac_t {
public:
    int a, b;
    double v;

    frac_t(int a, int b) { 
        this->a = a; 
        this->b = b;
        v = (double)a / b;
    }

    bool operator<(const frac_t &that) const {
        return this->v < that.v;
    }
};

int n;
vector<frac_t> s;

int gcd(int a, int b) {
    return b > 0 ? gcd(b, a % b) : a;
}

int main(int argc, char* argv[]) {
    freopen("frac1.in", "r", stdin);
    freopen("frac1.out", "w", stdout);

    scanf("%d", &n);

    s.push_back(frac_t(0, 1));
    s.push_back(frac_t(1, 1));
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i < j; i++) {
            int d = gcd(i, j);
            s.push_back(frac_t(i / d, j / d));
        }
    }

    sort(s.begin(), s.end());

    printf("%d/%d\n", s[0].a, s[0].b);
    int l = s.size();
    for (int i = 1; i < l; i++) {
        if (s[i].v - s[i - 1].v > 0.00000000001) {
            printf("%d/%d\n", s[i].a, s[i].b);
        }
    }

    return 0;
}