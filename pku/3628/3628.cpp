#include <stdio.h>
#include <limits.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int N, B, a[40];

int rec(int i, int s) {
    if(i==N) return s>=B ? s-B : INT_MAX;
    return min(rec(i+1, s), rec(i+1, s+a[i]));
}

int main() {
    scanf("%d%d", &N, &B);
    rep(i, N) scanf("%d", a+i);
    printf("%d\n", rec(0, 0));
    return 0;
}

