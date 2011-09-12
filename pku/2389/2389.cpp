#include <iostream>
#include <string>
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

string imul(string a, string b) {
    string r="0";
    for(int i=0; i<(int)b.size(); i++) {
        r=iadd(r, imul(a, (int)b[i]-'0')+string(b.size()-1-i, '0'));
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
    string s1, s2;
    cin >> s1 >> s2;
    cout << normalize(imul(s1, s2)) << endl;
    return 0;
}

