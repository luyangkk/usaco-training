/*
  ID: luyangk1
  PROG: ratios
  LANG: C++
  */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 3

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b , a % b);
}

long long determinant(int mat[][MAXN], int n) {
    long long ans = 0, r;
    
    int x, y;
    for (int i = 0; i < n; i++) {
        x = 0, y = i, r = 1;
        for (int j = 0; j < n; j++) {
            r *= mat[x][y];
            x++;
            y = ++y % n;
        }
        ans += r;
    }
    
    for (int i = n - 1; i >= 0; i--) {
        x = 0, y = i, r = 1;
        for (int j = 0; j < n; j++) {
            r *= mat[x][y];
            x++;
            y = --y >= 0 ? y : n - 1;
        }
        ans -= r;
    }
    
    return ans;
}

int main(int argc, char* argv[]) {
    freopen("ratios.in", "r", stdin);
    freopen("ratios.out", "w", stdout);
    int vec[3], mat[3][3], m[3][3];
    
    for (int i = 0; i < 3; i++)
        scanf("%d", vec + i);
    
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            scanf("%d", &mat[j][i]);
    
    long long d = determinant(mat, 3);
    if (d == 0) {
        printf("NONE\n");
        return 0;
    }
    
    memcpy(m, mat, sizeof(mat));
    for (int i = 0; i < 3; i++)
        m[i][0] = vec[i];
    
    long long d1 = determinant(m, 3);
    
    memcpy(m, mat, sizeof(mat));
    for (int i = 0; i < 3; i++)
        m[i][1] = vec[i];
    
    long long d2 = determinant(m, 3);
    
    memcpy(m, mat, sizeof(mat));
    for (int i = 0; i < 3; i++)
        m[i][2] = vec[i];
    
    long long d3 = determinant(m, 3);
    
    if ((d1 < 0 && (d2 > 0 || d3 > 0)) || (d1 > 0 && (d2 < 0 || d3 < 0))) {
        printf("NONE\n");
        return 0;
    }
    
    long long gcd1 = gcd(d, d1);
    long long gcd2 = gcd(gcd1, d2);
    long long gcd3 = gcd(gcd2, d3);
    
    printf("%lld %lld %lld %lld\n", d1 / gcd3, d2 / gcd3, d3 / gcd3, d / gcd3);
    
    return 0;
}