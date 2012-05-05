#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef long long Int;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

void println(const vector<Int>& a) {
    rep (i, a.size()) {
        if (i) cout << " ";
        cout << a[i];
    }
    cout << endl;
}

int N;
Int a[512];

void solve() {
    const int nn = 1<<N;
    map<Int, vector<Int> > has;
    rep (b, nn) {
        vector<Int> z;
        Int s = 0;
        rep (i, N) if (b&(1<<i)) {
            s += a[i];
            z.push_back(a[i]);
        }
        if (has.count(s) && has[s] != z) {
            println(has[s]);
            println(z);
            return ;
        }
        else {
            has[s] = z;
        }
    }
    puts("Impossible");
}

int main() {
    int T;
    cin >> T;
    for (int _q = 0; _q < T; _q++) {
        cin >> N;
        rep (i, N) cin >> a[i];
        sort(a, a+N);
        cout << "Case #" << _q+1 << ":" << endl;
        solve();
    }
    return 0;
}
