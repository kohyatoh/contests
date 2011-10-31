#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

const char raw[26][8] = {
    "4", "|3", "(", "|)", "3", "|=", "6", "#", "|", "_|",
    "|<", "|_", "|\\/|", "|\\|", "0", "|0", "(,)", "|?",
    "5", "7", "|_|", "\\/", "\\/\\/", "><", "-/", "2",
};

string tbl[26];
int dp[1024];

int main() {
    rep(i, 26) tbl[i] = raw[i];
    for(;;) {
        string src;
        getline(cin, src);
        if(src=="end") return 0;
        string f;
        rep(i, src.size()) f += tbl[src[i]-'A'];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        rep(k, f.size()) rep(i, 26) if(k+tbl[i].size()<=f.size()) {
            bool match = true;
            rep(j, tbl[i].size()) if(tbl[i][j]!=f[k+j]) {
                match = false;
                break;
            }
            if(match) dp[k+tbl[i].size()] += dp[k];
        }
        printf("%d\n", dp[f.size()]);
    }
}
