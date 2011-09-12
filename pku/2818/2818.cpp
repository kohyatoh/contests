#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int c[4], n;
int mins, d[4], ans[4];
int a[4] = { 25, 10, 5, 1 };

int main() {
    for(;;) {
        scanf("%d%d%d%d%d", c, c+1, c+2, c+3, &n);
        if(c[0]==0 && c[1]==0 && c[2]==0 && c[3]==0 && n==0) return 0;
        int mins=1000;
        rep(i, c[0]+1) if(25*i<=n) {
            int t=n;
            d[0] = i;
            t -= a[0]*d[0];
            rep(j, 3) {
                d[j+1] = min(c[j+1], t/a[j+1]);
                t -= a[j+1]*d[j+1];
            }
            int s=0;
            rep(j, 4) s+=d[j];
            if(t==0 && mins>s) {
                mins = s;
                rep(j, 4) ans[j] = d[j];
            }
        }
        if(mins==1000) printf("Cannot dispense the desired amount.\n");
        else printf("Dispense %d quarters, %d dimes, %d nickels, and %d pennies.\n", ans[0], ans[1], ans[2], ans[3]);
    }
}
