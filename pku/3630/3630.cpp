#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

string s[20000];
char buf[32];

bool solve(int n) {
    sort(s, s+n);
    rep(k, n-1) if(s[k].size()<s[k+1].size()) {
        bool pre = true;
        rep(i, s[k].size()) if(s[k][i]!=s[k+1][i]) pre = false;
        if(pre) return false;
    }
    return true;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        rep(i, n) {
            scanf("%s", buf);
            s[i] = buf;
        }
        puts(solve(n) ? "YES" : "NO");
    }
    return 0;
}

