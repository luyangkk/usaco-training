/*
ID: luyangk1
PROG: rect1
LANG: C++
*/

#include <cstdio>

int a, b, n, max_color; 
int llx[2505], lly[2505], urx[2505], ury[2505], s[2505], c[2505];

void cover(int lx, int ly, int ux, int uy, int c, int k) {
    while (k <= n && (llx[k] >= ux || urx[k] <= lx || ury[k] <= ly || lly[k] >= uy))
        k++;

    if (k > n) { s[c] += (ux - lx) * (uy - ly); return; }

    if (lx <= llx[k]) { cover(lx, ly, llx[k], uy, c, k + 1); lx = llx[k]; }
    if (ux >= urx[k]) { cover(urx[k], ly, ux, uy, c, k + 1); ux = urx[k]; }
    if (ly <= lly[k]) { cover(lx, ly, ux, lly[k], c, k + 1); ly = lly[k]; }
    if (uy >= ury[k]) { cover(lx, ury[k], ux, uy, c, k + 1); uy = ury[k]; } 
}

int main(int argc, char* argv[]) {
    freopen("rect1.in", "r", stdin);
    freopen("rect1.out", "w", stdout);

    scanf("%d %d %d", &a, &b, &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d %d %d", &llx[i], &lly[i], &urx[i], &ury[i], &c[i]);
		if (c[i] > max_color) max_color = c[i];
    }

    for (int i = 1; i <= n; i++) {
        cover(llx[i], lly[i], urx[i], ury[i], c[i], i + 1);
    }

	s[1] = a * b;
    for (int i = 2; i <= max_color; i++) {
		if (s[i]) s[1] -= s[i];
    }

    for (int i = 1; i <= max_color; i++) {
        if (s[i]) printf("%d %d\n", i, s[i]);
    }

    return 0;
}