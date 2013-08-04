/*
ID: luyangk1
PROG: namenum
LANG: C++
*/

//#include <iostream>
//#include <fstream>
//#include <vector>
//#include <utility>
//#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <set>

using namespace std;

char num[30], a[30];
int l;
char *m[] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PRS", "TUV", "WXY"};
int c[30] = {0};
set<string> s;
int is_find = 0;

void search(int k, int j) {
	if (k >= 0) 
		c[k] = j;

	if (k == l - 1) {
		for (int i = 0; i < l; i++)
			a[i] = m[num[i] - '0'][c[i]];
		a[l] = '\0';

		if (s.find(a) != s.end()) {
			printf("%s\n", a);
			if (!is_find)
				is_find = true;
		}
		return;
	}

	for (int i = 0; i < 3; i++)
		search(k + 1, i);
}

int main(int argc, char* argv[]) {
	freopen("namenum.in", "r", stdin);
	freopen("namenum.out", "w", stdout);

	//ifstream fin("namenum.in");
	//ofstream fout("namenum.out");

	char name[30];
	FILE *fp = fopen("dict.txt", "r");
	while (fscanf(fp, "%s", name) != EOF) {
		s.insert(name);
	}
	fclose(fp);

	scanf("%s", num);
	l = strlen(num);
	search(-1, 0);
	if (!is_find)
		printf("NONE\n");

	return 0;
}