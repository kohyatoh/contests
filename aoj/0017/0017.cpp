#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

string f(const string& s, int k) {
    string t;
    rep (i, s.size()) {
        if (islower(s[i])) t += (char)((s[i]-'a'+k)%26+'a');
        else t += s[i];
    }
    return t;
}

bool ok(const string& t) {
    if (t.find("the") != string::npos) return true;
    if (t.find("this") != string::npos) return true;
    if (t.find("that") != string::npos) return true;
    return false;
}

int main() {
    string s;
    while (getline(cin, s)) {
        if (s.size() > 0 && s[s.size()-1] == '\r') s.resize(s.size()-1);
        rep (i, 26) {
            const string t = f(s, i);
            if (ok(t)) {
                cout << t << endl;
                break;
            }
        }
    }
    return 0;
}
