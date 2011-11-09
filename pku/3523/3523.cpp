#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

const int dx[5] = {0, 1, 16, -1, -16};
int n, add[128], sub[128];
char f[256], buf[128];
bool vis[2][256*256*256];

inline int of(int s, int i) { return (s>>(i*8))%256; }

int solve(int st, int gl) {
    if(st==gl) return 0;
    int nn = 1, off = 0;
    rep(i, n) {
        nn *= 5;
        off = off*256+17;
    }
    rep(b, nn) {
        int p = b;
        add[b] = sub[b] = 0;
        rep(i, n) {
            const int k = p%5;
            p /= 5;
            add[b] *= 256;
            sub[b] *= 256;
            sub[b] += 17;
            if(dx[k]>=0) add[b] += dx[k];
            else sub[b] += dx[k];
        }
    }
    memset(vis, 0, sizeof(vis));
    vector<int> q[2][2];
    q[0][0].push_back(st);
    vis[0][st] = true;
    q[1][0].push_back(gl);
    vis[1][gl] = true;
    for(int turn=0; ; turn++) {
        const int cur = turn%2, nxt = 1-cur;
        rep(k, 2) {
            rep(ix, q[k][cur].size()) {
                const int at = q[k][cur][ix];
                if(vis[1-k][at]) return k==0 ? turn*2 : turn*2+1;
                rep(b, nn) {
                    const int nx = at+sub[b]-off+add[b];
                    if(vis[k][nx]) continue;
                    rep(i, n) if(f[of(nx, i)]=='#') goto fail;
                    rep(i, n) rep(j, i) if(of(nx, i)==of(nx, j)) goto fail;
                    rep(i, n) rep(j, i) {
                        if(of(nx, i)==of(at, j) && of(nx, j)==of(at, i)) {
                            goto fail;
                        }
                    }
                    vis[k][nx] = true;
                    q[k][nxt].push_back(nx);
fail:;
                }
            }
            q[k][cur].clear();
        }
    }
    return -1;
}

int main() {
    for(;;) {
        int w, h;
        gets(buf);
        sscanf(buf, "%d%d%d", &w, &h, &n);
        if(n==0) return 0;
        memset(f, '#', sizeof(f));
        rep(i, h) {
            gets(buf);
            rep(j, w) f[i*16+j] = buf[j];
        }
        int st=0, gl=0;
        rep(k, n) {
            rep(i, 256) if(f[i]=='a'+k) st=st*256+i;
            rep(i, 256) if(f[i]=='A'+k) gl=gl*256+i;
        }
        printf("%d\n", solve(st, gl));
    }
}
