#include <stdio.h>

int dx[4] = { 10, 0, -10, 0 };
int dy[4] = { 0, -10, 0, 10 };

char s[1000];

int main() {
    while(gets(s)) {
        printf("%d %d moveto\n", 300, 420);
        printf("%d %d lineto\n", 310, 420);
        int d=0, x=310, y=420;
        for(char *p=s; *p; p++) {
            if(*p=='A') d=(d+1)%4; else d=(d+3)%4;
            x+=dx[d], y+=dy[d];
            printf("%d %d lineto\n", x, y);
        }
        printf("stroke\n");
        printf("showpage\n");
    }
    return 0;
}
