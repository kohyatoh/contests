#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef unsigned long long Int;

int cnt[64];

vector<int> f(Int x) {
    if (x <= 3) {
        vector<int> a;
        if (x <= 1) a.push_back(x);
        else {
            a.push_back(x==3);
            a.push_back(x==3);
        }
        return a;
    }
    vector<int> a;
    for (Int p = x; p; p /= 2) a.push_back(p%2);
    const int n = a.size();
    vector<int> cnt(n);
    cnt[0] = cnt[1] = 1;
    if (x % 2 == 0) rep (i, n) if (a[i]) cnt[n-1-i]++;
    if (a[1]) cnt[n-1]++;
    if (a[0]) cnt[n-1]++;
    return cnt;
}

Int solve(Int a, Int b) {
    vector<int> x = f(a-1), y = f(b);
    const int n = max(x.size(), y.size());
    x.resize(n);
    y.resize(n);
    Int ans = 0;
    rep (i, n) if ((x[i]+y[i])%2) ans |= 1LL<<(n-1-i);
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    rep (_q, T) {
        Int a, b;
        cin >> a >> b;
        cout << "Case " << _q+1 << ": " << solve(a, b) << endl;
    }
    return 0;
}
