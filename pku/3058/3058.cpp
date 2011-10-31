#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

char f[1000001], r[1000001];
int cnt[256], pos[256], tr[1000001];

int main() {
    gets(r);
    int T = atoi(r);
    while(T--) {
        memset(cnt, 0, sizeof(cnt));
        memset(pos, 0, sizeof(pos));
        gets(r);
        const char *p = r;
        int L = 0, ix = -1;
        while(*p) {
            const char ch = *p++;
            if(ch=='.') ix = L;
            int dig = 0;
            while(isdigit(*p)) {
                dig = dig*10+*p-'0';
                p++;
            }
            if(dig==0) dig = 1;
            cnt[(int)ch] += dig;
            do f[L++] = ch; while(--dig>0);
        }
        rep(i, 255) pos[i+1] = pos[i] + cnt[i];
        rep(i, L) tr[i] = pos[(int)f[i]]++;
        r[L] = 0;
        for(int i=L-1; i>=0; i--) {
            r[i] = f[ix];
            ix = tr[ix];
        }
        puts(r);
    }
    return 0;
}
