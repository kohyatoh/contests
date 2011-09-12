#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, m, u[50], v[50], vis[50];

int dfs(int cur) {
    int ans=0;
    rep(i, m) if((u[i]==cur || v[i]==cur) && vis[i]==0) {
        vis[i] = 1;
        ans = max(ans, dfs(u[i]+v[i]-cur)+1);
        vis[i] = 0;
    }
    return ans;
}

int main() {
    for(;;) {
        scanf("%d%d", &n, &m);
        if(n==0) return 0;
        rep(i, m) scanf("%d%d", u+i, v+i);
        int ans=0;
        rep(i, n) {
            rep(j, m) vis[i]=0;
            ans = max(ans, dfs(i));
        }
        printf("%d\n", ans);
    }
}


