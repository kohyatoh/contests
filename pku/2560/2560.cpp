#include <stdio.h>
#include <math.h>
#include <queue>
#include <utility>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

int n, k, vis[100];
double s, x[100], y[100], g[100][100];

int main() {
    scanf("%d", &n);
    rep(i, n) scanf("%lf%lf", x+i, y+i);
    rep(i, n) rep(j, n) g[i][j]=hypot(x[i]-x[j], y[i]-y[j]);
    priority_queue<pair<double, int> > q;
    q.push(mp(0, 0));
    while(k<n) {
        pair<double, int> v=q.top();
        q.pop();
        int cur=v.second;
        if(vis[cur]) continue;
        vis[cur] = 1;
        k++;
        s -= v.first;
        rep(i, n) if(!vis[i]) q.push(mp(-g[cur][i], i));
    }
    printf("%.2f\n", s);
    return 0;
}

