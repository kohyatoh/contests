#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int a[30000];

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        rep(i, n) scanf("%d", a+i);
        sort(a, a+n);
        reverse(a, a+n);
        int s = 0;
        for(int i=2; i<n; i+=3) s += a[i];
        printf("%d\n", s);
    }
    return 0;
}
