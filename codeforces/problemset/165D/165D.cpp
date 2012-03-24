#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

struct BIT {
    BIT(int n) : n(n), x(n) {}
    int n;
    vector<int> x;
    void add(int k, int a) { for (; k<n; k|=k+1) x[k]+=a; }
    int sum(int k) { int s=0; for (; k>=0; k=(k&(k+1))-1) s+=x[k]; return s; }
    int rsum(int i, int j) { return i==0 ? sum(j) : sum(j)-sum(i-1); }
};
vector<BIT> bits;

#define N (200000)
int n, rt, col[N], h[N];
vector<int> g[N];
int u[N], v[N];

void prepare() {
    rt = 0;
    rep (i, n) if (g[rt].size() < g[i].size()) rt = i;
    rep (k, g[rt].size()) {
        int pre = rt, cur = g[rt][k];
        while (cur != -1) {
            col[cur] = k;
            h[cur] = h[pre]+1;
            int nxt = -1;
            rep (i, g[cur].size()) if (g[cur][i]!=pre) nxt = g[cur][i];
            pre = cur;
            cur = nxt;
        }
        bits.push_back(BIT(h[pre]+1));
    }
}

void modify(int e, int a) {
    const int vx = h[u[e]] > h[v[e]] ? u[e] : v[e];
    bits[col[vx]].add(h[vx], a);
}

int main() {
    scanf("%d", &n);
    rep (i, n-1) {
        scanf("%d%d", u+i, v+i);
        u[i]--, v[i]--;
        g[u[i]].push_back(v[i]);
        g[v[i]].push_back(u[i]);
    }
    prepare();
    int Q;
    scanf("%d", &Q);
    rep (_, Q) {
        int type, a, b;
        scanf("%d %d", &type, &a);
        a--;
        if (type == 1) modify(a, -1);
        else if (type == 2) modify(a, 1);
        else {
            scanf("%d", &b);
            b--;
            if (a == b) printf("%d\n", 0);
            else if (a == rt || b == rt || col[a] == col[b]) {
                const int c = h[a] > h[b] ? col[a] : col[b];
                if (bits[c].sum(h[a]) == bits[c].sum(h[b])) {
                    printf("%d\n", abs(h[a]-h[b]));
                }
                else {
                    printf("%d\n", -1);
                }
            }
            else {
                if (bits[col[a]].sum(h[a]) || bits[col[b]].sum(h[b])) {
                    printf("%d\n", -1);
                }
                else {
                    printf("%d\n", h[a]+h[b]);
                }
            }
        }
    }
    return 0;
}
