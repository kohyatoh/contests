#include <stdio.h>
#include <iostream>
#include <sstream>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
    string s;
    getline(cin, s);
    rep (i, s.size()) if (s[i] == '.' || s[i] == ',') s[i] = ' ';
    istringstream sin(s);
    bool f = false;
    string w;
    while (sin >> w) if (w.size() >= 3 && w.size() <= 6) {
        if (f) cout << ' ';
        f = true;
        cout << w;
    }
    cout << endl;
    return 0;
}
