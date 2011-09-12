#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int a[20], b[20];

int f(bool k) {
    int ans = 0;
    rep(i, 20) b[i] = a[i];
    if(k) {
        rep(i, 2) b[i] = 1-b[i];
        ans++;
    }
    rep(i, 18) if(b[i]) {
        rep(j, 3) b[i+j] = 1-b[i+j];
        ans++;
    }
    if(b[18]) {
        rep(i, 2) b[18+i] = 1-b[18+i];
        ans++;
    }
    rep(i, 20) if(b[i]) return 100;
    return ans;
}

int main() {
    rep(i, 20) scanf("%d", a+i);
    printf("%d\n", min(f(true), f(false)));
    return 0;
}
