#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, a[20];

int win() {
    if(n%2) return 1;
    sort(a, a+n);
    rep(i, n/2) if(a[2*i]!=a[2*i+1]) return 1;
    return 0;
}

int main() {
    for(;;) {
        scanf("%d", &n);
        if(n==0) return 0;
        rep(i, n) scanf("%d", a+i);
        printf("%d\n", win());
    }
}
