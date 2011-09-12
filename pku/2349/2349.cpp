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
#else
#define LOG(a) ((void)0)
#define ASS(a) ((void)0)
#endif
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
#define foreach(it, c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

struct unionset {
    int ud[500];
    void init() { memset(ud, -1, sizeof(ud)); }
    int root(int x) { return ud[x]<0 ? x : ud[x]=root(ud[x]); }
    int size(int x) { return -ud[root(x)]; }
    bool same(int x, int y) { return root(x)==root(y); }
    bool set(int x, int y) {
        x=root(x); y=root(y);
        if(x!=y) {
            if(ud[y]<ud[x]) std::swap(x, y);
            ud[x]+=ud[y]; ud[y]=x;
        }
        return x!=y;
    }
} us;

int sq(int a) { return a*a; }

int T, s, n, x[500], y[500], m;
pair<int, pair<int, int> > v[250000];

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &s, &n);
        rep(i, n) scanf("%d%d", x+i, y+i);
        m = 0;
        rep(i, n) rep(j, i) {
            v[m].first = sq(x[i]-x[j])+sq(y[i]-y[j]);
            v[m].second = mp(i, j);
            m++;
        }
        sort(v, v+m);
        us.init();
        int k=0;
        rep(i, m) if(us.set(v[i].second.first, v[i].second.second)) {
            LOG(v[i].first);
            k++;
            if(k+s==n) {
                printf("%.2f\n", sqrt((double)v[i].first));
                break;
            }
        }
    }
    return 0;
}


