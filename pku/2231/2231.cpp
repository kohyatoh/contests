#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, cows[10000];

int main() {
    scanf("%d", &n);
    rep(i, n) scanf("%d", cows+i);
    sort(cows, cows+n);
    long long ans=0, s=0;
    for(int i=n-1; i>=0; i--) {
        ans+=s-(n-i-1LL)*cows[i];
        s+=cows[i];
    }
    printf("%lld\n", ans*2);
    return 0;
}

