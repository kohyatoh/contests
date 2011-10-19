#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, a[2000];

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        rep(i, n) scanf("%d", a+i);
        if(n%2) a[n++] = 0;
        sort(a, a+n);
        int x = 0;
        for(int i=0; i<n; i+=2) x ^= a[i+1]-a[i]-1;
        printf("%s will win\n", x ? "Georgia" : "Bob");
    }
    return 0;
}
