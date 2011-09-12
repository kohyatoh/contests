#include <stdio.h>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

struct node { int s, b; node(int s, int b) : s(s), b(b) {} };

int of(char ch) {
    if(ch=='w') return 1;
    if(ch=='b') return 2;
    return 0;
}

const int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1};
const int dy[8] = { 1, 1, 0, -1, -1, -1, 0, 1};
char buf[4][4];
int T, f[6][6];

int main() {
    rep(i, 6) rep(j, 6) f[i][j]=-1;
    scanf("%d", &T);
    set<int> vis;
    while(T--) {
        vis.clear();
        int src=0, dst=0;
        rep(i, 4) rep(j, 4) scanf(" %c", buf[i]+j);
        rep(i, 4) rep(j, 4) src=src*3+of(buf[i][j]);
        rep(i, 4) rep(j, 4) scanf(" %c", buf[i]+j);
        rep(i, 4) rep(j, 4) dst=dst*3+of(buf[i][j]);
        queue<node> q;
        q.push(node(0, src));
        vis.insert(src);
        int ans=-1;
        while(!q.empty()) {
            node v(q.front());
            q.pop();
            if(v.b==dst) { ans=v.s; break; }
            int turn=v.s%2+1, b=v.b;
            rep(i, 4) rep(j, 4) f[i+1][j+1]=b%3, b/=3;
            rep(i, 4) rep(j, 4) if(f[i+1][j+1]==turn) {
                rep(d, 8) {
                    int nx=i+1, ny=j+1;
                    while(f[nx+dx[d]][ny+dy[d]]==0) nx+=dx[d], ny+=dy[d];
                    if(nx!=i+1 || ny!=j+1) {
                        swap(f[nx][ny], f[i+1][j+1]);
                        int nb=0;
                        rep(x, 4) rep(y, 4) nb=nb*3+f[4-x][4-y];
                        swap(f[nx][ny], f[i+1][j+1]);
                        if(nb==dst) { ans=v.s+1; goto end; }
                        if(vis.find(nb)==vis.end()) {
                            q.push(node(v.s+1, nb));
                            vis.insert(nb);
                        }
                    }
                }
            }
        }
end:;
        printf("%d\n", ans);
    }
    return 0;
}
