#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <complex>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
inline double sq(double a) { return a*a; }

int N, M, C;
int u[2000], v[2000], w[2000], next[2000], head[200];
int dp[200][1024];

int main() {
    for(;;) {
        scanf("%d%d%d", &N, &M, &C);
        if(N==0) return 0;
        memset(head, -1, sizeof(head));
        rep(i, M) {
            scanf("%d%d%d", u+i, v+i, w+i);
            u[i]--, v[i]--;
            next[i] = head[u[i]];
            head[u[i]] = i;
        }
        typedef pair<int, int> node;
        priority_queue<pair<int, node> > q;
        memset(dp, -1, sizeof(dp));
        q.push(mp(0, mp(0, 0)));
        while(!q.empty()) {
            pair<int, node> vv(q.top());
            q.pop();
            const int cw = -vv.first;
            if(cw>C) break;
            const int cat = vv.second.first;
            const int cdel = vv.second.second;
            if(dp[cat][cdel]!=-1) continue;
            dp[cat][cdel] = cw;
            for(int x=head[cat]; x!=-1; x=next[x]) {
                if(cdel<M) q.push(mp(-cw, mp(v[x], cdel+1)));
                if(dp[v[x]][cdel]==-1) q.push(mp(-cw-w[x], mp(v[x], cdel)));
            }
        }
        rep(i, M+1) if(dp[N-1][i]!=-1 && dp[N-1][i]<=C) {
            printf("%d\n", i);
            break;
        }
    }
}


