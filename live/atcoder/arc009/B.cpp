#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair

int n, of[16];
string ss[1000];

int dec(string s) {
    int a = 0;
    rep (i, s.size()) a = a*10 + of[s[i]-'0'];
    return a;
}

int main() {
    rep (i, 10) {
        int b;
        cin >> b;
        of[b] = i;
    }
    cin >> n;
    vector<pair<int, int> > v;
    rep (i, n) {
        cin >> ss[i];
        v.push_back(mp(dec(ss[i]), i));
    }
    sort(v.begin(), v.end());
    rep (i, n) cout << ss[v[i].second] << endl;
    return 0;
}

