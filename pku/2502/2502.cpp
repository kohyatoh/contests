#include <stdio.h>
#include <math.h>
#include <queue>
#include <utility>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

double x[300], y[300], g[300][300];
int n, m, s[300], vis[300];

int main() {
    scanf("%lf%lf%lf%lf", x, y, x+1, y+1);
    s[0]=n=2, m=0;
    while(scanf("%lf%lf", x+n, y+n)!=EOF) {
        n++;
        for(;;) {
            scanf("%lf%lf", x+n, y+n);
            if(x[n]==-1 && y[n]==-1) break;
            n++;
        }
        s[++m] = n;
    }
    rep(i, n) rep(j, i) g[i][j]=g[j][i]=hypot(x[i]-x[j], y[i]-y[j])*60/10000;
    rep(k, m) {
        for(int i=s[k]+1; i<s[k+1]; i++) {
            g[i][i-1]=g[i-1][i]=hypot(x[i]-x[i-1], y[i]-y[i-1])*60/40000;
        }
    }
    priority_queue<pair<double, int> > q;
    q.push(mp(0, 0));
    while(!q.empty()) {
        pair<double, int> v(q.top());
        q.pop();
        int cur=v.second;
        if(vis[cur]) continue;
        vis[cur] = 1;
        if(cur==1) {
            printf("%.0f\n", -v.first);
            break;
        }
        rep(i, n) if(!vis[i]) q.push(mp(v.first-g[cur][i], i));
    }
    return 0;
}
