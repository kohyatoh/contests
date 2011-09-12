#include <stdio.h>

char dat[7][10] = { "", "BFPV", "CGJKQSXZ", "DT", "L", "MN", "R" };
char tbl[128], w[128];

int main() {
    for(int i=1; i<7; i++) for(char *p=dat[i]; *p; p++) tbl[*p]=i+'0';
    while(gets(w)) {
        char pre=0;
        for(char *p=w; *p; p++) {
            if(tbl[*p] && tbl[*p]!=pre) putchar(tbl[*p]);
            pre = tbl[*p];
        }
        putchar('\n');
    }
    return 0;
}
