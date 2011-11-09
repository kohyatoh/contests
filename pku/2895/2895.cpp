#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

const char raw[9][8] = {
    " ", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"
};
string tbl[9];

int of(char ch) {
    rep(i, 9) if(tbl[i].find(ch)!=string::npos) return i;
    return -1;
}

char buf[4000];

int main() {
    rep(i, 9) tbl[i] = raw[i];
    gets(buf);
    int T = atoi(buf);
    while(T--) {
        gets(buf);
        int p, w;
        sscanf(buf, "%d%d", &p, &w);
        gets(buf);
        int ans = 0, pre = -1;
        for(int i=0; buf[i]; i++) {
            const int cur = of(buf[i]);
            if(cur!=0 && cur==pre) ans += w;
            ans += p*(1+tbl[cur].find(buf[i]));
            pre = cur;
        }
        printf("%d\n", ans);
    }
    return 0;
}
