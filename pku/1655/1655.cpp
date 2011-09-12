#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, p[30000], cnt[30000];
vector<int> g[30000];

int visit(int at, int pre) {
    p[at] = pre;
    cnt[at] = 1;
    rep(i, g[at].size()) if(g[at][i]!=p[at]) {
        cnt[at] += visit(g[at][i], at);
    }
    return cnt[at];
}

int calc(int at) {
    int ans = 0;
    rep(i, g[at].size()) if(g[at][i]!=p[at]) {
        ans = max(ans, cnt[g[at][i]]);
    }
    ans = max(ans, n-cnt[at]);
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        memset(cnt, 0, sizeof(cnt));
        rep(i, 30000) g[i].clear();
        rep(_, n-1) {
            int a, b;
            scanf("%d%d", &a, &b);
            a--, b--;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        visit(0, -1);
        int ans=1<<30, ansi=-1;
        rep(i, n) {
            const int t = calc(i);
            if(ans>t) ans=t, ansi=i;
        }
        printf("%d %d\n", ansi+1, ans);
    }
    return 0;
}
