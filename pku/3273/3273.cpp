#include <stdio.h>
#include <algorithm>
#include <numeric>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, m, a[100000];

bool can(int w) {
    int s=w, c=0;
    rep(i, n) {
        if(s+a[i]>w) {
            s = 0;
            if(++c>m) return false;
        }
        s += a[i];
    }
    return true;
}

int main() {
    scanf("%d%d", &n, &m);
    rep(i, n) scanf("%d", a+i);
    int l=*max_element(a, a+n)-1, r=accumulate(a, a+n, 0);
    while(r-l>1) {
        int mid = (l+r)/2;
        if(can(mid)) r=mid; else l=mid;
    }
    printf("%d\n", r);
    return 0;
}
