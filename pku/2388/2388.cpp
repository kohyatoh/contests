#include <stdio.h>
#include <algorithm>
#define rep(i, n) for(int i=0; i<n; i++)

int n, v[20000];

int main() {
    scanf("%d", &n);
    rep(i, n) scanf("%d", v+i);
    std::nth_element(v, v+n/2, v+n);
    printf("%d\n", v[n/2]);
    return 0;
}

