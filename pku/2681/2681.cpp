#include <stdio.h>
#include <stdlib.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int Q, cnt[26];
char buf[80];

int main() {
    gets(buf); Q=atoi(buf);
    rep(q, Q) {
        rep(i, 26) cnt[i]=0;
        gets(buf); for(int i=0; buf[i]!=0; i++) cnt[buf[i]-'a']++;
        gets(buf); for(int i=0; buf[i]!=0; i++) cnt[buf[i]-'a']--;
        int ans=0;
        rep(i, 26) ans+=abs(cnt[i]);
        printf("Case #%d:  %d\n", q+1, ans);
    }
    return 0;
}
