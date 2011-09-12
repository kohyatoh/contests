#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <assert.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <numeric>
#include <algorithm>
#include <functional>
#include <complex>
using namespace std;
#ifdef DEBUGRUN
#define LOG(a) (cerr<<__LINE__<<": "#a" = "<<(a)<<endl)
#define ASS(a) (assert(a))
#define DBG(...) (fprintf(stderr,"%d: ",__LINE__)+fprintf(stderr,__VA_ARGS__))
#else
#define LOG(...) ((void)0)
#define ASS(...) ((void)0)
#define DBG(...) ((void)0)
#endif
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
#define foreach(it, c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

struct TopologicalGraph {
    static const int n=1000, m=5000;
    int E, u[m], v[m], head[n], next[m];
    void init() { E=0; memset(head, -1, sizeof(head)); }
    void add_edge(int s, int t) {
        u[E]=s; v[E]=t; next[E]=head[s]; head[s]=E; E++;
    }
    int color[n];
    vector<int> order;
    bool ts_visit(int cur) {
        color[cur] = 1;
        for(int x=head[cur]; x!=-1; x=next[x]) {
            if(color[v[x]]==2) continue;
            if(color[v[x]]==1 || !ts_visit(v[x])) return false;
        }
        color[cur] = 2;
        order.push_back(cur);
        return true;
    }
    bool sort(int n) {
        order.clear();
        memset(color, 0, sizeof(color));
        rep(i, n) if(!color[i] && !ts_visit(i)) return false;
        reverse(order.begin(), order.end());
        return true;
    }
} tg;

int n;

int main() {
    tg.init();
    scanf("%d", &n);
    rep(i, n) {
        for(;;) {
            int a;
            scanf("%d", &a);
            if(a==0) break;
            tg.add_edge(i, a-1);
        }
    }
    tg.sort(n);
    rep(i, n) printf("%d%c", tg.order[i]+1, i<n-1 ? ' ' : '\n');
    return 0;
}


