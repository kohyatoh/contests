#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <algorithm>
#include <utility>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

int n, k, a[20000];
pair<int, int> x[20000];

typedef pair<int, int> T;
int cnt[256], pos[256];
T buf[20000];
void _bsort(T *begin, T *end, int d) {
    memset(cnt, 0, sizeof(cnt));
    for(T *it=begin; it!=end; it++) cnt[(it->first>>d)%256]++;
    pos[0] = 0;
    rep(i, 255) pos[i+1] = pos[i]+cnt[i];
    for(T *it=begin; it!=end; it++) {
        buf[pos[(it->first>>d)%256]++] = *it;
    }
    int ix = 0;
    for(T* it=begin; it!=end; it++) *it = buf[ix++];
}
void radix_sort(T *begin, T *end) {
    rep(i, 4) _bsort(begin, end, i*8);
}

int rec(int l, int r) {
    if(r-l<k) return -1;
    for(int i=l; i<r; i++) {
        const int ix = x[i].second;
        x[i].first = ix<n ? a[ix] : INT_MAX;
        x[i].second += 1;
    }
    radix_sort(x+l, x+r);
    int a=l, b=l, mx=0;
    while(a<r) {
        while(b<r && x[a].first==x[b].first) b++;
        if(x[a].first!=INT_MAX) mx = max(mx, rec(a, b));
        a = b;
    }
    return mx+1;
}

int main() {
    scanf("%d%d", &n, &k);
    rep(i, n) scanf("%d", a+i);
    rep(i, n) x[i] = mp(0, i);
    printf("%d\n", rec(0, n)-1);
    return 0;
}
