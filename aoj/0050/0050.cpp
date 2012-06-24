#include <stdio.h>
#include <iostream>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const char dat[2][6] = { "apple", "peach" };

string fix(string s) {
    rep (k, s.size()-4) {
        rep (t, 2) {
            bool f = true;
            rep (i, 5) if (s[k+i] != dat[t][i]) f = false;
            if (f) {
                rep (i, 5) s[k+i] = dat[1-t][i];
                break;
            }
        }
    }
    return s;
}

int main() {
    string s;
    while (getline(cin, s)) {
        if (s.size() && s[s.size()-1] == '\r') s.resize(s.size()-1);
        cout << fix(s) << endl;
    }
    return 0;
}
