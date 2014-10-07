/*
  ID: luyangk1
  PROG: skidesign
  LANG: C++
  */
#include <stdio.h>

int n, h[1024];

int main(int argc, char* argv[]) {
    freopen("skidesign.in", "r", stdin);
    freopen("skidesign.out", "w", stdout);
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", h + i);
    
    int m = 0x7fffffff;
    for (int i = 0; i <= 83; i++) {
        int f = i, t = i + 17, r = 0;
        for (int j = 0; j < n; j++) {
            if (h[j] < f)
                r += (h[j] - f) * (h[j] - f);
            else if (h[j] > t)
                r += (t - h[j]) * (t - h[j]);
            
            if (r > m) break;
        }
        
        if (r < m) m = r;
    }
    
    printf("%d\n", m);
    
    return 0;
}
