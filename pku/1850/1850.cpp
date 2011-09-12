#include <iostream>
#include <string>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int cb[32][32];
string s;
bool error;

int calc(int ix, char a) {
    if(ix==(int)s.size()) return 1;
    if(s[ix]<'a' || s[ix]>'z' || s[ix]<a) {
        error = true;
        return 0;
    }
    int r=0;
    for(char c=a; c<s[ix]; c++) r += cb['z'-c][s.size()-ix-1];
    return r+calc(ix+1, s[ix]+1);
}

int main() {
    cb[0][0] = 1;
    rep(i, 30) rep(j, i+1) cb[i+1][j]+=cb[i][j], cb[i+1][j+1]+=cb[i][j];
    cin >> s;
    int ans=calc(0, 'a');
    rep(i, s.size()-1) ans+=cb[26][i+1];
    cout << (error ? 0 : ans) << endl;
    return 0;
}

