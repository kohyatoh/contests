#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int t, n;
string s[100];

int main() {
    cin >> t;
    rep(q, t) {
        cin >> n;
        rep(i, n) cin >> s[i];
        rep(i, n) if(s[0].size()>s[i].size()) swap(s[0], s[i]);
        int ans=0;
        for(int l=1; l<=s[0].size(); l++) {
            bool f=false;
            rep(i, s[0].size()-l+1) {
                string sub=s[0].substr(i, l);
                string rev(sub);
                reverse(rev.begin(), rev.end());
                f=true;
                for(int i=1; i<n; i++) {
                    if(s[i].find(sub)==string::npos
                            && s[i].find(rev)==string::npos) {
                        f=false;
                        break;
                    }
                }
                if(f) break;
            }
            if(f) ans=l;
            else break;
        }
        cout << ans << endl;
    }
    return 0;
}

