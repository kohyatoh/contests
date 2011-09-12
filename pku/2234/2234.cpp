#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int main() {
    int n;
    while(scanf("%d", &n)!=EOF) {
        int a, c=0;
        rep(i, n) {
            scanf("%d", &a);
            c^=a;
        }
        printf("%s\n", c?"Yes":"No");
    }
    return 0;
}

