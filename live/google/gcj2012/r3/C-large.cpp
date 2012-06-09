#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long Int;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair

int N;
Int F, M, P[256], S[256];
vector<pair<Int, Int> > v;

Int f(Int k) {
    Int r = M-k*F;
    Int z = 0, ta = 0;
    rep (i, N) {
        if (v[i].second+1 < z) continue;
        if (r/v[i].first/k >= v[i].second+1-z) {
            r -= k*v[i].first*(v[i].second+1-z);
            z = max(z, v[i].second+1);
            ta = z * k;
        }
        else {
            const Int q = r/v[i].first;
            ta += q;
            break;
        }
    }
    return ta;
}

int main() {
    srand(time(NULL));
    int T;
    cin >> T;
    rep (_q, T) {
        cin >> M >> F >> N;
        rep (i, N) cin >> P[i] >> S[i];
        v.clear();
        rep (i, N) v.push_back(mp(P[i], S[i]));
        sort(v.begin(), v.end());
        Int l = 1, r = M/F;
        Int ans = 0;
        int qq = 0;
        while (r - l > 100000) {
            qq++;
            Int m1 = (2*l+r)/3, m2 = (l+2*r)/3;
            const Int f1 = f(m1), f2 = f(m2);
            if (f1 < f2) l = m1;
            else if (f1 > f2) r = m2;
            else {
//                cout << "?" << qq << ":" << m1 << "," << m2 << endl;
                rand() % 2 ? (l = m1) : (r = m2);
            }
        }
//        for (Int k = l-10000; k <= r+10000; k++) {
//            if (k >= 1 && k <= M/F) ans = max(ans, f(k));
 //       }
        for (Int k = l; k <= r; k++) ans = max(ans, f(k));
        cout << "Case #" << _q+1 << ": " << ans << endl;
    }
    return 0;
}
