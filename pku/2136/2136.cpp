#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int cnt[26];
char s[400];

int main() {
    rep(i, 4) {
        gets(s);
        for(char *p=s; *p; p++) if('A'<=*p && *p<='Z') cnt[*p-'A']++;
    }
    int mx=0;
    rep(i, 26) if(mx<cnt[i]) mx=cnt[i];
    for(int y=mx; y>0; y--) {
        int w=0;
        rep(i, 26) if(cnt[i]>=y) w=i+1;
        rep(i, w) {
            if(i) putchar(' ');
            putchar(cnt[i]>=y ? '*' : ' ');
        }
        putchar('\n');
    }
    rep(i, 26) printf("%c%c", 'A'+i, i==25 ? '\n' : ' ');
    return 0;
}

