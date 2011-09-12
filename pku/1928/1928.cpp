#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

int n, m, k,a[64][64];

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d%d", &n, &m, &k);
        rep(i, n) rep(j, m) scanf("%d", a[i]+j);
        vector<pair<int, pair<int, int> > > v;
        rep(i, n) rep(j, m) v.push_back(mp(a[i][j], mp(i, j)));
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        int ans=0, t=0, pi=-1, pj=v[0].second.second;
        rep(i, v.size()) {
            t += abs(v[i].second.first-pi) + abs(v[i].second.second-pj) + 1;
            pi = v[i].second.first;
            pj = v[i].second.second;
            if(t+v[i].second.first+1>k) break;
            ans += v[i].first;
        }
        printf("%d\n", ans);
    }
    return 0;
}
