#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
typedef long long Int;

#define MX (200000)
int N, M, K, L, X[MX], ix[MX], ff[MX], R, xof[MX];
char name[MX][16], fav[MX][16];
string ns[MX];
pair<int, int> v[MX];
Int z[MX];

inline int of(const string& s) { return lower_bound(ns, ns+N, s)-ns; }

bool can(int a) {
    if(N==M || a+R<=K) return true;
    if(a>K) return false;
    const int b = K-a;
    rep(i, M) {
        const int w = ix[i]<=v[b].second ? -v[b].first : -v[b].first+1;
        z[i] = max(0, w-xof[ix[i]]);
    }
    sort(z, z+M);
    return accumulate(z, z+a, 0LL)<=L;
}

int main() {
    for(;;) {
        scanf("%d%d%d%d", &N, &M, &K, &L);
        if(N==0 && M==0 && K==0 && L==0) return 0;
        memset(ff, 0, sizeof(ff));
        rep(i, N) scanf("%s%d", name[i], X+i);
        rep(i, M) scanf("%s", fav[i]);
        rep(i, N) ns[i] = name[i];
        sort(ns, ns+N);
        rep(i, M) ix[i] = of(fav[i]);
        rep(i, M) ff[ix[i]] = 1;
        R = 0;
        rep(i, N) {
            const int x = of(name[i]);
            xof[x] = X[i];
            if(ff[x]==0) v[R++] = mp(-X[i], x);
        }
        sort(v, v+R);
        int l=0, r=min(K, M)+1;
        while(r-l>1) {
            const int mid = (l+r)/2;
            if(can(mid)) l = mid;
            else r = mid;
        }
        printf("%d\n", l);
    }
}

