/*
ID: luyangk1
PROG: castle
LANG: C++
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
//#include <cctype>

//#include <iostream>
//#include <fstream>
//#include <set>
#include <deque>
#include <vector>
#include <algorithm>
#include <functional>v 

#define N 52

using namespace std;

int n, m, fp[N][N], g[N][N], id, cnt[N * N];

void bfs(int x, int y, int id) {
    int d[][4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int v[4] = {2, 0, 3, 1};
    deque<pair<int, int> > q;

    g[x][y] = id;
    q.push_back(pair<int, int>(x, y));
    cnt[id]++;
    while (!q.empty()) {
        int i = q.front().first, j = q.front().second;
        q.pop_front();

        for (int k = 0; k < 4; k++) {
            int a = i + d[k][0], b = j + d[k][1];
            if (a < 0 || a >= m || b < 0 || b >= n || g[a][b] != 0) 
                continue;

            int mask = 1 << v[k];
            if ((fp[i][j] & mask) != mask) {
                g[a][b] = id;
                q.push_back(pair<int, int>(a, b));
                cnt[id]++;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    freopen("castle.in", "r", stdin);
    freopen("castle.out", "w", stdout);

    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &fp[i][j]);
        }
    }

    deque<int> q;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (g[i][j] != 0) continue;
            bfs(i, j, ++id);
        }
    }

    
    int x, y, max = 0;
    char w;
    for (int i = 1; i <= id; i++) {
        if (cnt[i] > max)
            max = cnt[i];
    }
    printf("%d\n", id);
    printf("%d\n", max);

    max = 0;
    for (int j = 0; j < n; j++) {
        for (int i = m - 1; i >= 0; i--) {
            if (i - 1 > 0 && g[i - 1][j] != g[i][j] && 
                cnt[g[i - 1][j]] + cnt[g[i][j]] > max) {
                max = cnt[g[i - 1][j]] + cnt[g[i][j]];
                x = i, y = j, w = 'N';
            }

            if (j + 1 < n && g[i][j + 1] != g[i][j] && 
                cnt[g[i][j + 1]] + cnt[g[i][j]] > max) {
                max = cnt[g[i][j + 1]] + cnt[g[i][j]];
                x = i, y = j, w = 'E';
            }
        }
    }
    printf("%d\n%d %d %c\n", max, x + 1, y + 1, w);

    return 0;
}