#include <stdio.h>

int T, x, y;

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &x, &y);
        for(int i=0; ; i++) {
            if(1LL*(i/2)*(i/2+1)+(i%2?i/2+1:0)>=y-x) {
                printf("%d\n", i);
                break;
            }
        }
    }
}

