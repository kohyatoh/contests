#include <stdio.h>
#include <iostream>
#include <set>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

int w, h, b[100000], used[100000];
long long ans;
struct MyComp {
    inline bool operator()(int l, int r) { return b[l]!=b[r]?b[l]<b[r]:l<r; }
};
set<int, MyComp> S;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void rec(int ix, int level) {
    used[ix] = 1;
    if(b[ix]>level) S.insert(ix);
    else {
        ans += level-b[ix];
        int cx=ix/h, cy=ix%h;
        rep(d, 4) {
            int nx=cx+dx[d], ny=cy+dy[d], nix=nx*h+ny;
            if(0<=nx && nx<w && 0<=ny && ny<h && !used[nix]) rec(nix, level);
        }
    }
}

int main() {
    scanf("%d%d", &w, &h);
    w+=2; h+=2;
    rep(j, h-2) rep(i, w-2) scanf("%d", b+(i+1)*h+(j+1));
    S.insert(0);
    while(!S.empty()) {
        int ix=*S.begin();
        S.erase(S.begin());
        rec(ix, b[ix]);
    }
    cout << ans << endl;
    return 0;
}
