#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

char r[4][20] = {
    "`1234567890-=",
    "QWERTYUIOP[]\\",
    "ASDFGHJKL;'",
    "ZXCVBNM,./",
};
char tbl[128];

int main() {
    rep(i, 128) tbl[i]=i;
    rep(i, 4) for(char *p=r[i]+1; *p; p++) tbl[*p]=*(p-1);
    int ch;
    while((ch=getchar())!=EOF) putchar(tbl[ch]);
    return 0;
}

