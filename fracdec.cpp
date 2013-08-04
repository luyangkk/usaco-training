/*
ID: luyangk1
PROG: fracdec
LANG: C++
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <set>

using namespace std;

int n, d, f = 1, m;
set<int> s;
char res[900000];

int get_k(int x, int b) {
    int c = 0;
    while (x % b == 0) {
        c++;
        x /= b;
    }
    return c;
}

int gcd(int a, int b) {
    return b > 0 ? gcd(b, a % b) : a;
}

int main(int argc, char *argv[]) {
    freopen("fracdec.in", "r", stdin);
    freopen("fracdec.out", "w", stdout);

    scanf("%d %d", &n, &d);

    int k1 = get_k(d, 2);
    int k2 = get_k(d, 5);
    m = (k1 > k2 ? k1 : k2);

    if (n % d == 0) {
        printf("%.1f\n", (float) n / d);
        return 0;
    } else {
        int t = d / gcd(n, d);
        int y = 1;
        while (1) {
            if (t % 2 == 0) {
                t /= 2;
                continue;
            }
            if (t % 5 == 0) {
                t /= 5;
                continue;
            }
            if (t != 1) {
                y = 0;
            }
            break;
        }

        if (y == 1) {
            sprintf(res, "%f", (float)n / d);
            for (int i = strlen(res) - 1; i >= 0; i--)
                if (res[i] != '0') {
                    res[i + 1] = '\0';
                    break;
                }
            printf("%s\n", res);
            return 0;
        }
    }

    sprintf(res, "%d", n / d);
    n %= d;

    int l = strlen(res);
    printf("%s", res);
    putchar('.');
    l++;

    while (1) {
        if (l % 76 == 0)
            putchar('\n');
        l++;
        if (m > 0) {
            m--;
        } else if (m == 0) {
            putchar('(');
            m--;
            continue;
        }

        n *= 10;

        if (s.find(n) != s.end())
            break;
        s.insert(n);
        printf("%d", n / d);
        n %= d;
    }

    if (l % 76 == 0) {
        putchar('\n');
    }
    printf(")\n");

    return 0;
}