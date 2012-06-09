#include <stdio.h>
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

int main() {
    int T;
    cin >> T;
    rep (_q, T) {
        cin >> M >> F >> N;
        rep (i, N) cin >> P[i] >> S[i];
        vector<pair<Int, Int> > v;
        rep (i, N) v.push_back(mp(P[i], S[i]));
        sort(v.begin(), v.end());
        Int ans = 0;
        for (int k = 1; k*F < M; k++) {
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
            ans = max(ans, ta);
        }
        cout << "Case #" << _q+1 << ": " << ans << endl;
    }
    return 0;
}
