#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int val(char c) {
    if (c == 'I') return 1;
    if (c == 'V') return 5;
    if (c == 'X') return 10;
    if (c == 'L') return 50;
    if (c == 'C') return 100;
    if (c == 'D') return 500;
    if (c == 'M') return 1000;
    return 0;
}

int main() {
    string s;
    while (getline(cin, s)) {
        int a = 0;
        rep (i, s.size()) {
            if (i+1 < (int)s.size() && val(s[i]) < val(s[i+1])) a -= val(s[i]);
            else a += val(s[i]);
        }
        printf("%d\n", a);
    }
    return 0;
}
