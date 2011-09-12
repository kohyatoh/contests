#include <stdio.h>
#include <string.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

char str[120];
int tb[30][30];

int main() {
    for(;;) {
        gets(str);
        if(*str=='*') return 0;
        int n=strlen(str);
        bool f=true;
        for(int d=1; d<n; d++) {
            rep(i, 30) rep(j, 30) tb[i][j]=0;
            rep(i, n-d) {
                if(tb[str[i]-'A'][str[i+d]-'A']) { f=false; goto loop_end; }
                tb[str[i]-'A'][str[i+d]-'A']=1;
            }
        }
    loop_end:
        printf("%s %s surprising.\n", str, f ? "is" : "is NOT");
    }
}

