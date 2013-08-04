/*
ID: luyangk1
PROG: calfflac
LANG: C++
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>

//#include <iostream>
//#include <fstream>
//#include <vector>
#include <algorithm>
//#include <functional>

using namespace std;

const char padding = '#';

char * preprocess(char *before, int len) {
    char *after = (char *) malloc(sizeof(char) * len * 2 + 2);

    int k = 0;
    after[k++] = padding;
    for (int i = 0; i < len; i++) {
        after[k++] = before[i];
        after[k++] = padding;
    }
    after[k] = '\0';

    return after;
}

char s0[80500];
char s1[80500];
int pos[80500];

int main(int argc, char* argv[]) {
    freopen("calfflac.in", "r", stdin);
    freopen("calfflac.out", "w", stdout);

    char *cur = s0;
    while (fgets(cur, 100, stdin) != NULL) {
        cur += strlen(cur);
	}
    
    int l = strlen(s0);
    int k = 0, j = 1;
    pos[0] = -1;
    for (int i = 0; i < l; i++) {
        if (isalpha(s0[i])) {
            s1[k++] = tolower(s0[i]);
            pos[j++] = i;
            pos[j++] = -1;
        }
    }

    int b, e;
    {
        char *t = preprocess(s1, strlen(s1));
        int n = strlen(t);
        int *p = (int *)malloc(sizeof(int) * n + 1);
        memset(p , 0, sizeof(int) * n + 1);
        int c = 0, r = 0 ;

        for (int i = 0; i < n - 1; i++) {
            p[i] = r > i ? min( p[2 * c - i ], r - i) : 1;
        
            while (t[i + p[i]] == t[i - p[i]])
                p[i]++;
        
            if (i + p[i] > r)
                r = i + p[i], c = i;
        }

        r = 0;
        for (int i = 0; i < n; i++) {
            if (p[i] > r)
                c = i, r = p[i];
        }

        b = c - r + 1;
        if (t[b] == padding)
            b++;

        e = c + r - 2;
        if (t[e] == padding)
            e--;

        printf("%d\n", r - 1);

        free(t);
        free(p);
    }


    for (int i = pos[b]; i <= pos[e]; i++) {
        printf("%c", s0[i]);
    }
    printf("\n");

    return 0;
}