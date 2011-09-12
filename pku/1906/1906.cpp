#include <iostream>
#include <string>
#include <vector>
using namespace std;

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
    return r;
}

string imul(string a, int k) {
    int n=a.size()+1;
    a='0'+a;
    int carr=0;
    string r(n, '0');
    for(int i=n-1; i>=0; i--) {
        r[i]=((a[i]-'0')*k+carr)%10+'0';
        carr=((a[i]-'0')*k+carr)/10;
    }
    return r;
}

string normalize(const string& s) {
    int i=0;
    while(i<(int)s.size() && s[i]=='0') i++;
    if(i==(int)s.size()) return "0";
    return s.substr(i);
}

int main() {
    unsigned long long n;
    for(;;) {
        cin >> n;
        if(n==0) return 0;
        n--;
        vector<string> v;
        string k="1";
        for(int i=0; i<64; i++) {
            if(n&(1LL<<i)) v.push_back(k);
            k = imul(k, 3);
        }
        string ans="";
        for(int i=0; i<(int)v.size(); i++) {
            if(ans.size()) ans += ", ";
            ans += normalize(v[i]);
        }
        cout << "{ " << ans << (ans.size() ? " }" : "}") << endl;
    }
}

