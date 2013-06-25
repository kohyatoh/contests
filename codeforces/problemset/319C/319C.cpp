#include <stdio.h>
#include <iostream>
#include <deque>
#include <utility>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long Int;
#define mp make_pair
#define fst first
#define snd second

#define N (200000)
int n;
Int a[N], b[N], dp[N];

int main() {
    cin >> n;
    rep (i, n) cin >> a[i];
    rep (i, n) cin >> b[i];
    deque<pair<Int, int> > q;
    q.push_back(mp(-1, 0));
    for (int i = 1; i < n; i++) {
        while (q.size() > 1 && q[1].fst <= a[i]) q.pop_front();
        dp[i] = dp[q[0].snd] + b[q[0].snd] * a[i];
        while (q.size()) {
            const int ix = q.back().snd;
            // A s.t. dp[ix] + b[ix]*A < dp[i] + b[i]*A
            Int A = (dp[i]-dp[ix]) / (b[ix]-b[i]);
            while (dp[ix]+b[ix]*A < dp[i]+b[i]*A) A++;
            if (A <= q.back().fst) q.pop_back();
            else {
                q.push_back(mp(A, i));
                break;
            }
        }
    }
    cout << dp[n-1] << endl;
    return 0;
}
