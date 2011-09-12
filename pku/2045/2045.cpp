#include <stdlib.h>
#include <iostream>
#include <string>
#include <map>
using namespace std;

typedef map<string, int> result;
result parse(string ex);
string nextToken();
bool is_num(const string& t);
result seq();
result elem();

string _s;
unsigned _ix;
string token;

result parse(string ex) {
    _s = ex;
    _ix = 0;
    token = nextToken();
    return seq();
}

string nextToken() {
    if(_ix==_s.size()) return "";
    unsigned k=1;
    if('0'<=_s[_ix] && _s[_ix]<='9') {
        while(_ix+k<_s.size() && '0'<=_s[_ix+k] && _s[_ix+k]<='9') k++;
    }
    else if('A'<=_s[_ix] && _s[_ix]<='Z') {
        while(_ix+k<_s.size() && 'a'<=_s[_ix+k] && _s[_ix+k]<='z') k++;
    }
    _ix += k;
    return _s.substr(_ix-k, k);
}

bool is_num(const string& t) {
    return t.size() && '0'<=t[0] && t[0]<='9';
}

result seq() {
    result r(elem());
    while(token!="" && token!=")") {
        result v(elem());
        for(result::iterator it=v.begin(); it!=v.end(); it++) {
            r[it->first] += it->second;
        }
    }
    return r;
}

result elem() {
    result r;
    if(token=="(") {
        token = nextToken();
        r=seq();
        // token==")"
    }
    else r[token]=1;
    token = nextToken();
    if(is_num(token)) {
        int k = atoi(token.c_str());
        for(result::iterator it=r.begin(); it!=r.end(); it++) {
            r[it->first] *= k;
        }
        token = nextToken();
    }
    return r;
}

int main() {
    map<string, int> w;
    string a;
    int b;
    for(;;) {
        cin >> a;
        if(a=="END_OF_FIRST_PART") break;
        cin >> b;
        w[a] = b;
    }
    string s;
    for(;;) {
        cin >> s;
        if(s=="0") return 0;
        result r(parse(s));
        int ans=0;
        for(result::iterator it=r.begin(); it!=r.end(); it++) {
            if(w.find(it->first)==w.end()) {
                ans=-1;
                break;
            }
            ans += w[it->first] * it->second;
        }
        if(ans>=0) cout << ans << endl;
        else cout << "UNKNOWN" << endl;
    }
}
