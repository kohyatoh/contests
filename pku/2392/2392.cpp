#include <stdio.h>
#include <set>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

struct block { int h, a, c; };
bool operator<(const block& l, const block& r) {
    return l.a!=r.a ? l.a<r.a : l.h!=r.h ? l.h<r.h : l.c<r.c;
}

int n;
block b[400];
int dp[40001];

int main() {
    scanf("%d", &n);
    rep(i, n) scanf("%d%d%d", &b[i].h, &b[i].a, &b[i].c);
    sort(b, b+n);
    dp[0]=1;
    int mh=0;
    rep(i, n) {
        for(int h=mh; h>=0; h--) if(dp[h]) {
            rep(j, b[i].c+1) if(h+b[i].h*j<=b[i].a) {
                dp[h+b[i].h*j]=1;
                mh = max(mh, h+b[i].h*j);
            }
        }
    }
    printf("%d\n", mh);
    return 0;
}

