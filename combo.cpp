/*
  ID: luyangk1
  PROG: combo
  LANG: C++
  */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, x1, y1, z1, x2, y2, z2, c;

bool judge(int a, int b) {
    if (a < b) {
        return b - a <= 2 || a + n - b <= 2;
    } else {
        return a - b <= 2 || b + n - a <= 2;
    }
}

bool work(int x, int y, int z, int a, int b, int c) {
    return judge(x, a) && judge(y, b) && judge(z, c);
}

int main(int argc, char* argv[]) {
    freopen("combo.in", "r", stdin);
    freopen("combo.out", "w", stdout);
    
    scanf("%d", &n);
    scanf("%d %d %d", &x1, &y1, &z1);
    scanf("%d %d %d", &x2, &y2, &z2);
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (work(x1, y1, z1, i, j, k) || work(x2, y2, z2, i, j, k)) {
                    c++;
                }
            }
        }
    }
    
    printf("%d\n", c);
    
    return 0;
}
