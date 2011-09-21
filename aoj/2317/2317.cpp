#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
typedef long long Int;

int of[200000];

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    vector<pair<int, int> > v[2];
    rep(i, N) {
        int s, t;
        scanf("%d%d", &s, &t);
        v[s<t].push_back(mp(s, i+1));
        v[s<t].push_back(mp(t, -(i+1)));
    }
    rep(_, M) {
        int p;
        scanf("%d", &p);
        rep(k, 2) v[k].push_back(mp(p, 0));
    }
    rep(k, 2) sort(v[k].begin(), v[k].end());
    reverse(v[0].begin(), v[0].end());
    Int ans = 0;
    rep(k, 2) {
        int nc=0, cc=0, pc=0;
        rep(i, v[k].size()) {
            if(i>0) ans += (Int)nc*abs(v[k][i].first-v[k][i-1].first);
            if(v[k][i].second==0) {
                pc++;
                swap(nc, cc);
            }
            else if(v[k][i].second>0) {
                const int ix = v[k][i].second-1;
                nc++;
                of[ix] = pc;
            }
            else {
                const int ix = -v[k][i].second-1;
                if((pc-of[ix])%2==0) nc--;
                else cc--;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
