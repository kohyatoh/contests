#include <stdio.h>
#include <vector>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, ans;
vector<int> g[128], ansv;

void rec(const vector<int>& v) {
    int c = 0;
    rep(i, n) if(v[i]!=1) c++;
    if(c<=ans) return ;
    rep(i, n) if(v[i]==-1) {
        vector<int> nv(v);
        nv[i] = 0;
        bool ok = true;
        rep(j, g[i].size()) {
            const int t = g[i][j];
            if(nv[t]==0) { ok = false; break; }
            else nv[t] = 1;
        }
        if(ok) rec(nv);
        nv = v;
        nv[i] = 1;
        rec(nv);
        return ;
    }
    if(ans<c) ans=c, ansv=v;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        rep(i, 128) g[i].clear();
        int m;
        scanf(" %d%d", &n, &m);
        rep(_, m) {
            int u, v;
            scanf("%d%d", &u, &v);
            u--, v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        ans = -1;
        ansv.clear();
        rec(vector<int>(n, -1));
        printf("%d\n", ans);
        bool first = true;
        rep(i, n) if(ansv[i]==0) {
            if(!first) putchar(' ');
            first = false;
            printf("%d", i+1);
        }
        putchar('\n');
    }
    return 0;
}
