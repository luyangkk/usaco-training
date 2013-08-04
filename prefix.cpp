/*
ID: luyangk1
PROG: prefix
LANG: C++
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>
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

struct node {
    int next[26];
    bool f;
    void init() { memset(next, -1, sizeof(next)); }
} s[20000];

int ind;

void insert(char *a, int l) {
    int k = 0;
    for (int i = 0; i < l; i++) {
        int x = a[i] - 'A';
        if (s[k].next[x] == -1) {
            s[++ind].init();
            s[k].next[x] = ind;
        }
        k = s[k].next[x];
    }
    s[k].f = 1;
}

bool find(char *a, int l) {
    int k = 0;
    for (int i = 0; i < l; i++) {
        int x = a[i] - 'A';
        if (s[k].next[x] == -1)
            return false;
        k = s[k].next[x]; 
    }
    return s[k].f;
}

char w[256], str[210000];
bool dp[210000] = {1};
int l;

int main(int argc, char* argv[]) {
    freopen("prefix.in", "r", stdin);
    freopen("prefix.out", "w", stdout);

    //ifstream fin("preface.in");
    //ofstream fout("preface.out");

    s[0].init();
    while (scanf("%s", w) != EOF && strcmp(w, ".") != 0)
        insert(w, strlen(w));

    char *p = str + 1;
    while (scanf("%s", p) != EOF) {
        l = strlen(p);
        p += l;
    }

    l = strlen(str + 1);
    for (int i = 1; i <= l; i++) {
        for (int j = i - 1; i - j <= 10; j--) {
            if (dp[j] != 1) continue;
            if (find(str + j + 1, i - j)) {
                dp[i] = 1;
                break;
            }
        }
    }

    for (int i = l; i >= 0; i--) {
        if (dp[i] == 1) {
            printf("%d\n", i);
            break;
        }
    }

    return 0;
}