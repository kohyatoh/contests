#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int cnt[2][26];

int main() {
    rep(i, 2) {
        string s;
        cin >> s;
        rep(j, s.size()) cnt[i][s[j]-'A']++;
        sort(cnt[i], cnt[i]+26);
    }
    bool yes=true;
    rep(i, 26) if(cnt[0][i]!=cnt[1][i]) yes=false;
    cout << (yes ? "YES" : "NO") << endl;
    return 0;
}

