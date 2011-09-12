#include <stdio.h>
#include <stdlib.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n;
char b[80], d[1000001];

int main() {
    gets(b); n = atoi(b);
    rep(i, n) { gets(b); d[i]=b[0]-'0'+b[2]-'0'; }
    int carry=0;
    for(int i=n-1; i>=0; i--) {
        d[i]+=carry;
        carry=d[i]/10;
        d[i]=d[i]%10+'0';
    }
    d[n]=0;
    puts(d);
    return 0;
}

