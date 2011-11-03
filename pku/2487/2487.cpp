#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int M, N, a[2000];

int main() {
    int T;
    scanf("%d", &T);
    rep(_q, T) {
        scanf("%d%d", &M, &N);
        rep(i, N) scanf("%d", a+i);
        sort(a, a+N);
        int s = 0, c = 0;
        while(c<N && s<M) {
            s += a[N-1-c];
            c++;
        }
        printf("Scenario #%d:\n", _q+1);
        if(s<M) puts("impossible");
        else printf("%d\n", c);
        puts("");
    }
    return 0;
}
