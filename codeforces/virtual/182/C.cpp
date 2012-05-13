#include <stdio.h>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF (1LL<<60)
typedef long long Int;

int n, len, a[200000], k;
Int sum, nsum;
multiset<int> as, bs;

void add(int v) {
    if (k == 0) return ;
    if ((int)as.size() < k) {
        as.insert(v);
        nsum += v;
    }
    else {
        set<int>::iterator it = as.end();
        --it;
        if (v >= *it) bs.insert(v);
        else {
            const int u = *it;
            as.erase(it);
            as.insert(v);
            bs.insert(u);
            nsum += v;
            nsum -= u;
        }
    }
}

void rem(int v) {
    if (k == 0) return ;
    if (bs.count(v)) {
        bs.erase(bs.find(v));
    }
    else {
        as.erase(as.find(v));
        nsum -= v;
        if (bs.size()) {
            nsum += *bs.begin();
            as.insert(*bs.begin());
            bs.erase(bs.begin());
        }
    }
}

int main() {
    scanf("%d%d", &n, &len);
    rep (i, n) scanf("%d", a+i);
    scanf("%d", &k);
    Int ans = -INF;
    rep (d, 2) {
        sum = nsum = 0;
        as.clear(); bs.clear();
        rep (i, len) {
            sum += a[i];
            if (a[i] < 0) add(a[i]);
        }
        ans = max(ans, sum-2*nsum);
        for (int i = len; i < n; i++) {
            sum += a[i];
            if (a[i] < 0) add(a[i]);
            sum -= a[i-len];
            if (a[i-len] < 0) rem(a[i-len]);
            ans = max(ans, sum-2*nsum);
        }
        rep (i, n) a[i] *= -1;
    }
    cout << ans << endl;
    return 0;
}
