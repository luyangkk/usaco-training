/*
ID: luyangk1
PROG: zerosum
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

char f[] = {' ', '+', '-'}, s[16] = {'+'};
int n;

void dfs(int cur) {
    if (cur == n) {
        int sum = 0, m, tmp;
        for (int i = 0; i < n; i++) {
            tmp = i + 1, m = 1;
            if (s[i] == '-')
                m = -1;
            while (s[i + 1] == ' ') {
                i++;
                tmp = tmp * 10 + i + 1;
            }
            sum += m * tmp;
        }

        if (sum == 0) {
            printf("1");
            for (int i = 1; i < n; i++) {
                printf("%c%d", s[i], i + 1);
            }
            printf("\n");
        }

        return;
    }

    for (int i = 0; i < 3; i++) {
        s[cur] = f[i];
        dfs(cur + 1);
    }
}

int main(int argc, char* argv[]) {
    freopen("zerosum.in", "r", stdin);
    freopen("zerosum.out", "w", stdout);

    //ifstream fin("preface.in");
    //ofstream fout("preface.out");

    scanf("%d", &n);
    dfs(1);

    return 0;
}