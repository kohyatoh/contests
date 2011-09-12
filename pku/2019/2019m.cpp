#include <stdio.h>
#include <limits.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

struct rmq {
    static const int w=256, n=w*w;
    int dat[2*n];
    rmq() { rep(i, 2*n) dat[i]=INT_MAX; }
    int leaf(int x, int y) {
        int cw=w, k=0;
        while(cw>1) {
            if(x<cw/2) {
                if(y<cw/2) k=k*4+1;
                else k=k*4+2, y-=cw/2;
            }
            else {
                x-=cw/2;
                if(y<cw/2) k=k*4+3;
                else k=k*4+4, y-=cw/2;
            }
            cw /= 2;
        }
        return k;
    }
    void update(int x, int y, int a) {
        int k = leaf(x, y);
        dat[k] = a;
        while(k>0) {
            k=(k-1)/4;
            dat[k] = min(min(dat[k*4+1], dat[k*4+2]),
                         min(dat[k*4+3], dat[k*4+4]));
        }
    }
    int _q(int xa, int ya, int xb, int yb,
            int k, int xl, int yl, int xr, int yr) {
        if(xr<=xa || xb<=xl || yr<=ya || yb<=yl) return INT_MAX;
        if(xa<=xl && xr<=xb && ya<=yl && yr<=yb) return dat[k];
        int r1, r2;
        r2 = min(_q(xa, ya, xb, yb, k*4+1, xl, yl, (xl+xr)/2, (yl+yr)/2),
                 _q(xa, ya, xb, yb, k*4+2, xl, (yl+yr)/2, (xl+xr)/2, yr));
        r1 = min(_q(xa, ya, xb, yb, k*4+3, (xl+xr)/2, yl, xr, (yl+yr)/2),
                 _q(xa, ya, xb, yb, k*4+4, (xl+xr)/2, (yl+yr)/2, xr, yr));
        return min(r1, r2);
    }
    int query(int xa, int ya, int xb, int yb) {
        return _q(xa, ya, xb, yb, 0, 0, 0, w, w);
    }
};

int main() {
    int n, b, q, h;
    scanf("%d%d%d", &n, &b, &q);
    rmq mn, mx;
    rep(i, n) rep(j, n) {
        scanf("%d", &h);
        mn.update(i, j, h);
        mx.update(i, j, -h);
    }
    rep(i, q) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--; v--;
        int p=mn.query(u, v, u+b, v+b);
        int q=mx.query(u, v, u+b, v+b);
        printf("%d\n", -(q+p));
    }
    return 0;
}
