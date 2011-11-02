#include <stdio.h>
#include <string.h>
#include <queue>
#include <set>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

int bitcount(int b) {
    int c = 0;
    while(b) b &= b-1, c++;
    return c;
}

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
int n, m, f[32][32];

int main() {
    scanf("%d%d", &n, &m);
    memset(f, -1, sizeof(f));
    rep(i, n) rep(j, m) {
        char ch;
        scanf(" %c", &ch);
        f[i+1][j+1] = 1<<(ch-'A');
    }
    int ans = 0;
    typedef pair<int, pair<int, int> > T;
    queue<T> q;
    set<T> vis;
    q.push(T(f[1][1], mp(1, 1)));
    vis.insert(T(f[1][1], mp(1, 1)));
    while(!q.empty()) {
        T vv(q.front());
        q.pop();
        const int b = vv.first;
        const int x = vv.second.first, y = vv.second.second;
        ans = bitcount(b);
        rep(d, 4) {
            const int nx = x+dx[d], ny = y+dy[d];
            if(f[nx][ny]!=-1 && (b&f[nx][ny])==0) {
                T nxt(b|f[nx][ny], mp(nx, ny));
                if(vis.count(nxt)==0) {
                    q.push(nxt);
                    vis.insert(nxt);
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
