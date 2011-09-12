#include <stdio.h>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

#define N (60000)
int n, k[N], a[N], p[N], l[N], r[N];
pair<int, int> v[N];

int main() {
    scanf("%d", &n);
    rep(i, n) scanf("%d%d", k+i, a+i);
    rep(i, n) v[i].first=a[i], v[i].second=i;
    sort(v, v+n);
    map<int, int> bs;
    const int rix=v[0].second;
    bs[k[rix]] = bs[1<<30] = rix;
    p[rix] = l[rix] = r[rix] = -1;
    for(int i=1; i<n; i++) {
        const int ix=v[i].second;
        map<int, int>::iterator it=bs.lower_bound(k[ix]);
        const int pix=it->second;
        p[ix] = pix;
        l[ix] = r[ix] = -1;
        if(k[ix]<k[pix]) l[pix] = ix;
        else r[pix] = ix;
        bs[k[ix]] = it->second = ix;
    }
    puts("YES");
    rep(i, n) printf("%d %d %d\n", p[i]+1, l[i]+1, r[i]+1);
    return 0;
}

