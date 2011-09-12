#include <stdio.h>

int main() {
    int T, K, a;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &K);
        int ans=1-K;
        while(K--) {
            scanf("%d", &a);
            ans += a;
        }
        printf("%d\n", ans);
    }
    return 0;
}
