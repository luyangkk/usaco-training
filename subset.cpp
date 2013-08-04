/*
ID: luyangk1
PROG: subset
LANG: C++
*/

//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <cmath>
//#include <cctype>

#include <iostream>
#include <fstream>
//#include <set>
#include <string>
#include <sstream>
#include <map>
//#include <deque>
//#include <vector>
//#include <algorithm>
#include <functional>

#define N 400

using namespace std;

long long int dp[N];

int main(int argc, char* argv[]) {
    freopen("subset.in", "r", stdin);
    freopen("subset.out", "w", stdout);

    //ifstream fin("preface.in");
    //ofstream fout("preface.out");

    int n, v;
    scanf("%d", &n);
    v = n * (n + 1) / 4;

    dp[0] = 1;
    for (int i = 1; i <= v; i++)
        dp[i] = 0x8000000000000000;
    
    for (int i = 1; i <= n; i++) {
        for (int j = v; j >= i; j--) {
            dp[j] = (dp[j] < 0 ? dp[j - i] : dp[j] + dp[j - i]);
        }
    }

    if ((n * (n + 1) / 2) % 2 == 0)
        printf("%d\n", dp[v] / 2);
    else 
        printf("%d\n", 0);

    return 0;
}