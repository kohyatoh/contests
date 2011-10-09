#include <stdio.h>
#include <string.h>
#include <complex>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
typedef complex<double> P;
#define EPS (1e-10)

int N, X1[2000], Y1[2000], X2[2000], Y2[2000];
int u[2000];

int solve() {
    vector<pair<double, int> > vs;
    rep(i, N) {
        const double a1 = arg(P(X1[i], Y1[i]));
        const double a2 = arg(P(X2[i], Y2[i]));
        vs.push_back(mp(min(a1, a2)-EPS, -(i+1)));
        vs.push_back(mp(max(a1, a2)+EPS, i+1));
    }
    sort(vs.begin(), vs.end());
    memset(u, 0, sizeof(u));
    vector<int> s;
    int ans = 0;
    rep(i, vs.size()) {
        if(vs[i].second<0) s.push_back(-vs[i].second-1);
        else if(!u[vs[i].second-1]) {
            rep(j, s.size()) u[s[j]] = 1;
            s.clear();
            ans++;
        }
    }
    return ans;
}

int main() {
    for(;;) {
        scanf("%d", &N);
        if(N==0) return 0;
        rep(i, N) scanf("%d%d%d%d", X1+i, Y1+i, X2+i, Y2+i);
        printf("%d\n", solve());
    }
}



