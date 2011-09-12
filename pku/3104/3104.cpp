#include <stdio.h>
#include <algorithm>
#include <functional>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, k, a[200000];

bool can(int t) {
    if(k==0) return false;
    long long z = 0;
    rep(i, n) {
        if(a[i]<=t) break;
        z += (a[i]-t+k-1)/k;
    }
    return z<=t;
}

int main() {
    scanf("%d", &n);
    rep(i, n) scanf("%d", a+i);
    scanf("%d", &k);
    k--;
    sort(a, a+n, greater<int>());
    int l=0, r=a[0];
    while(r-l>1) {
        int mid = (l+r)/2;
        if(can(mid)) r=mid;
        else l=mid;
    }
    printf("%d\n", r);
    return 0;
}
