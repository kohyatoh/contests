#include <iostream>
#include <string>
#include <set>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

string strip(const string& s, int ix) {
    while(s[ix]!='"') ix++;
    int jx=ix+1;
    while(s[jx]!='"') jx++;
    return s.substr(ix+1, jx-ix-1);
}

int n, ans;
string ini, fr[100], to[100];
set<string> vis;

void calc(const string& s) {
    if(vis.find(s)!=vis.end()) return;
    vis.insert(s);
    ans++;
    if(ans>1000) return;
    rep(i, n) {
        int ix=-1;
        while((ix=s.find(fr[i], ix+1))!=string::npos) {
            calc(s.substr(0, ix)+to[i]+s.substr(ix+fr[i].size()));
            if(ans>1000) return;
        }
    }
}

int main() {
    cin >> ini;
    ini = strip(ini, 0);
    while(cin>>fr[n]) {
        to[n] = strip(fr[n], fr[n].find('>')+1);
        fr[n] = strip(fr[n], 0);
        n++;
    }
    calc(ini);
    if(ans>1000) cout << "Too many." << endl;
    else cout << ans << endl;
    return 0;
}

