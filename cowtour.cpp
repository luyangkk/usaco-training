/*
ID: luyangk1
PROG: cowtour
LANG: C++
*/

#include <cstdio>
//#include <cstring>
//#include <cstdlib>
#include <cmath>
//#include <cctype>

//#include <iostream>
//#include <fstream>
//#include <map>
//#include <set>
//#include <string>
//#include <sstream>
#include <deque>
//#include <vector>
#include <algorithm>
//#include <functional>

#define MAX 999999999

using namespace std;

int n, c[160][160], f[160], cn;
char g[160][160];
double dist[160][160], h[160];
pair<int, int> p[160];

double comp_dist(pair<int, int> &a, pair<int, int> &b) {
    double dx = a.first - b.first;
    double dy = a.second - b.second;
    return sqrt(dx * dx + dy * dy);
}

void bfs(int x, int k) {
    int &l = c[k][0];

    deque<int> q;
    q.push_back(x);
    f[x] = 1;

    int cur;
    while (!q.empty()) {
        cur = q.front();
        c[k][++l] = cur;
        q.pop_front();

        for (int i = 0; i < n; i++) {
            if (g[cur][i] == '0' || f[i] == 1) {
                continue;
            }
            q.push_back(i);
            f[i] = 1;
        }
    }
}

void floyd() {
    double new_dist;
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                new_dist = dist[i][k] + dist[k][j];
                if (new_dist < dist[i][j]) {
                    dist[i][j] = new_dist;
                }
            }
        }
    }
}

int main(int argc, char* argv[]) {
    freopen("cowtour.in", "r", stdin);
    freopen("cowtour.out", "w", stdout);

    //ifstream fin("preface.in");
    //ofstream fout("preface.out");

    scanf("%d", &n);

    int x, y;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        p[i].first = x, p[i].second = y;
    }

    for (int i = 0; i < n; i++) {
        getchar();
        for (int j = 0; j < n; j++) {
            scanf("%c", &g[i][j]);
            if (g[i][j] == '1') {
                dist[i][j] = comp_dist(p[i], p[j]);
            } else {
                dist[i][j] = MAX;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (f[i] != 1) {
            bfs(i, cn++);
        }
    }

    floyd();

    double od = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] != MAX && i != j) {
                if (dist[i][j] > h[i])
                    h[i] = dist[i][j];
                if (dist[i][j] > od)
                    od = dist[i][j];
            }
        }
    }

    int a, b;
    double d1 = 0, d2 = 0, d3 = 0, nd = MAX, tmp;
    for (int i = 0; i < cn; i++) {
        for (int j = i + 1; j < cn; j++) {
            for (int k1 = 1; k1 <= c[i][0]; k1++) {
                a = c[i][k1];
                for (int k2 = 1; k2 <= c[j][0]; k2++) {
                    b = c[j][k2];
                    d1 = h[a], d2 = h[b];
                    d3 = comp_dist(p[a], p[b]);
                    tmp = d1 + d2 + d3;
                    if (tmp < nd)
                        nd = tmp;
                }
            }
        }
    }

    printf("%.6f\n", nd < od ? od : nd);

    return 0;
}