/*
ID: luyangk1
PROG: beads
LANG: C++
*/

#include <stdio.h>

int n, max = 0;
char beads[1000];
int lr[1000], lb[1000], rr[1000], rb[1000];

int main(int argc, char* argv[]) {
	freopen("beads.in", "r", stdin);
	freopen("beads.out", "w", stdout);

	scanf("%d\n%s", &n, beads + 1);

	for (int i = 1; i <= n; i++) 
		beads[n + i] = beads[i];

	int n2 = n * 2;
	for (int i = 1; i <= n2; i++) {
		char c = beads[i];

		if (c == 'r') 
			lr[i] = lr[i - 1] + 1, lb[i] = 0;
		else if (c == 'b')
			lb[i] = lb[i - 1] + 1, lr[i] = 0;
		else
			lb[i] = lb[i - 1] + 1, lr[i] = lr[i - 1] + 1;

		if (lr[i] > n) lr[i] = n;
		if (lb[i] > n) lb[i] = n;
	}

	for (int i = n2; i > 0; i--) {
		char c = beads[i];

		if (c == 'r') 
			rr[i] = rr[i + 1] + 1, rb[i] = 0;
		else if (c == 'b')
			rb[i] = rb[i + 1] + 1, rr[i] = 0;
		else
			rb[i] = rb[i + 1] + 1, rr[i] = rr[i + 1] + 1;

		if (rr[i] > n) rr[i] = n;
		if (rb[i] > n) rb[i] = n;
	}

	int l1, l2, l, max = 0;
	for (int i = 1; i <= n2; i++) {
		l1 = lr[i] + rb[i + 1];
		l2 = lb[i] + rr[i + 1];

		l = l1 > l2 ? l1 : l2;
		if (l > max) max = l;

		if (max >= n) {
			max = n;
			break;
		}
	}

	printf("%d\n", max);

	return 0;
}