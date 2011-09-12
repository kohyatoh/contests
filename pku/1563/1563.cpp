#include <stdio.h>

int h, d, u, f;

int main() {
    for(;;) {
        scanf("%d%d%d%d", &h, &u, &d, &f);
        if(h==0) return 0;
        h*=100, d*=100;
        int ch=0, cu=u*100, day=0;
        do {
            day++;
            if(cu>0) ch+=cu;
            cu-=u*f;
            if(ch>h) break;
            ch -= d;
        } while(ch>=0);
        printf("%s on day %d\n", ch>h?"success":"failure", day);
    }
}

