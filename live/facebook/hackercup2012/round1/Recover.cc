#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
typedef long long Int;

string src;
int ix;
vector<string> ts;
int a[100000];

void complete(int n) {
    if (n == 1) return ;
    const int m = n / 2;
    complete(m);
    complete(n-m);
    int a = 0, b = 0;
    string t;
    while (a < m && b < n-m) {
        if (src[ix++] == '1') a++, t+='1';
        else b++, t+='2';
    }
    while (a < m) a++, t+='1';
    while (b < n-m) b++, t+='2';
    ts.push_back(t);
}

void recover(int* a, int n) {
    if (n == 1) return ;
    const int m = n / 2;
    const string t = ts.back();
    ts.pop_back();
    assert((int)t.size() == n);
    vector<int> bs;
    rep (i, n) bs.push_back(a[i]);
    int *p = a, *q = a+m;
    rep (i, n) {
        if (t[i] == '1') *p++ = bs[i];
        else *q++ = bs[i];
    }
    assert(p == a+m && q == a+n);
    recover(a+m, n-m);
    recover(a, m);
}

int solve(int n, string s) {
    src = s;
    ix = 0;
    ts.clear();
    rep (i, n) a[i] = i+1;
    complete(n);
    assert(ix == (int)s.size());
    recover(a, n);
    assert(ts.size() == 0);
//    rep (i, n) cerr << a[i] << endl;
    Int result = 1;
    rep (i, n) result = (31 * result + a[i]) % 1000003;
    return result;
}

int main() {
    int T;
    cin >> T;
    rep (t, T) {
        int n;
        string s;
        cin >> n >> s;
        const int ans = solve(n, s);
        cout << "Case #" << t+1 << ": " << ans << endl;
    }
    return 0;
}

