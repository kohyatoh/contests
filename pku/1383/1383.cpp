#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

const int dx[4] = {1024, 1, -1024, -1};

int N, M, mh, mx;
char f[1024*1024], fr;

void rec(int x, int dep) {
    if(mh<dep) mh=dep, mx=x;
    f[x]++;
    if(f[x+dx[0]]==fr) rec(x+dx[0], dep+1);
    if(f[x+dx[1]]==fr) rec(x+dx[1], dep+1);
    if(f[x+dx[2]]==fr) rec(x+dx[2], dep+1);
    if(f[x+dx[3]]==fr) rec(x+dx[3], dep+1);
}

int solve() {
    rep(i, N) rep(j, M) if(f[i*1024+j]=='.') {
        mh = -1; fr = '.';
        rec(i*1024+j, 0);
        mh = -1; fr++;
        rec(mx, 0);
        return mh;
    }
    return -1;
}

int main() {
    gets(f);
    int T;
    sscanf(f, "%d", &T);
    while(T--) {
        gets(f);
        sscanf(f, "%d%d", &M, &N);
        rep(i, N) gets(f+i*1024);
        printf("Maximum rope length is %d.\n", solve());
    }
    return 0;
}
