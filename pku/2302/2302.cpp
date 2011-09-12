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

int T, xof[80], yof[80], xc[5], yc[5], rc[2];

int main() {
    int a;
    scanf("%d", &T);
    while(T--) {
        memset(xof, -1, sizeof(xof));
        memset(yof, -1, sizeof(yof));
        rep(i, 5) rep(j, 5-(i==2)) {
            scanf("%d", &a);
            xof[a] = i;
            yof[a] = i!=2||j<2 ? j : j+1;
        }
        rep(i, 5) xc[i]=i==2;
        rep(i, 5) yc[i]=i==2;
        rc[0]=rc[1]=1;
        int ans=100;
        rep(i, 75) {
            scanf("%d", &a);
            if(xof[a]==-1) continue;
            if(++xc[xof[a]]==5) ans=min(ans, i+1);
            if(++yc[yof[a]]==5) ans=min(ans, i+1);
            if(xof[a]==yof[a] && ++rc[0]==5) ans=min(ans, i+1);
            if(xof[a]==4-yof[a] && ++rc[1]==5) ans=min(ans, i+1);
        }
        printf("BINGO after %d numbers announced\n", ans);
    }
    return 0;
}

