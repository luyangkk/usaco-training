/*
ID: luyangk1
PROG: lamps
LANG: C++
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>
//#include <cmath>
//#include <cctype>

//#include <iostream>
//#include <fstream>
#include <set>
#include <string>
//#include <sstream>
//#include <map>
//#include <deque>
//#include <vector>
//#include <algorithm>
//#include <functional>

using namespace std;

int n, c, l, on[128], off[128], f[8], s[8], a, b;
set<string> ans;

void func1() {
    for (int i = 1; i <= 6; i++)
        s[i] =  1 - s[i];
}

void func2() {
    for (int i = 1; i <= 6; i += 2)
        s[i] =  1 - s[i];
}

void func3() {
    for (int i = 2; i <= 6; i += 2)
        s[i] =  1 - s[i];
}

void func4() {
    s[1] = 1 - s[1];
    s[4] = 1 - s[4];
}

void (*func[])(void) = {func1, func2, func3, func4};

void dfs(int cur) {
    if (cur == c) {
        for (int i = 0; i < a; i++) {
            if (s[(on[i] - 1) % 6 + 1] != 1)
                return;
        }

        for (int i = 0; i < b; i++) {
            if (s[(off[i] - 1) % 6 + 1] != 0)
                return;
        }

        string m;
        for (int i = 1; i <= 6; i++) 
            m += s[i] + '0';
        ans.insert(m);
        return;
    }

    for (int i = 0; i < 4; i++) {
        func[i]();
        dfs(cur + 1);
        func[i]();

        dfs(cur + 1);
    }
}

int main(int argc, char* argv[]) {
    freopen("lamps.in", "r", stdin);
    freopen("lamps.out", "w", stdout);

    //ifstream fin("preface.in");
    //ofstream fout("preface.out");

    scanf("%d %d", &n, &c);
    c %= 8;

    while (scanf("%d", &l) && l != -1) 
        on[a++] = l;

    while (scanf("%d", &l) && l != -1) 
        off[b++] = l;

    for (int i = 1; i <= 6; i++)
        s[i] = 1;

    dfs(0);

    if (ans.empty()) {
        printf("IMPOSSIBLE\n");
    } else {
        for (set<string>::iterator iter = ans.begin(); iter != ans.end(); iter++) {
            const string &v = *iter;
            for (int i = 0, k = 0; i < n; i++) {
                printf("%c", v[k]);
                if (++k == 6)
                    k = 0;
            }
            printf("\n");
        }
    }

    return 0;
}