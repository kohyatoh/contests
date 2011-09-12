#include <stdio.h>
#include <limits.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

struct RMQ {
    static const int N=50000, B=250, C=N/B+(N%B>0);
    int dat[N], buc[C];
    void init(int *v) {
        rep(i, N) dat[i]=v[i];
        rep(i, C) buc[i]=INT_MAX;
        rep(i, N) buc[i/B]=min(buc[i/B], dat[i]);
    }
    int query(int a, int b) {
        int r=INT_MAX;
        while(a<b && a%B) r=min(r, dat[a++]);
        while(a<b && b%B) r=min(r, dat[--b]);
        for(; a<b; a+=B) r=min(r, buc[a/B]);
        return r;
    }
};

int n, q, h[50000];
RMQ mn, mx;

int main() {
    scanf("%d%d", &n, &q);
    rep(i, n) scanf("%d", h+i);
    mn.init(h);
    rep(i, n) h[i]=-h[i];
    mx.init(h);
    rep(i, q) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        printf("%d\n", -mx.query(a, b)-mn.query(a, b));
    }
    return 0;
}

