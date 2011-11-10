#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

string itos(int a) {
    string r;
    do {
        r += (char)('0'+a%10);
        a /= 10;
    } while(a);
    reverse(r.begin(), r.end());
    return r;
}

int f(const string& s) {
    int a = 32;
    rep(i, s.size()-1) a = min(a, abs(s[i]-s[i+1]));
    return a;
}

int main() {
    string s;
    while(getline(cin, s)) {
        pair<int, string> ans(-f(s), s);
        string r(s);
        rep(_, 10) {
            prev_permutation(r.begin(), r.end());
            ans = min(ans, mp(-f(r), r));
        }
        r = s;
        rep(_, 10) {
            next_permutation(r.begin(), r.end());
            ans = min(ans, mp(-f(r), r));
        }
        string z(ans.second+itos(-ans.first));
        puts(z.c_str());
    }
}
