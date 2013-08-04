/*
ID: luyangk1
PROG: transform
LANG: C++
*/

//#include <iostream>
//#include <fstream>
#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int n;
char before[12][12], after[12][12], trans[12][12];

void rotate_90(int n, char trans[][12], char before[][12]) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			trans[j][n - 1 - i] = before[i][j];
}

void rotate_180(int n, char trans[][12], char before[][12]) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			trans[n - 1 - i][n - 1 - j] = before[i][j];
}

void rotate_270(int n, char trans[][12], char before[][12]) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			trans[n - 1 - j][i] = before[i][j];
}

void reflect(int n, char trans[][12], char before[][12]) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			trans[i][n - 1 -j] = before[i][j];
}

void combine(int n, char trans[][12], char before[][12], int type) {
	reflect(n, trans, before);

	char tmp[12][12];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			tmp[i][j] = trans[i][j];

	switch (type) {
		case 1: 
			rotate_90(n, trans, tmp);
			break;
		case 2: 
			rotate_180(n, trans, tmp);
			break;
		case 3: 
			rotate_270(n, trans, tmp);
			break;
		default:
			break;
	}
}

int valid(int n, char trans[][12], char after[][12]) {
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			if (trans[i][j] != after[i][j]) 
				return 0;
	return 1;
}

int main(int argc, char* argv[]) {
	freopen("transform.in", "r", stdin);
	freopen("transform.out", "w", stdout);

	//ifstream fin("beads.in");
	//ofstream fout("beads.out");

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", before + i);
	}

	for (int i = 0; i < n; i++) {
		scanf("%s", after + i);
	}

	rotate_90(n, trans, before);
	if (valid(n, trans, after)) {
		printf("1\n");
		return 0;
	}

	rotate_180(n, trans, before);
	if (valid(n, trans, after)) {
		printf("2\n");
		return 0;
	}

	rotate_270(n, trans, before);
	if (valid(n, trans, after)) {
		printf("3\n");
		return 0;
	}

	reflect(n, trans, before);
	if (valid(n, trans, after)) {
		printf("4\n");
		return 0;
	}

	for (int i = 1; i <= 3; i++) {
		combine(n, trans, before, i);
		if (valid(n, trans, after)) {
			printf("5\n");
			return 0;
		}
	}

	if (valid(n, before, after)) 
		printf("6\n");
	else
		printf("7\n");

	return 0;
}