/*
ID: luyangk1
PROG: comehome
LANG: C++
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

#define N 64

int **g, dist[N], prev[N], p, v;

inline int get_id(char c) {
    return (c >= 'a' && c <= 'z' ? 26 + c - 'a' : c - 'A');
}

inline char get_name(int id) {
    return (id < 26 ? 'A' + id : 'a' + id - 26);
}

void dijstra(int **g, int *dist, int *prev, int n, int v) {
    bool *f = (bool *)malloc(sizeof(bool) * (n + 4));
    memset(f, 0, sizeof(bool) * (n + 4));

    for (int i = 0; i < n; i++) {
        dist[i] = g[v][i];
    }

    f[v] = 1;

    int tmp_dist, u, new_dist;
    for (int i = 0; i < n; i++) {
        tmp_dist = 0x7fffffff, u = v;
        for (int j = 0; j < n; j++) {
            if (!f[j] && dist[j] < tmp_dist) {
                tmp_dist = dist[j], u = j;
            }
        }

        f[u] = 1;

        for (int j = 0; j < n; j++) {
            if (!f[j] && g[u][j] < 0x7fffffff) {
                if ((new_dist = dist[u] + g[u][j]) < dist[j]) {
                    dist[j] = new_dist;
                }
            }
        }
    }
}

int main(int argc, char *argv[]) {
    freopen("comehome.in", "r", stdin);
    freopen("comehome.out", "w", stdout);

    g = (int **)malloc(sizeof(int) * N);
    g[0] = (int *)malloc(sizeof(int) * N * N);
    for (int i = 1; i < N; i++)
        g[i] = g[i - 1] + N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            g[i][j] = 0x7fffffff;
        }
    }

    scanf("%d", &p);
    getchar();

    int d;
    char f, t;
    for (int i = 0; i < p; i++) {
        f = getchar();
        getchar();
        t =getchar();
        scanf("%d", &d);
        getchar();
        if (g[get_id(f)][get_id(t)] > d)
            g[get_id(f)][get_id(t)] = d;
        if (g[get_id(t)][get_id(f)] > d)
            g[get_id(t)][get_id(f)] = d;
    }

    dijstra(g, dist, prev, 52, get_id('Z'));

    char r;
    int min_dist = 0x7fffffff;
    for (int i = 0; i < 25; i++) {
        if (dist[i] < min_dist) {
            r = get_name(i);
            min_dist = dist[i];
        }
    }

    printf("%c %d\n", r, min_dist);

    return 0;
}