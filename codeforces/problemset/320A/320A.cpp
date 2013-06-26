#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

bool f(const string& s) {
    rep (i, s.size()) if (s[i] != '1' && s[i] != '4') return false;
    if (s[0] != '1') return false;
    int pre = 0;
    rep (i, s.size()) if (s[i] == '1') {
        if (i - pre > 3) return false;
        pre = i;
    }
    return s.size()-pre <= 3;
}

int main() {
    string s;
    cin >> s;
    puts(f(s) ? "YES" : "NO");
    return 0;
}
