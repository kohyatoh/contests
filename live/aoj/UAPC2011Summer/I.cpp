#include <stdio.h>
#include <iostream>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define MOD (100000007LL)
typedef long long Int;

const int of[2] = {3, 5};
Int dp1[2][200000], dp2[2][200000], sub[2][8];
char f[200000];

int which(char ch) {
    if(ch=='8' || ch=='0') return 0;
    return 1;
}

int main() {
    rep(k, 2) {
        dp1[k][0] = 1;
        rep(i, 180000) rep(j, of[k]) {
            dp1[k][i+j+1] = (dp1[k][i+j+1]+dp1[k][i])%MOD;
        }
        rep(i, 180000) {
            if(i) sub[k][i%of[k]] = (sub[k][i%of[k]]+dp1[k][i])%MOD;
            dp2[k][i] = (dp2[k][i]+sub[k][i%of[k]])%MOD;
        }
    }
    for(;;) {
        scanf("%s", f);
        if(f[0]=='#') return 0;
        int pre = 0, cur = 0;
        Int ans = 1;
        do {
            if(f[pre]!=f[cur]) {
                const Int w = dp2[which(f[pre])][cur-pre];
                ans = (ans*w)%MOD;
                pre = cur;
            }
        } while(f[cur++]);
        cout << ans << endl;
    }
}
