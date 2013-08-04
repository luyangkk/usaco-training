/*
ID: luyangk1
PROG: ariprog
LANG: C++
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
//#include <cctype>

//#include <iostream>
//#include <fstream>
#include <set>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

bool cmp(const pair<int ,int> &l, const pair<int, int> r) {
    return l.second < r.second;
}

int n, m, s[300];

int main(int argc, char* argv[]) {
    freopen("ariprog.in", "r", stdin);
    freopen("ariprog.out", "w", stdout);

    scanf("%d %d", &n, &m);

    int n1;
    for (n1 = 0; n1 <= m; n1++) {
        s[n1] = n1 * n1;
    }

    set<int> d;
    for (int i = 0; i < n1; i++) {
        for (int j = i; j >= 0; j--) {
            d.insert(s[i] + s[j]);
        }
    }

    vector<int> v(d.begin(), d.end());
    vector<pair<int, int> > ans;
    int n2 = v.size();
    for (int i = 0; i < n2 - 1; i++) {
        for (int j = i + 1; j < n2; j++) {
            int g = v[j] - v[i];
            if (v[i] + g * (n - 1) > v.back())
                break;
        
            int k = 2;
            for (int z = v[j] + g; k <= n; k++, z += g) {
                if (d.find(z) == d.end()) 
                    break;
            }
            if (k >= n) {
                ans.push_back(pair<int, int>(v[i], g));
            }
        }
    }

    sort(ans.begin(), ans.end(), cmp);

    for (vector<pair<int, int> >::iterator iter = ans.begin(); 
        iter != ans.end(); iter++) {
        printf("%d %d\n", iter->first, iter->second);
    }
    
    if (ans.empty()) {
        printf("NONE\n");
    }

    return 0;
}