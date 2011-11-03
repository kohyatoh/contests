#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
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
using namespace std;
#ifdef DEBUGRUN
#define LOG(a) (cerr<<__LINE__<<": "#a" = "<<(a)<<endl)
#define DBG(...) (__VA_ARGS__)
#else
#define LOG(...) ((void)0)
#define DBG(...) ((void)0)
#endif
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
#define foreach(it, c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
typedef long long Int;
#define INF (MY_INFINITY)
#define MOD (YOUR_MODULUS)

vector<Int> xs;
int n, m, a[200000], cnt[400][20000], bias[400];

void modify(int k, int d) {
    const int b = k/m;
    cnt[b][a[k]]--;
    a[k] += d;
    cnt[b][a[k]]++;
}

void add(int l, int r, int d) {
    const int lb = l/m, rb = r/m;
    if(lb==rb) {
        for(int k=l; k<=r; k++) modify(k, d);
    }
    else {
        for(int k=lb+1; k<rb; k++) bias[k] += d;
        for(int k=(lb+1)*m-1; k>=l; k--) modify(k, d);
        for(int k=rb*m; k<=r; k++) modify(k, d);
    }
}

int kount(int l, int r) {
    const int lb = l/m, rb = r/m;
    int ans = 0;
    if(lb==rb) {
        for(int k=l; k<=r; k++) {
//            rep(i, xs.size()) if(bias[lb]+a[k]==xs[i]) ans++;
            if(binary_search(xs.begin(), xs.end(), bias[lb]+a[k])) ans++;
        }
    }
    else {
        for(int k=lb+1; k<rb; k++) {
            rep(i, xs.size()) {
                const int t = xs[i]-bias[k];
                if(t>=0 && t<20000) ans += cnt[k][t];
            }
        }
        for(int k=(lb+1)*m-1; k>=l; k--) {
//            rep(i, xs.size()) if(bias[lb]+a[k]==xs[i]) ans++;
            if(binary_search(xs.begin(), xs.end(), bias[lb]+a[k])) ans++;
        }
        for(int k=rb*m; k<=r; k++) {
//            rep(i, xs.size()) if(bias[rb]+a[k]==xs[i]) ans++;
            if(binary_search(xs.begin(), xs.end(), bias[rb]+a[k])) ans++;
        }
    }
    return ans;
}

int main() {
    rep(k, 5) if(k>0) {
        const int kk = 1<<k;
        rep(b, kk) {
            Int a = 0;
            rep(i, k) a = a*10+(b&(1<<i) ? 7 : 4);
            xs.push_back(a);
        }
    }
    sort(xs.begin(), xs.end());
    LOG(xs.size());
    rep(i, xs.size()) LOG(xs[i]);

    int q;
    scanf("%d%d", &n, &q);
    m = max(20, (int)sqrt(n));
//    m = 1;
    rep(i, n) scanf("%d", a+i);
    rep(i, n) cnt[i/m][a[i]]++;
    char op[8];
    int l, r, d;
    rep(_, q) {
        scanf(" %s%d%d", op, &l, &r);
        l--, r--;
        if(op[0]=='a') {
            scanf("%d", &d);
            add(l, r, d);
        }
        else {
            printf("%d\n", kount(l, r));
        }
        rep(i, n) LOG(bias[i]), LOG(a[i]);
    }
    return 0;
}

