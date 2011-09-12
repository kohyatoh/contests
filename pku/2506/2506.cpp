#include <iostream>
#include <string>
using namespace std;

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

string dp[300];

int main() {
    dp[0]="1", dp[1]="1";
    for(int i=2; i<=250; i++) dp[i]=iadd(dp[i-1], iadd(dp[i-2], dp[i-2]));
    int n;
    while(cin >> n) cout << dp[n] << endl;
    return 0;
}
