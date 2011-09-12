#include <stdio.h>
#include <string.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int cnt[2][16];

bool check(char *a, char *b) {
    memset(cnt, 0, sizeof(cnt));
    if(*a=='0' || *b=='0') return false;
    for(char *p=a; *p; p++) cnt[0][*p-'0']++;
    for(char *p=b; *p; p++) cnt[1][*p-'0']++;
    rep(i, 10) if(!cnt[0][i] != !cnt[1][i]) return false;
    return true;
}

bool acheck(char *a, char *b) {
    for(char *p=a; *(p+1); p++) {
        if(*p>='1' && *(p+1)<'9') {
            --*p; ++*(p+1);
            if(check(a, b)) return true;
            ++*p; --*(p+1);
        }
        if(*p<'9' && *(p+1)>='1') {
            ++*p; --*(p+1);
            if(check(a, b)) return true;
            --*p; ++*(p+1);
        }
    }
    return false;
}

char a[128], b[128];

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%s%s", a, b);
        if(check(a, b)) puts("friends");
        else if(acheck(a, b) || acheck(b, a)) puts("almost friends");
        else puts("nothing");
    }
    return 0;
}
