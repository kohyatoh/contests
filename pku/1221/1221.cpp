#include <stdio.h>
#include <iostream>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
typedef long long Int;

Int memo[1024][1024];

Int f(int n, int z) {
    if(n==0) return 1;
    if(memo[n][z]) return memo[n][z]-1;
    Int ans = 0;
    if(n>=z) ans++;
    for(int k=z; k+k<=n; k++) ans += f(n-k-k, k);
    memo[n][z] = ans+1;
    return ans;
}

int main() {
    for(;;) {
        int n;
        scanf("%d", &n);
        if(n==0) return 0;
        cout << n << ' ' << f(n, 1) << endl;
    }
    return 0;
}
