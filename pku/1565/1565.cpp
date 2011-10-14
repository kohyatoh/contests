#include <stdio.h>
#include <string.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

char b[100];

int main() {
    for(;;) {
        gets(b);
        if(b[0]=='0') return 0;
        const int n = strlen(b);
        int a = 0;
        rep(i, n) a += (b[n-1-i]-'0')*((1<<(i+1))-1);
        printf("%d\n", a);
    }
}
