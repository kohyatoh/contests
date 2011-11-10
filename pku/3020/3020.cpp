#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

struct BiMatching {
    int w, h, m;
    vector<int> head, to, next;

    int cvis;
    vector<int> mat, vis;

    BiMatching(int _w, int _h) : w(_w), h(_h), m(0), head(_w+_h, -1) {}
    void add(int s, int t) {
        t += w;
        to.push_back(t);
        next.push_back(head[s]);
        head[s] = m;
        m++;
    }
    bool rec(int at) {
        if(at<0) return true;
        for(int x=head[at]; x!=-1; x=next[x]) if(vis[to[x]]!=cvis) {
            vis[to[x]] = cvis;
            if(rec(mat[to[x]])) {
                mat[at] = to[x];
                mat[to[x]] = at;
                return true;
            }
        }
        return false;
    }
    int match() {
        mat = vector<int>(w+h, -1);
        vis = vector<int>(w+h, -1);
        int r = 0;
        rep(i, w) {
            cvis = i;
            if(rec(i)) r++;
        }
        return r;
    }
};

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int h, w, of[64][64];
char f[64][64];

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &h, &w);
        memset(f, 'o', sizeof(f));
        rep(i, h) rep(j, w) scanf(" %c", f[i+1]+j+1);
        int n = 0, m = 0;
        rep(i, h) rep(j, w) if(f[i+1][j+1]=='*') {
            if((i+j)%2) of[i+1][j+1] = n++;
            else of[i+1][j+1] = m++;
        }
        BiMatching bm(n, m);
        rep(i, h) rep(j, w) if(f[i+1][j+1]=='*') {
            rep(d, 4) {
                const int nx = i+1+dx[d], ny = j+1+dy[d];
                if(f[nx][ny]=='*') {
                    if((i+j)%2) bm.add(of[i+1][j+1], of[nx][ny]);
                    else bm.add(of[nx][ny], of[i+1][j+1]);
                }
            }
        }
        printf("%d\n", n+m-bm.match());
    }
    return 0;
}
