#include <stdio.h>
#include <iostream>
using namespace std;
typedef long long Int;

Int f(int m, int s, int e) {
    if (s > e) return 0;
    int c = 1 + (e-s) / m;
    return (Int)c * (s+s+m*(c-1)) / 2;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        int n, m;
        scanf("%d%d", &n, &m);
        const Int a = f(m, m-1, n);
        const Int b = f(m, 2*n+1-(2*n+1)/m*m, n-1);
        const Int g = m%2 ? 1 : 2;
        const Int c = 2*n / (2LL*m/g);
        printf("%lld\n", (a+b-c) / 2);
    }
    return 0;
}
