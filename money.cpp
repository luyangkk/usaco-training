
/*
ID: luyangk1
PROG: money
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
//#include <string>
//#include <sstream>
//#include <map>
//#include <deque>
//#include <vector>
#include <algorithm>
//#include <functional>

using namespace std;

long long int dp[10006];
int c[27];

int main(int argc, char* argv[]) {
    freopen("money.in", "r", stdin);
    freopen("money.out", "w", stdout);

    //ifstream fin("preface.in");
    //ofstream fout("preface.out");

    int v, n;
    scanf("%d %d", &v, &n);
    for (int i = 1; i <= v; i++)
        scanf("%d", c + i);

    dp[0] = 1;
    for (int i = 1; i <= v; i++) {
        for (int j = c[i]; j <= n; j++) {
            dp[j] += dp[j - c[i]];
        }
    }

    printf("%lld\n", dp[n]);

    return 0;
}