#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, c, b;
char s[32], cs[32];

void rec(int ix, int cx) {
    if(ix==n) {
        if(b>=1 && n-b>=2) puts(cs);
        return ;
    }
    for(int i=cx; i<c; i++) {
        cs[ix] = s[i];
        if(s[i]=='a' || s[i]=='i' || s[i]=='u' || s[i]=='e' || s[i]=='o') b++;
        rec(ix+1, i+1);
        if(s[i]=='a' || s[i]=='i' || s[i]=='u' || s[i]=='e' || s[i]=='o') b--;
    }
}

int main() {
    scanf("%d%d", &n, &c);
    rep(i, c) scanf(" %c", s+i);
    sort(s, s+c);
    b = 0;
    rec(0, 0);
    return 0;
}
