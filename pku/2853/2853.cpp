#include <stdio.h>
typedef long long Int;

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int q, n;
        scanf("%d%d", &q, &n);
        int ans = 0;
        for(int i=2; (Int)i*(i+1)/2<=n; i++) {
            if(i%2==1) ans += n%i==0;
            else ans += n%(i/2)==0 && (n/(i/2))%2==1;
        }
        printf("%d %d\n", q, ans);
    }
    return 0;
}
