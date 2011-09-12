#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int T;
char b[80];

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%s", b);
        unsigned a=0;
        rep(i, 32) a=a*2+(b[i]-'0');
        printf("%u.%u.%u.%u\n", a>>24, (a>>16)%256, (a>>8)%256, a%256);
    }
    return 0;
}

