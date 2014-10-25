/*
  ID: luyangk1
  PROG: wormhole
  LANG: C++
  */
#include <stdio.h>
#include <algorithm>

using namespace std;

#define MAX_N 16

int n, x[MAX_N], y[MAX_N];
int partner[MAX_N];
int next_on_right[MAX_N];

bool circle_exists() {
    for (int start = 1; start <= n; start++) {
        int pos = start;
        for (int i = 1; i <= n; i++)
            pos = next_on_right[partner[pos]];
        if (pos != 0) return true;
    }
    return false;
}

int solve() {
    int i, total = 0;
    for (i = 1; i <= n; i++)
        if (partner[i] == 0)
            break;
    
    if (i > n)
        return circle_exists() ? 1 : 0;
    
    for (int j = i + 1; j <= n; j++)
        if (partner[j] == 0) {
            partner[i] = j, partner[j] = i;
            total += solve();
            partner[i] = 0, partner[j] = 0;
        }
    
    return total;
}

int main(int argc, char* argv[]) {
    freopen("wormhole.in", "r", stdin);
    freopen("wormhole.out", "w", stdout);
    
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d %d", x + i, y + i);
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (x[i] < x[j] && y[i] == y[j])
                if (next_on_right[i] == 0
                    || x[j] - x[i] < x[next_on_right[i]] - x[i])
                    next_on_right[i] = j;
    
    printf("%d\n", solve());
    
    return 0;
}
