#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <assert.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <numeric>
#include <algorithm>
#include <functional>
#include <complex>
using namespace std;
#ifdef DEBUGRUN
#define LOG(a) (cerr<<__LINE__<<": "#a" = "<<(a)<<endl)
#define ASS(a) (assert(a))
#define DBG(...) (fprintf(stderr,"%d: ",__LINE__)+fprintf(stderr,__VA_ARGS__))
#else
#define LOG(...) ((void)0)
#define ASS(...) ((void)0)
#define DBG(...) ((void)0)
#endif
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
#define foreach(it, c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
typedef long long Int;
#define INF (1<<28)

int n, m, g[15][15], cnt[15], dp[1<<15];

int main() {
    for(;;) {
        scanf("%d", &n);
        if(n==0) return 0;
        rep(i, n) rep(j, n) g[i][j]=INF;
        memset(cnt, 0, sizeof(cnt));
        scanf("%d", &m);
        int s = 0;
        rep(i, m) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            a--, b--;
            g[a][b] = min(g[a][b], c);
            g[b][a] = min(g[b][a], c);
            cnt[a]++;
            cnt[b]++;
            s += c;
        }
        rep(k, n) rep(i, n) rep(j, n) g[i][j]=min(g[i][j], g[i][k]+g[k][j]);
        int base=0;
        rep(i, n) if(cnt[i]%2==0) base|=1<<i;
        vector<pair<int, int> > v;
        rep(i, n) if(cnt[i]%2) rep(j, i) if(cnt[j]%2) {
            v.push_back(mp((1<<i)|(1<<j), g[i][j]));
        }
        const int nn=1<<n;
        rep(i, nn) dp[i]=INF;
        dp[base] = s;
        rep(b, nn) if(dp[b]!=INF) {
            rep(i, v.size()) if((b&v[i].first)==0) {
                const int nb=b|v[i].first;
                dp[nb] = min(dp[nb], dp[b]+v[i].second);
            }
        }
        printf("%d\n", dp[nn-1]);
    }
    return 0;
}


