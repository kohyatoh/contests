#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
typedef long long Int;

int a[1000];

int rec(int at, int c) {
    if(at==0) return a[0]<=c ? a[0] : 0;
    if(a[at]>c) return rec(at-1, c);
    Int s = 0;
    rep(i, at+1) s += a[i];
    if(s<=c) return s;
    return max(rec(at-1, c), rec(at-1, c-a[at])+a[at]);
}

int main() {
    int n, c;
    scanf("%d%d", &n, &c);
    rep(i, n) scanf("%d", a+i);
    printf("%d\n", rec(n-1, c));
    return 0;
}
