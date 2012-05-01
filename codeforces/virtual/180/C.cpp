#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int cnt[200000], Cnt[200000];

int main() {
    string s;
    cin >> s;
    const int n = s.size();
    rep (i, n) cnt[i+1] = cnt[i] + (s[i] >= 'a');
    for (int i = n-1; i >= 0; i--) Cnt[i] = Cnt[i+1] + (s[i] <= 'Z');
    int ans = n;
    rep (i, n+1) {
        const int m = cnt[i] + Cnt[i];
        if (ans > m) ans = m;
    }
    printf("%d\n", ans);
    return 0;
}

