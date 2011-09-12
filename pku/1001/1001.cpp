#include <iostream>
#include <string>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

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

string imul(string a, string b) {
    string r="0";
    for(int i=0; i<(int)b.size(); i++) {
        r=iadd(r, imul(a, (int)b[i]-'0')+string(b.size()-1-i, '0'));
    }
    return r;
}

string float_repr(string s, int p) {
    s=normalize(s);
    if(s=="0") return "0";
    if(p>=0) return s+string(p, '0');
    else {
        string r;
        if((int)s.size()<=-p) r="."+string(-(s.size()+p), '0')+s;
        else r=s.substr(0, s.size()+p)+'.'+s.substr(s.size()+p);
        int i=r.size()-1;
        while(r[i]=='0') i--;
        if(r[i]=='.') i--;
        return r.substr(0, i+1);
    }
}

int main() {
    string s;
    int k;
    while(cin >> s >> k) {
        string r="1";
        int t=(s.find('.')-s.size()+1);
        s=s.replace(s.find('.'), 1, "");
        rep(i, k) r=imul(r, s);
        cout << float_repr(r, t*k) << endl;
    }
    return 0;
}

