#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
typedef long long Int;

int c2i(char ch) {
    if(ch=='A') return 0;
    if(ch=='C') return 1;
    if(ch=='G') return 2;
    if(ch=='T') return 3;
    return -1;
}

int cnt[30000];
Int a[30000];

int main() {
    char buf[32];
    for(;;) {
        int n, m;
        scanf("%d%d", &n, &m);
        if(n==0 && m==0) return 0;
        rep(k, n) {
            scanf(" %s", buf);
            Int t = 0;
            rep(i, m) t = t*4+c2i(buf[i]);
            a[k] = t;
        }
        sort(a, a+n);
        a[n] = -1;
        memset(cnt, 0, sizeof(cnt));
        Int pre = -1;
        int c = 0;
        rep(i, n+1) {
            if(a[i]==pre) c++;
            else {
                if(pre!=-1) cnt[c]++;
                pre = a[i];
                c = 0;
            }
        }
        rep(i, n) printf("%d\n", cnt[i]);
    }
}
