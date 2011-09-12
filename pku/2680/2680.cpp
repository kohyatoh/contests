#include <iostream>
#include <string>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n;
string dp[2000][2];

string normalize(const string& s) {
    int i=0;
    while(i<(int)s.size() && s[i]=='0') i++;
    if(i==(int)s.size()) return "0";
    return s.substr(i);
}

string iadd(string a, string b) {
    int n=max(a.size(), b.size())+1;
    a=string(n-a.size(), '0')+a;
    b=string(n-b.size(), '0')+b;
    string r(n, '0');
    int carr=0;
    for(int i=n-1; i>=0; i--) {
        r[i]=(a[i]-'0'+b[i]-'0'+carr)%10+'0';
        carr=(a[i]-'0'+b[i]-'0'+carr)/10;
    }
    return normalize(r);
}

int main() {
    int f = 1;
    dp[0][0]=dp[0][1]="0";
    rep(i, 1000) {
        dp[i+1][0] = dp[i+1][1] = iadd(dp[i][0], dp[i][1]);
        if(f==0) dp[i+1][0] = iadd(dp[i+1][0], "1");
        f = 1-f;
    }
    while(cin>>n) cout << dp[n][0] << endl;
    return 0;
}

