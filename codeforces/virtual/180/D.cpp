#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int cnt[32];

bool ok() {
    rep (i, 32) if (cnt[i] < 0) return false;
    return true;
}

int main() {
    string s, t;
    cin >> s >> t;
    rep (i, s.size()) cnt[s[i]-'a']++;
    const int m = min(s.size(), t.size());
    rep (i, m) cnt[t[i]-'a']--;
    string ans;
    if (ok() && s.size() > t.size()) {
        ans = t.substr(0, m);
        rep (i, 32) while (cnt[i]--) ans += (char)(i+'a');
    }
    else {
        for (int k = m-1; k >= 0; k--) {
            cnt[t[k]-'a']++;
            if (!ok()) continue;
            int ix = -1;
            for (int i = 31; i > t[k]-'a'; i--) if (cnt[i]) ix = i;
            if (ix != -1) {
                ans = t.substr(0, k);
                cnt[ix]--;
                ans += (char)(ix+'a');
                rep (i, 32) while (cnt[i]--) ans += (char)(i+'a');
                break;
            }
        }
        if (ans.size() == 0) ans = "-1";
    }
    cout << ans << endl;
    return 0;
}
