/*
ID: luyangk1
PROG: packrec
LANG: C++
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
//#include <cctype>

//#include <iostream>

//#include <fstream>
#include <set>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class hw_pair {
public:
    int h, w;
    hw_pair() : h(0), w(0) {};
    hw_pair(int height, int width) : h(height), w(width) {};
    bool operator<(const hw_pair &p) const {
        return this->h < p.h;}
};

hw_pair rec[4][2];
set<hw_pair> ans;

bool next_state(int *s, int n, int b) {
    bool is_max = true;
    for (int i = 0; i < n; i++) {
        if (s[i] != b - 1) {
            is_max = false;
            break;
        }
    }

    if (is_max)
        return false;

    int d = 0;
    for (int i = 0; i < n; i++) {
        d += s[i] * pow(b, i);
    }
    d++;

    for (int i = 0; i < n; i++) {
        s[i] = d % b;
        d /= b;
    }

    return true;
}

void validate(int height, int width) {
    int tmp = height;
    if (height > width) {
        tmp = height;
        height = width;
        width = tmp;
    }
    
    int min = ans.begin()->h * ans.begin()->w;

    int area = height * width;
    if (area == min) {
        ans.insert(hw_pair(height, width));
    } else if (area < min) {
        ans.clear();
        ans.insert(hw_pair(height, width));
    }
}

int main(int argc, char* argv[]) {
    freopen("packrec.in", "r", stdin);
    freopen("packrec.out", "w", stdout);

    ans.insert(hw_pair(0x7fffffff, 1));

    for (int i = 0; i < 4; i++) {
        int l, w;
        scanf("%d %d", &l, &w);
        rec[i][0] = hw_pair(l, w);
        rec[i][1] = hw_pair(w, l);
    }

    int seq[4] = {0, 1, 2, 3};
    int s[4] = {0, 0, 0, 0};
    do {
        memset(s, 0, sizeof(int) * 4);
        do {
            int height = 0, width = 0; 
            
            /* layout 1 */
            height = max(max(rec[seq[0]][s[0]].h, rec[seq[1]][s[1]].h), 
                max(rec[seq[2]][s[2]].h, rec[seq[3]][s[3]].h));
            width = rec[seq[0]][s[0]].w + rec[seq[1]][s[1]].w +
                rec[seq[2]][s[2]].w + rec[seq[3]][s[3]].w;
            validate(height, width);

            /* layout 2 */
            height = max(max(rec[seq[0]][s[0]].h, rec[seq[1]][s[1]].h), 
                rec[seq[2]][s[2]].h) + rec[seq[3]][s[3]].h;
            width = max(rec[seq[0]][s[0]].w + rec[seq[1]][s[1]].w + 
                rec[seq[2]][s[2]].w, rec[seq[3]][s[3]].w);
            validate(height, width);

            /* layout 3 */
            height = max(max(rec[seq[0]][s[0]].h, rec[seq[1]][s[1]].h) + 
                rec[seq[2]][s[2]].h, rec[seq[3]][s[3]].h);
            width = max(rec[seq[0]][s[0]].w + rec[seq[1]][s[1]].w, 
                rec[seq[2]][s[2]].w) + rec[seq[3]][s[3]].w;
            validate(height, width);

            /* layout 4 */
            height = max(rec[seq[0]][s[0]].h, max(rec[seq[1]][s[1]].h + 
                rec[seq[2]][s[2]].h, rec[seq[3]][s[3]].h));
            width = rec[seq[0]][s[0]].w + max(rec[seq[1]][s[1]].w, 
                rec[seq[2]][s[2]].w) + rec[seq[3]][s[3]].w;
            validate(height, width);

            /* layout 5 */
            /*length = ;
            width = ;
            validate(length, width);*/

            /* layout 6 */
            height = max(rec[seq[0]][s[0]].h + rec[seq[1]][s[1]].h, 
                rec[seq[2]][s[2]].h + rec[seq[3]][s[3]].h);
            if (rec[seq[1]][s[1]].h >= rec[seq[3]][s[3]].h && 
                (rec[seq[0]][s[0]].w > rec[seq[1]][s[1]].w || 
                rec[seq[2]][s[2]].w < rec[seq[3]][s[3]].w)) {
                width = max(rec[seq[0]][s[0]].w + rec[seq[2]][s[2]].w, 
                    rec[seq[1]][s[1]].w + rec[seq[3]][s[3]].w);
            } else {
                width = max(rec[seq[0]][s[0]].w, rec[seq[1]][s[1]].w) + 
                    max(rec[seq[2]][s[2]].w, rec[seq[3]][s[3]].w);
            }
            validate(height, width);
        } while (next_state(s, 4, 2));
    } while (next_permutation(seq, seq + 4));

    printf("%d\n", ans.begin()->h * ans.begin()->w);
    for (set<hw_pair>::iterator iter = ans.begin(); iter != ans.end();
        iter++) {
        printf("%d %d\n", iter->h, iter->w);
    }

    return 0;
}