#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define pb push_back

struct EGraph {
    int n, m;
    vector<int> head, u, v, next;
    EGraph(int _n) : n(_n), m(0), head(_n, -1) {}
    void add(int _u, int _v) {
        u.pb(_u); v.pb(_v); next.pb(head[_u]); head[_u] = m++;
    }
};

int N, T;
EGraph g(0);
vector<int> vis, rank;

bool check(int at, int z) {
    if(at==T) return true;
    if(at==z) return false;
    if(vis[at]) return false;
    vis[at] = 1;
    for(int x=g.head[at]; x!=-1; x=g.next[x]) if(check(g.v[x], z)) return true;
    return false;
}

int main() {
    scanf("%d%d", &N, &T);
    g = EGraph(N);
    int u, v;
    while(scanf("%d%d", &u, &v)!=EOF) g.add(u, v);
    rank = vector<int>(N, -1);
    queue<int> q;
    q.push(0);
    rank[0] = 0;
    while(!q.empty()) {
        const int at = q.front();
        q.pop();
        for(int x=g.head[at]; x!=-1; x=g.next[x]) {
            const int v = g.v[x];
            if(rank[v]==-1) {
                rank[v] = rank[at]+1;
                q.push(v);
            }
        }
    }
    int ansi = -1, ansr = -1;
    rep(i, N) {
        vis = vector<int>(N);
        if(check(0, i)==false && rank[i]>ansr) ansi = i, ansr = rank[i];
    }
    printf("Put guards in room %d.\n", ansi);
    return 0;
}
