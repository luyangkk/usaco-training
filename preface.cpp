/*
ID: luyangk1
PROG: preface
LANG: C++
*/

//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <cmath>
//#include <cctype>

#include <iostream>
#include <fstream>
//#include <set>
#include <string>
#include <sstream>
#include <map>
//#include <deque>
//#include <vector>
//#include <algorithm>
//#include <functional>

using namespace std;

string r[][10] = 
        {{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},  /* 1- 9 */
         {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},  /* 10 - 90 */
         {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},  /* 100 - 900 */
         {"", "M", "MM", "MMM"}}; /* 1000 - 3000 */

int main(int argc, char* argv[]) {
    //freopen("preface.in", "r", stdin);
    //freopen("preface.out", "w", stdout);

    ifstream fin("preface.in");
    ofstream fout("preface.out");

    int n;
    fin >> n;

    char m[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    map<char, int> c;
    for (int i = 0; i < 7; i++)
        c[m[i]] = 0;

    char t[64];
    string s;
    for (int i = 1; i <= n; i++) {
        sprintf(t, "%d", i);
        string s(t);
        int l = s.length();
        for (int i = 0; i < l; i++) {
            int k = s[i] - '0';
            string &rs = r[l - i - 1][k];
            for (string::iterator iter = rs.begin(); 
                iter != rs.end(); iter++) c[*iter]++;
        }
    }

    for (int i = 0; i < 7; i++) {
        if (c[m[i]] != 0) {
            fout << m[i] << ' ' << c[m[i]] << '\n';
        }
    }

    return 0;
}