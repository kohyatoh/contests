#include <stdio.h>
#include <algorithm>
#include <utility>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair
#define fst first
#define snd second
typedef long long Int;

int n;
pair<int, int> ps[30000];

bool check(int cx, int cy) {
    cx *= 2; cy *= 2;
    sort(ps, ps+n);
    for(int i=0, j=n-1; i<=j; i++, j--) {
        if(ps[i].fst+ps[j].fst!=cx || ps[i].snd+ps[j].snd!=cy) return false;
    }
    return true;
}

int main() {
    for(;;) {
        scanf("%d", &n);
        if(n==0) return 0;
        rep(i, n) scanf("%d%d", &ps[i].fst, &ps[i].snd);
        Int xa = 0, ya = 0;
        rep(i, n) {
            ps[i].fst *= 2; xa += ps[i].fst;
            ps[i].snd *= 2; ya += ps[i].snd;
        }
        if(xa%n!=0 || ya%n!=0 || !check(xa/n, ya/n)) {
            puts("This is a dangerous situation!");
        }
        else {
            printf("V.I.P. should stay at (%.1f,%.1f).\n", xa/n/2.0, ya/n/2.0);
        }
    }
}
