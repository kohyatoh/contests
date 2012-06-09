#include <stdio.h>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair

int N, L[1024], P[1024];

int main() {
    int T;
    scanf("%d", &T);
    rep (_q, T) {
        scanf("%d", &N);
        rep (i, N) scanf("%d", L+i);
        rep (i, N) scanf("%d", P+i);
        vector<pair<double, int> > v;
        rep (i, N) {
            const double p = P[i]/100.0;
            if (p == 0) v.push_back(mp(1e100, i));
            else v.push_back(mp(L[i]/p, i));
        }
        sort(v.begin(), v.end());
        printf("Case #%d:", _q+1);
        rep (i, N) printf(" %d", v[i].second);
        printf("\n");
    }
    return 0;
}
