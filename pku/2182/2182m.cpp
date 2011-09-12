#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int N, v[10000], ans[10000];

int nn, x[10000];
void add(int k, int a) { for(; k<nn; k|=k+1) x[k]+=a; }

int find(int k) {
    int l=0, r=nn, m, s=0;
    while(r-l>1) {
        m=(l+r)/2;
        if(s+x[m-1]<k) l=m, s+=x[m-1];
        else r=m;
    }
    return l;
}

int main() {
    scanf("%d", &N);
    nn=1;
    while(nn<N) nn*=2;
    v[0]=0;
    rep(i, N-1) scanf("%d", v+i+1);
    rep(i, N) add(i, 1);
    for(int i=N-1; i>=0; i--) {
        ans[i]=find(v[i]+1);
        add(ans[i], -1);
    }
    rep(i, N) printf("%d\n", ans[i]+1);
    return 0;
}
