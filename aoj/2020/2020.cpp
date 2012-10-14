#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

bool aiu(char ch) {
    return ch == 'a' || ch == 'i' || ch == 'u' || ch == 'e' || ch == 'o';
}

vector<string> parse(const string& s) {
    vector<string> v;
    int pos = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (aiu(s[i]) || s[i] == 'n' || s[i] == '\'') {
            if (pos != i) v.push_back(s.substr(pos, i-pos));
            v.push_back(s.substr(i, 1));
            pos = i+1;
        }
    }
    if (pos < (int)s.size()) v.push_back(s.substr(pos));
    return v;
}

bool musei(const string& s) {
    char c = s[0];
    return c == 'k' || c == 's' || c == 't' || c == 'h' || c == 'p';
}

bool hatsu(const string& s) {
    return s.size() >= 2 && s[0] == s[1];
}

bool rule1(const vector<string>& ns, int ix) {
    if (ns[ix] != "i" && ns[ix] != "u") return false;
    return ix > 0 && musei(ns[ix-1]) &&
        (ix == (int)ns.size()-1 || musei(ns[ix+1]));
}

bool rule2(const vector<string>& ns, int ix) {
    if (ns[ix] != "a" && ns[ix] != "o" && ns[ix] != "u") return false;
    if (ix + 2 >= (int)ns.size()) return false;
    if (ns[ix] != ns[ix+2]) return false;
    return ix > 0 && musei(ns[ix-1]) && musei(ns[ix+1]) && !hatsu(ns[ix+1]);
}

int main() {
    for (;;) {
        string s;
        cin >> s;
        if (s == "#") return 0;
        vector<string> ns = parse(s);
        const int n = ns.size();
        vector<bool> is(n);
        rep (i, n) if (aiu(ns[i][0])) {
            if (rule1(ns, i)) is[i] = true;
            if (rule2(ns, i)) is[i] = true;
        }
        bool pre = false;
        rep (i, n) if (aiu(ns[i][0])) {
            if (pre) is[i] = false;
            pre = is[i];
        }
        rep (i, n) {
            if (is[i]) printf("(%s)", ns[i].c_str());
            else printf("%s", ns[i].c_str());
        }
        printf("\n");
    }
}
