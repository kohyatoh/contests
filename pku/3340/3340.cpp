#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
typedef long long Int;

char s[32], f[32];

int main() {
    for(;;) {
        scanf(" %s", s);
        if(s[0]=='#') return 0;
        scanf("%s", f);
        const int n = strlen(s);
        Int dig = 1, ans = 0;
        rep(i, n) if(s[i]=='?') dig *= 10;
        rep(i, n) {
            if(s[i]!='?') {
                if(s[i]>f[i]) ans += dig;
                if(s[i]!=f[i]) break;
            }
            else {
                dig /= 10;
                ans += dig*('9'-f[i]);
            }
        }
        cout << ans << endl;
    }
}
