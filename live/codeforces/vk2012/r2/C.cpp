#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
using namespace std;
#ifdef DEBUGRUN
#define LOG(a) (cerr<<__LINE__<<": "#a" = "<<(a)<<endl)
#else
#define LOG(...) ((void)0)
#endif
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
#define foreach(it, c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
typedef long long Int;
#define INF (MY_INFINITY)
#define MOD (1000000007)
#define EPS (1e-12)
inline void add(int &a, Int b) { a = (a+b) % MOD; }

int N, L, _v1, _v2;
double v1, v2;
int a[200000];
vector<Int> xs, cnt, sum;
vector<double> ts;
double ans[200000];

double adjust(double t, double T) {
    if (fabs(t) < EPS) return 0;
    if (t < EPS) t += T*(floor((-t)/T));
    while (t < EPS) t += T;
    if (t >= T-EPS) t -= T*floor(t/T);
    if (fabs(t) < EPS) return 0;
    LOG(t);
    LOG(T);
    return t;
}

int main() {
    scanf("%d%d%d%d", &N, &L, &_v1, &_v2);
    rep (i, N) scanf("%d", a+i);
    v1 = _v1, v2 = _v2;

    rep (i, N) xs.push_back(a[i]);
    xs.push_back(0);
    xs.push_back(2LL*L);
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    cnt = vector<Int>(xs.size());
    rep (i, N) {
        const int ix = lower_bound(xs.begin(), xs.end(), a[i])-xs.begin();
        cnt[ix]++;
    }
    sum = vector<Int>(cnt.size()+1);
    rep (i, cnt.size()) sum[i+1] = sum[i] + cnt[i];

    const double T = (2.0*L) / v1;
    LOG(T);
    rep (i, N) {
        const double t1 = (2.0*L-a[i]) / v1;
        LOG(t1);
        ts.push_back(adjust(t1, T));
        const double t2 = (3.0*L-a[i]) / v1 - L / (v1+v2);
        LOG(t2);
        ts.push_back(adjust(t2, T));
    }
    ts.push_back(0.0);
    ts.push_back(T);
    int sz = ts.size();
    rep (i, sz) {
        ts.push_back(adjust(ts[i]+1e-8, T));
        ts.push_back(adjust(ts[i]-1e-8, T));
    }
    sort(ts.begin(), ts.end());
    rep (i, ts.size()-1) {
        LOG(ts[i]);
        double z = v2 * L / (v1+v2);
        const double x1 = adjust(0 - ts[i]*v1, 2.0*L);
        const double x2 = adjust(z - ts[i]*v1, 2.0*L);
        LOG(z);
        int ix = lower_bound(xs.begin(), xs.end(), (Int)x1)-xs.begin();
        while (xs[ix] < x1+EPS) ix++;
        int jx = lower_bound(xs.begin(), xs.end(), (Int)x2)-xs.begin();
        while (xs[jx] < x2+EPS) jx++;
        LOG(x1);
        LOG(x2);
        LOG(ix);
        LOG(jx);
        LOG(sum[ix]);
        LOG(sum[jx]);
        Int c = 0;
        if (x1 <= x2) {
            c += sum[jx] - sum[ix];
        }
        else {
            c += sum.back() - sum[ix];
            c += sum[jx];
        }
        LOG(c);
        assert(c <= N);
        ans[c] += (ts[i+1]-ts[i]) / T;
    }
    rep (i, N+1) printf("%.12f\n", ans[i]);
    return 0;
}
