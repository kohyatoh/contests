#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <complex>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
typedef complex<double> P;
#define INF (1<<28)

int L, N, x[20000], r[20000];

int solve() {
    vector<pair<int, int> > vs;
    rep(i, N) vs.push_back(mp(x[i]-r[i], x[i]+r[i]));
    sort(vs.begin(), vs.end());
    int pos = 0, ix = 0, u = 0;
    while(pos<L && ix<N) {
        int npos = -1;
        while(ix<N && vs[ix].first<=pos) {
            npos = max(npos, vs[ix].second);
            ix++;
        }
        if(npos==-1) return -1;
        pos = npos;
        u++;
    }
    return pos>=L ? N-u : -1;
}

int main() {
    for(;;) {
        scanf("%d%d", &L, &N);
        if(L==0 && N==0) return 0;
        rep(i, N) scanf("%d%d", x+i, r+i);
        printf("%d\n", solve());
    }
}

