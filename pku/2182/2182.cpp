#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int N, v[10000], ans[10000];

int x[10000];
void add(int k, int a) { for(; k<N; k|=k+1) x[k]+=a; }
int sum(int k) { int s=0; for(; k>=0; k=(k&(k+1))-1) s+=x[k]; return s; }

int calc(int k) {
    int l=0, r=N, m;
    while(r-l>0) {
        m=(l+r)/2;
        if(sum(m)<k) l=m+1;
        else r=m;
    }
    return l;
}

int main() {
    scanf("%d", &N);
    v[0]=0;
    rep(i, N-1) scanf("%d", v+i+1);
    rep(i, N) add(i, 1);
    for(int i=N-1; i>=0; i--) {
        ans[i]=calc(v[i]+1);
        add(ans[i], -1);
    }
    rep(i, N) printf("%d\n", ans[i]+1);
    return 0;
}
