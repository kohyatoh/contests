#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
#define foreach(it, c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#ifdef DEBUGRUN
#define LOG(a) (cerr<<__LINE__<<": "#a" = "<<(a)<<endl)
#define ASS(a) (assert(a))
#else
#define LOG(a) ((void)0)
#define ASS(a) ((void)0)
#endif

#define INF (1<<30)
int n, a[100], of[100], dp[2][100];

int main() {
    scanf("%d", &n);
    rep(i, n) scanf("%d", a+i);
    rep(i, n) of[i]=a[i];
    sort(of, of+n);
    int m=unique(of, of+n)-of;
    rep(i, m) LOG(of[i]);
    int *cur=dp[0], *nxt=dp[1];
    rep(i, m) cur[i]=abs(a[0]-of[i]);
    rep(i, n-1) {
        rep(j, m) nxt[j]=INF;
        rep(j, m) rep(k, m) {
            nxt[j] = min(nxt[j], cur[k]+abs(of[k]-of[j])+abs(a[i+1]-of[j]));
        }
        swap(cur, nxt);
    }
    int ans=INF;
    rep(i, m) ans=min(ans, cur[i]);
    printf("%d\n", ans);
    return 0;
}


