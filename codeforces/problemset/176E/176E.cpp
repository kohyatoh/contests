#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <utility>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair
typedef long long Int;
#define LOG(x) (cerr << #x ": " << x << endl)

#define NUM (200000)
int N, Q;
vector<pair<int, int> > g[NUM];

int of[NUM]; // org -> ord
int h[NUM], tw[NUM], end[NUM];
Int w[NUM];
vector<int> as[NUM];

struct BIT {
    static const int N = NUM;
    int x[N];
    void add(int k, int a) { for (; k<N; k|=k+1) x[k]+=a; }
    int sum(int k) { int s=0; for (; k>=0; k=(k&(k+1))-1) s+=x[k]; return s; }
    int rsum(int i, int j) { return i==0 ? sum(j) : sum(j)-sum(i-1); }
} bit;

inline int kount(int x) {
    return bit.rsum(x, end[x]-1);
}

int mm;
void rec(int at, int pre) {
    const int cur = mm++;
    of[at] = cur;
    rep (i, g[at].size()) if (g[at][i].first != pre) {
        as[mm].push_back(cur);
        tw[mm] = g[at][i].second;
        rec(g[at][i].first, at);
    }
    end[cur] = mm;
}

void build() {
    mm = 0;
    rec(0, -1);
    for (int i = 1; i < N; i++) h[i] = h[as[i][0]] + 1;
    for (int i = 1; i < N; i++) w[i] = w[as[i][0]] + tw[i];
    for (int i = 1; i < N; i++) {
        int k = 1, ch = 2;
        for (int k = 1, ch = 2; ch <= h[i]; k++, ch*=2) {
            as[i].push_back(as[as[i][k-1]][k-1]);
        }
    }
}

int get(int x, int h) {
    while (h) {
        int k = 0, ch = 1;
        while (ch * 2 <= h) k++, ch*=2;
        x = as[x][k];
        h -= ch;
    }
    return x;
}

int find(int x, int c) {
    if (kount(x) >= c) return x;
    int l = 0, r = h[x];
    while (r-l > 1) {
        const int mid = (l+r) / 2;
        if (kount(get(x, mid)) >= c) r = mid;
        else l = mid;
    }
    return get(x, r);
}

Int sum = 0;
int tr = -1;
set<int> in;

void add(int x) {
    in.insert(x);
    bit.add(x, 1);
    if (in.size() == 1) {
        tr = x;
    }
    else {
        const int y = find(x, 2);
        sum += w[x] - w[y];
        if (x < tr || end[tr] <= x) {
            sum += w[tr] - w[y];
            tr = y;
        }
    }
}

void remove(int x) {
    in.erase(x);
    bit.add(x, -1);
    if (in.size() == 0) {
        tr = -1;
    }
    else {
        const int y = find(x, 1);
        sum -= w[x] - w[y];
        if (y == tr) {
            const int a = *in.begin();
            const int b = find(a, in.size());
            sum -= w[b] - w[tr];
            tr = b;
        }
    }
}

int main() {
    scanf("%d", &N);
    rep (_, N-1) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        a--, b--;
        g[a].push_back(mp(b, c));
        g[b].push_back(mp(a, c));
    }
    build();
    scanf("%d", &Q);
    rep (_, Q) {
        char op;
        scanf(" %c", &op);
        if (op == '?') cout << sum << endl;
        else {
            int x;
            scanf("%d", &x);
            x--;
            if (op == '+') add(of[x]);
            else remove(of[x]);
        }
    }
    return 0;
}
