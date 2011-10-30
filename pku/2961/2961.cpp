#include <stdio.h>
#include <iostream>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
typedef long long Int;

Int ox, oy;
int f[32][32];

void rec(Int n, Int x, Int y, Int w, Int h, Int p, Int q, int s) {
    if(x>=n || x+w<=0 || y>=n || y+h<=0) return ;
    if(n==1) f[p-ox][q-oy] = s;
    else {
        const Int k = n/2;
        rec(k, x, y, w, h, p, q, s);
        rec(k, x-k, y, w, h, p+k, q, s);
        rec(k, x, y-k, w, h, p, q+k, s);
        rec(k, x-k, y-k, w, h, p+k, q+k, -s);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        Int n, x, y, w, h;
        cin >> n >> x >> y >> w >> h;
        ox = x, oy = y;
        rec(n, x, y, w, h, 0, 0, 1);
        rep(i, h) rep(j, w) printf("%d%c", f[j][i], j<w-1 ? ' ' : '\n');
        puts("");
    }
    return 0;
}
