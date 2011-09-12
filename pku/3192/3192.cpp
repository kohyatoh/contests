#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, a[10];
string s[10];

int main() {
    cin >> n;
    rep(i, n) cin >> s[i];
    rep(i, n) a[i] = i;
    int ans = 10000;
    do {
        string r;
        rep(i, n) {
            const string t = s[a[i]];
            for(int l=min(r.size(), t.size()); l>=0; l--) {
                bool f = true;
                rep(i, l) if(r[r.size()-l+i]!=t[i]) f=false;
                if(f) {
                    r += t.substr(l);
                    break;
                }
            }
        }
        ans = min(ans, (int)r.size());
    } while(next_permutation(a, a+n));
    cout << ans << endl;
    return 0;
}
