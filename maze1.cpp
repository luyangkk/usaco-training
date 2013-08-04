/*
ID: luyangk1
PROG: maze1
LANG: C++
*/

#include <stdio.h>
#include <deque>
#include <algorithm>

using namespace std;

int w, h, W, H, e[2][2], c, min_c[256][128];
char m[256][128], f[256][128];
int d[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

class step_t {
public:
    int x, y, c;

    step_t() {

    }

    step_t(const step_t &in) {
        x = in.x;
        y = in.y;
        c = in.c;
    }

    step_t(int x, int y, int c) {
        this->x = x;
        this->y = y;
        this->c = c;
    }
};

deque<step_t> q;

void bfs(int x, int y) {
    q.clear();
    q.push_back(step_t(x, y, 1));
    f[x][y] = 1;

    step_t cur;
    while (!q.empty()) {
        cur = q.front();
        q.pop_front();

		x = cur.x;
		y = cur.y;
        if (cur.c < min_c[x][y]) {
            min_c[x][y] = cur.c;
        }

        for (int i = 0; i < 4; i++) {
            x = cur.x + d[i][0];
            y = cur.y + d[i][1];
            c = cur.c + 1;

            if (m[x][y] == '|' || m[x][y] == '-' ||
                    f[x + d[i][0]][y + d[i][1]] == 1) {
                continue;
            }

            q.push_back(step_t(x + d[i][0], y + d[i][1], c));
            f[x + d[i][0]][y + d[i][1]] = 1;
        }
    }
}

int main(int argc, char *argv[]) {
    freopen("maze1.in", "r", stdin);
    freopen("maze1.out", "w", stdout);

    scanf("%d %d", &w, &h);
    W = 2 * w + 1;
    H = 2 * h + 1;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            min_c[i][j] = 0x7fffffff;
        }
    }

    int k = 0;
    for (int i = 0; i < H; i++) {
        getchar();
        for (int j = 0; j < W; j++) {
            scanf("%c", &m[i][j]);
            if (i == 0 && m[i][j] == ' ') {
               e[k][0] = i + 1, e[k++][1] = j;
               m[i][j] = '|';
            } else if (i == H - 1 && m[i][j] == ' ') {
               e[k][0] = i - 1, e[k++][1] = j;
               m[i][j] = '|';
            } else if (j == 0 && m[i][j] == ' ') {
               e[k][0] = i, e[k++][1] = j + 1;
               m[i][j] = '|';
            } else if (j == W - 1 && m[i][j] == ' ') {
               e[k][0] = i, e[k++][1] = j - 1;
               m[i][j] = '|';
            }
        }
    }

    bfs(e[0][0], e[0][1]);

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            f[i][j] = 0;
        }
    }

    bfs(e[1][0], e[1][1]);

    int res = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (min_c[i][j] != 0x7fffffff && min_c[i][j] > res)
                res = min_c[i][j];
        }
    }

    printf("%d\n", res);

    return 0;
}