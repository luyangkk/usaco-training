/*
ID: luyangk1
PROG: contact
LANG: C++
*/

#include <cstdio>
#include <cmath>
#include <algorithm>
#include <functional>
#include <map>
#include <vector>
#include <string>

using namespace std;

int a, b, n, l;
char s[200008];

int c[8000];

map<string, int> m;

int idx(const char *s, int l) {
    int m = 0, b = 1;

    for (int i = l - 1; i >= 0; i--) {
        m += (s[i] - '0') * b;
        b *= 2;
    }

    //m += pow(2, (l)) - 2;

    return m;
}

bool cmp(const pair<string, int> &lhs, const pair<string, int> &rhs) {
    if (lhs.second > rhs.second) {
        return true;
    } else if (lhs.second < rhs.second) {
        return false;
    }

    int ls = lhs.first.size(), rs = rhs.first.size();
    if (ls < rs) {
        return true;
    } else if (ls == rs) {
        return idx(lhs.first.c_str(), ls) < idx(rhs.first.c_str(), rs);
    } else {
        return false;
    }
}

int main(int argc, char* argv[]) {
    freopen("contact.in", "r", stdin);
    freopen("contact.out", "w", stdout);

    scanf("%d %d %d", &a, &b, &n);

    char *k = s;
    while (scanf("%s", k) != EOF) {
        while (*k != '\0') k++;
    }
    l = k - s;

    for (int i = 0; i < l; i++) {
        for (int j = a; j <= b && i + j - 1< l; j++) {
            m[string(s + i, j)]++;
        }
    }

    vector<pair<string, int> > v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp);

    int q = 0, e = 0, f = 0;
    for (vector<pair<string, int> >::iterator iter = v.begin(); iter != v.end(); iter++) {
        if (iter->second != e && q + 1 > n) {
            break;
        }

        if (iter->second != e) {
            if (q != 0) {
                printf("\n");
            }
            q++;
            printf("%d\n", iter->second);
            f = 0;
        }

        if (f == 6) {
            printf("\n");
            printf("%s", (iter->first).c_str());
            f = 1;
        } else if (f == 0) {
            printf("%s", (iter->first).c_str());
            f++;
        } else {
            printf(" %s", (iter->first).c_str());
            f++;
        }

        e = iter->second;
    }

    printf("\n");

    return 0;
}