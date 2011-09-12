#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int T, x, y;
long long s[100000];

int main() {
    rep(i, 100000) s[i+1]=s[i]+i/2+1;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &x, &y);
        printf("%d\n", lower_bound(s, s+100000, y-x)-s);
    }
}

