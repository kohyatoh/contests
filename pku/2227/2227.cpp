#include <stdio.h>
#include <iostream>
#include <set>
#include <utility>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

int w, h, b[500][500], used[500][500];
long long ans;
set<pair<int, pair<int, int> > > S;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void rec(int cx, int cy, int level) {
    if(b[cx][cy]>level) {
        S.insert(mp(b[cx][cy], mp(cx, cy)));
    }
    else {
        if(used[cx][cy]) return;
        used[cx][cy] = 1;
        ans += level-b[cx][cy];
        rep(d, 4) {
            int nx=cx+dx[d], ny=cy+dy[d];
            if(0<=nx && nx<w && 0<=ny && ny<h) rec(nx, ny, level);
        }
    }
}

int main() {
    scanf("%d%d", &w, &h);
    rep(i, h) rep(j, w) scanf("%d", b[j+1]+i+1);
    w+=2; h+=2;
    S.insert(mp(b[0][0], mp(0, 0)));
    while(!S.empty()) {
        pair<int, pair<int, int> > v=*S.begin();
        S.erase(S.begin());
        rec(v.second.first, v.second.second, v.first);
    }
    cout << ans << endl;
    return 0;
}
