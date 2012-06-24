#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int inv[26];

bool ok(const string& t) {
    if (t.find("that") != string::npos) return true;
    if (t.find("this") != string::npos) return true;
    return false;
}

string decode(const string& s) {
    rep (a, 26) if (a % 2 != 0 && a % 13 != 0) {
        rep (b, 26) {
            string t(s);
            rep (i, s.size()) if (islower(s[i])) {
                t[i] = 'a' + (s[i]-'a'+b)*inv[a] % 26;
            }
            if (ok(t)) return t;
        }
    }
    return "";
}

int main() {
    rep (i, 26) {
        int k = 1;
        rep (_, 11) k = (k*i)%26;
        inv[i] = k;
    }
    string s;
    getline(cin, s);
    int T = atoi(s.c_str());
    while (T--) {
        getline(cin, s);
        if (s.size() && s[s.size()-1] == '\r') s.resize(s.size()-1);
        cout << decode(s) << endl;
    }
    return 0;
}
