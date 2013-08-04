/*
ID: luyangk1
PROG: dualpal
LANG: C++
*/

#include <stdio.h>

int n, s;
int a[1024];

bool foo(int x, int b) {
	int l = 0;

	while (true) {
		a[l++] = x % b;
		if (x / b == 0) 
			break;

		x = (x - a[l - 1]) / b;
	}

	int j = l / 2;
	for (int i = 0; i < j; i++) {
		if (a[i] != a[l - i - 1])
			return false;
	}
	
	return true;
}

int main(int argc, char* argv[]) {
	freopen("dualpal.in", "r", stdin);
	freopen("dualpal.out", "w", stdout);

	scanf("%d %d", &n, &s);

	int c = 0, k = 0;
	for (int i = s + 1; i <= 0x7fffffff; i++) {
		if (c == n) 
			break;

		k = 0;
		for (int j = 2; j <= 10 && k < 2; j++) {
			if (foo(i, j)) {
				k++;
			}
		}

		if (k == 2) {
			printf("%d\n", i);
			c++;
		}
	}

	return 0;
}