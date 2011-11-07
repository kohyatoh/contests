#include <stdio.h>
#include <string.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int ctoi(char ch) {
    if(ch=='_') return 0;
    if(ch=='.') return 27;
    return ch-'a'+1;
}

char itoc(int i) {
    if(i==0) return '_';
    if(i==27) return '.';
    return 'a'+i-1;
}

int cc[256], pc[256];
char f[256];

int main() {
    for(;;) {
        int k;
        scanf("%d", &k);
        if(k==0) return 0;
        scanf(" %s", f);
        const int n = strlen(f);
        rep(i, n) cc[i] = ctoi(f[i]);
        rep(i, n) pc[k*i%n] = (cc[i]+i)%28;
        rep(i, n) putchar(itoc(pc[i]));
        putchar('\n');
    }
}
