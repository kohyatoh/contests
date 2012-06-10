#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <utility>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair

#define A1 (500)
#define A2 (10000)

int N;
string a[512];

string norma(const string a) {
    const size_t dot = a.find('.');
    string p1 = a.substr(0, dot);
    string p2 = a.substr(dot+1);
    const size_t p = p2.find('(');
    if (p != string::npos) {
        string b = p2.substr(0, p);
        string re = p2.substr(p+1);
        re.resize(re.size()-1);
        int i = 0;
        while (b.size() < A2) {
            b += re[i++];
            i %= re.size();
        }
        p2 = b;
    }
    return string(A1-p1.size(), '0') + p1 + p2 + string(A2-p2.size(), '0');
}

bool same(const string& a, const string& b) {
    if (a == b) return true;
    string r = a;
    int c = 1;
    for (int i = (int)r.size()-1; i >= 0; i--) {
        int v = r[i]-'0' + c;
        c = 0;
        if (v >= 10) v -= 10, c = 1;
        r[i] = '0' + v;
    }
    return r == b;
}

int main() {
    cin >> N;
    rep (i, N) cin >> a[i];
    rep (i, N) a[i] = norma(a[i]);
//    rep (i, N) cout << a[i] << endl;
    sort(a, a+N);
    int ans = 1;
    rep (i, N-1) if (!same(a[i], a[i+1])) ans++;
    printf("%d\n", ans);
    return 0;
}
