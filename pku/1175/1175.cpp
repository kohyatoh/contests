#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define INF (1<<28)
#define mp make_pair
#define fst first
#define snd second

const int dx[8] = {1, 1, 1, 0, -1, -1, -1, 0};
const int dy[8] = {1, 0, -1, -1, -1, 0, 1, 1};

typedef vector<pair<int, int> > Poly;

Poly uni(Poly ps) {
    int mx = INF, my = INF;
    rep(i, ps.size()) {
        mx = min(mx, ps[i].fst);
        my = min(my, ps[i].snd);
    }
    rep(i, ps.size()) ps[i] = mp(ps[i].fst-mx, ps[i].snd-my);
    sort(ps.begin(), ps.end());
    return ps;
}

Poly rot(Poly ps) {
    int mx = 0;
    rep(i, ps.size()) mx = max(mx, ps[i].fst);
    rep(i, ps.size()) ps[i] = mp(ps[i].snd, mx-ps[i].fst);
    return uni(ps);
}

Poly rev(Poly ps) {
    int mx = 0;
    rep(i, ps.size()) mx = max(mx, ps[i].fst);
    rep(i, ps.size()) ps[i] = mp(mx-ps[i].fst, ps[i].snd);
    return uni(ps);
}

int N, M;
char f[128][128];

void rec(int x, int y, Poly& ps) {
    if(f[x][y]!='1') return ;
    f[x][y] = '#';
    ps.push_back(mp(x, y));
    rep(d, 8) rec(x+dx[d], y+dy[d], ps);
}

int main() {
    scanf("%d%d", &M, &N);
    rep(i, N) rep(j, M) scanf(" %c", f[i+1]+j+1);
    map<Poly, char> of;
    char nxt = 'a';
    rep(i, N) rep(j, M) if(f[i+1][j+1]=='1') {
        Poly rs;
        rec(i+1, j+1, rs);
        Poly ps = uni(rs);
        char ch = nxt;
        bool found = false;
        rep(i, 8) {
            ps = rot(ps);
            if(i%4==0) ps = rev(ps);
            if(of.count(ps)) {
                ch = of[ps];
                found = true;
                break;
            }
        }
        if(!found) of[ps] = nxt++;
        rep(k, rs.size()) f[rs[k].first][rs[k].second] = ch;
    }
    rep(i, N) {
        rep(j, M) putchar(f[i+1][j+1]);
        putchar('\n');
    }
}
