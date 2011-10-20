#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

char f[2000];
int cnt[10], pre[10][16], dp[10][16];

string imax(const string& a, const string& b) {
    if(a.size()>b.size()) return a;
    if(a.size()<b.size()) return b;
    return max(a, b);
}

string solve(int r) {
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for(int k=1; k<10; k++) for(int i=cnt[k]; i>=0; i--) rep(j, 15) {
        if(dp[k-1][j]<0) continue;
        const int ix = (j+i*k*10)%15;
        if(dp[k][ix]<dp[k-1][j]+i) {
            dp[k][ix] = dp[k-1][j]+i;
            pre[k][ix] = j;
        }
    }
    string s;
    for(int x=9, y=r; x>0; x--) {
        if(dp[x][y]==-1) return "";
        const int py = pre[x][y];
        s += string(dp[x][y]-dp[x-1][py], ((char)(x+'0')));
        y = py;
    }
    if(s.size()) s += string(cnt[0], '0');
    return s;
}

int main() {
    scanf("%s", f);
    for(int i=0; f[i]; i++) cnt[f[i]-'0']++;
    string ans = "";
    if(cnt[0]) ans = "0";
    rep(i, 10) if(cnt[i]) {
        cnt[i]--;
        const string& s = solve((15-i)%15);
        if(s.size()) ans = imax(ans, s+(char)(i+'0'));
        cnt[i]++;
    }
    if(ans=="") ans = "impossible";
    printf("%s\n", ans.c_str());
    return 0;
}
