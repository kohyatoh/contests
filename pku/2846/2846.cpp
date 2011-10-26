#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

const int md[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int f(int y, int m, int d) {
    int c = 0;
    if(y>0) c += (y-1)*365 + (y-1)/4 - (y-1)/100 + (y-1)/400 + 1;
    rep(i, m-1) {
        c += md[i];
        if(i==1 && y%4==0 && (y%100!=0 || y%400==0)) c++;
    }
    c += d-1;
    return c;
}

void solve(int y, int m, int d, int a, int b) {
    const int ix = f(y, m, d);
    for(int k=y-1; k<=y+1; k++) {
        const int jx = f(k, a, b);
        if(abs(ix-jx)<=7) {
            if(ix==jx) puts("SAME DAY");
            else {
                printf("%d/%d/%d IS %d DAY%s %s\n", a, b, k, abs(ix-jx),
                        abs(ix-jx)!=1 ? "S" : "", ix>jx ? "PRIOR" : "AFTER");
            }
            return ;
        }
    }
    puts("OUT OF RANGE");
}

int main() {
    int T;
    scanf("%d", &T);
    rep(_q, T) {
        int y, m, d, a, b;
        scanf("%d/%d/%d %d/%d", &m, &d, &y, &a, &b);
        printf("%d ", _q+1);
        solve(y, m, d, a, b);
    }
    return 0;
}
