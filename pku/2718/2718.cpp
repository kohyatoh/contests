#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
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
using namespace std;
#ifdef DEBUGRUN
#define LOG(a) (cerr<<__LINE__<<": "#a" = "<<(a)<<endl)
#define DBG(...) (__VA_ARGS__)
#else
#define LOG(...) ((void)0)
#define DBG(...) ((void)0)
#endif
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
#define foreach(it, c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
typedef long long Int;
#define INF (1<<30)
#define MOD (YOUR_MODULUS)

int n, a[10], x[10], y[10];
char buf[100];

int calc(int w, int* x, int h, int *y) {
    if(w==0 || h==0) return INF;
    if(w>1 && x[0]==0) return INF;
    if(h>1 && y[0]==0) return INF;
    int xv=0, yv=0;
    rep(i, w) xv=xv*10+x[i];
    rep(i, h) yv=yv*10+y[i];
    return abs(xv-yv);
}

int main() {
    gets(buf);
    int T = atoi(buf);
    while(T--) {
        gets(buf);
        n = 0;
        for(char *p=buf; *p; p++) if(isdigit(*p)) a[n++]=*p-'0';
        rep(i, n) LOG(a[i]);
        sort(a, a+n);
        int ans = INF;
        if(n%2==0) rep(i, n) rep(j, i) if(n==2 || a[j]!=0) {
            int w=0, h=0;
            x[w++] = a[i];
            y[h++] = a[j];
            rep(k, n) if(k!=i && k!=j) (w<n/2 ? x[w++] : y[h++]) = a[k];
            reverse(y+1, y+h);
            ans = min(ans, calc(w, x, h, y));
        }
        const int nn = 1<<n;
        rep(b, nn) {
            int w=0, h=0;
            rep(i, n) (b&(1<<i) ? x[w++] : y[h++]) = a[i];
            if(w==0 || h==0) continue;
            if(w>h) {
                if(w>1 && x[0]==0) swap(x[0], x[1]);
                reverse(y, y+h);
                ans = min(ans, calc(w, x, h, y));
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}


