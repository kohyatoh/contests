#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
int cross(int x0, int y0, int x1, int y1) { return x0*y1-x1*y0; }

struct P {
    int i, j, p;
    P(int i, int j, int p) : i(i), j(j), p(p) {}
};
bool operator<(const P& l, const P& r) {
    const int c = cross(l.i, l.j, r.i, r.j);
    return c!=0 ? c<0 : l.p<r.p;
}

int H, W;
char f[1024][1024];

int kount(int i, int j) {
    int c = 0;
    rep(a, 2) rep(b, 2) if(f[i+a][j+b]=='#') c++;
    return c;
}

int main() {
    memset(f, '.', sizeof(f));
    scanf("%d%d", &H, &W);
    rep(i, H) rep(j, W) scanf(" %c", f[H-i]+j+1);
    vector<P> v;
    rep(i, H+1) rep(j, W+1) if(i || j) {
        const int c = kount(i, j);
        if(c==1) {
            if(f[i+1][j]=='#') v.push_back(P(i, j, 1));
            if(f[i][j+1]=='#') v.push_back(P(i, j, -1));
        }
        else if(c==2) {
            if(f[i+1][j]=='#' && f[i][j+1]=='#') {
                v.push_back(P(i, j, 1));
                v.push_back(P(i, j, -1));
            }
        }
        else if(c==3) {
            if(f[i+1][j]=='.') v.push_back(P(i, j, 1));
            if(f[i][j+1]=='.') v.push_back(P(i, j, -1));
        }
    }
    sort(v.begin(), v.end());
    int cur = 1;
    int ans = cur;
    rep(i, v.size()) {
        cur += v[i].p;
        ans = max(ans, cur);
    }
    printf("%d\n", ans);
    return 0;
}

