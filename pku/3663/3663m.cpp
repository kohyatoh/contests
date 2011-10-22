#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int a[30000];

int main() {
    int N, S;
    scanf("%d%d", &N, &S);
    rep(i, N) scanf("%d", a+i);
    sort(a, a+N);
    int ans = 0;
    for(int i=0, j=N-1; i<j; i++) {
        while(j>i && a[i]+a[j]>S) j--;
        if(j>i) ans += j-i;
    }
    printf("%d\n", ans);
    return 0;
}
