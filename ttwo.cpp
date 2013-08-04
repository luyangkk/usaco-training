/*
ID: luyangk1
PROG: ttwo
LANG: C++
*/

#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <cmath>
//#include <cctype>

//#include <iostream>
//#include <fstream>
//#include <map>
#include <set>
//#include <string>
//#include <sstream>
//#include <deque>
//#include <vector>
//#include <algorithm>
//#include <functional>

using namespace std;

char m[16][16];
int fx, fy, cx, cy, fd, cd, fp, cp, nx, ny;
int d[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int main(int argc, char* argv[]) {
    freopen("ttwo.in", "r", stdin);
    freopen("ttwo.out", "w", stdout);

    //ifstream fin("preface.in");
    //ofstream fout("preface.out");

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            scanf("%c", &m[i][j]);
            if (m[i][j] == 'F') {
                fx = i, fy = j;
            } else if (m[i][j] == 'C') {
                cx = i, cy = j;
            }
        }
        getchar();
    }

    int c = 0;
    while (true) {
        nx = fx + d[fd][0], ny = fy + d[fd][1];
        if (nx < 0 || nx >= 10 || ny < 0 || ny >= 10 || m[nx][ny] == '*') {
            fd = (fd + 1) % 4;
        } else {
            fx = nx, fy = ny;
        }
        fp = fx * 10 + fy;

        nx = cx + d[cd][0], ny = cy + d[cd][1];
        if (nx < 0 || nx >= 10 || ny < 0 || ny >= 10 || m[nx][ny] == '*') {
            cd = (cd + 1) % 4;
        } else {
            cx = nx, cy = ny;
        }
        cp = cx * 10 + cy;

        c++;
        if (fp == cp) 
            break;

        if (c > 400 * 400) {
            break;
        }
    }

    if (fp != cp) {
        c = 0;
    }
    printf("%d\n", c);

    return 0;
}