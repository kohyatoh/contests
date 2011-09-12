#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n;
string r[200];
int tb[200][5];

int main() {
    for(;;) {
        cin >> n;
        if(n==0) return 0;
        rep(i, n) cin >> r[i];
        rep(i, n) rep(j, 5) tb[i][r[i][j]-'A'] = j;
        string s("ABCDE"), ans;
        int minc=1<<30;
        do {
            rep(i, 5) tb[n][s[i]-'A'] = i;
            int c=0;
            rep(k, n) rep(i, 5) rep(j, i) {
                c+=(tb[k][i]-tb[k][j])*(tb[n][i]-tb[n][j])<0;
            }
            if(minc>c) { minc=c; ans=s; }
        } while(next_permutation(s.begin(), s.end()));
        cout << ans << " is the median ranking with value " << minc << "." << endl;
    }
}

