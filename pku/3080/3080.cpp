#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n;
string s[10];

void solve() {
    for(int l=60; l>2; l--) {
        string ans;
        for(int i=0; i+l<=60; i++) {
            string sub = s[0].substr(i, l);
            bool ok = true;
            for(int j=1; j<n; j++) {
                if(s[j].find(sub)==string::npos) {
                    ok = false;
                    break;
                }
            }
            if(ok && (ans.size()==0 || ans>sub)) ans=sub;
        }
        if(ans.size()) {
            puts(ans.c_str());
            return;
        }
    }
    puts("no significant commonalities");
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        rep(i, n) cin >> s[i];
        solve();
    }
    return 0;
}
