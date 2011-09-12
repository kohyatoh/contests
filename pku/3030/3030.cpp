#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int r, e, c;
        scanf("%d%d%d", &r, &e, &c);
        e -= c;
        if(r<e) puts("advertise");
        else if(r==e) puts("does not matter");
        else puts("do not advertise");
    }
    return 0;
}
