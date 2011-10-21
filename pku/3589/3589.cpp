#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int main() {
    char a[8], b[8];
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%s%s", a, b);
        int A=0, B=0;
        rep(i, 4) rep(j, 4) if(a[i]==b[j]) {
            if(i==j) A++; else B++;
        }
        printf("%dA%dB\n", A, B);
    }
    return 0;
}
