#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long Int;

string solve(string s, Int kth) {
    const int n = s.size();
    int a[32];
    rep (i, n) a[i] = i;
    string ans(n, 'X');
    kth--;
    rep (k, n) {
        Int r = 1;
        rep (i, n-1-k) r *= i+1;
        int ix = 0;
        while (kth >= r) {
            kth -= r;
            ix++;
        }
        ans[a[ix]] = s[k];
        for (int i = ix; i+1 < n; i++) a[i] = a[i+1];
    }
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    rep (_q, T) {
        string s;
        Int k;
        cin >> s >> k;
        cout << "Case " << _q+1 << ": " << solve(s, k) << endl;
    }
    return 0;
}
