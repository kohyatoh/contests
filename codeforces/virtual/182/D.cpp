#include <iostream>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

bool div(const string &s, const string& z) {
    if (s.size() % z.size() != 0) return false;
    int ix = 0;
    rep (i, s.size()) {
        if (s[i] != z[ix]) return false;
        ix++;
        if (ix >= (int)z.size()) ix = 0;
    }
    return true;
}

int main() {
    string a, b;
    cin >> a >> b;
    const int n = a.size();
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a.size() % i == 0 && b.size() % i == 0) {
            string s(a.substr(0, i));
            if (div(a, s) && div(b, s)) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
