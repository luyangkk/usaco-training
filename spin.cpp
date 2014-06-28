/*
  ID: luyangk1
  PROG: spin
  LANG: C++
  */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct seg {
    int start, end;
} seg_t;

int s[5], w[5];
seg_t r[5][5];
int f[360];

void mark(int *f, seg_t s) {
    int i;
    if (s.start <= s.end) {
        for (i = s.start; i <= s.end; i++) {
            f[i]++;
        }
    } else {
        for (i = s.start; i < 360; i++) {
            f[i]++;
        }
        for (i = 0; i <= s.end; i++) {
            f[i]++;
        }
    }
}

int main(int argc, char* argv[]) {
    int d, l, res;
    
    freopen("spin.in", "r", stdin);
    freopen("spin.out", "w", stdout);
    
    for (int i = 0; i < 5; i++) {
        scanf("%d %d", &s[i], &w[i]);
        for (int j = 0; j < w[i]; j++) {
            scanf("%d %d", &d, &l);
            r[i][j].start = d;
            r[i][j].end = (d + l) % 360;
        }
    }
    
    for (d = 0; d < 360; d++) {
        memset(f, 0, sizeof(f));
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < w[i]; j++) {
                mark(f, r[i][j]);
            }
        }
        
        res = 0;
        for (int i = 0; i < 360; i++) {
            if (f[i] == 5) {
                res = 1;
                break;
            }
        }
        
        if (res) {
            break;
        }
        
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < w[i]; j++) {
                r[i][j].start += s[i];
                r[i][j].start %= 360;
                r[i][j].end += s[i];
                r[i][j].end %= 360;
            }
        }
    }
    
    if (res) {
        printf("%d\n", d);
    } else {
        printf("none\n");
    }
    
    return 0;
}
