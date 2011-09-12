#include <iostream>
#include <string>
#include <utility>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

long long ans;
int n, x[30], y[30];

typedef pair<int, int> result;
result parse(string ex);
char nextToken();
result expr();

string _s;
unsigned _ix;
char token;

result parse(string ex) {
    _s = ex;
    _ix = 0;
    token = nextToken();
    return expr();
}

char nextToken() {
    if(_ix==_s.size()) return 0;
    while(_ix<_s.size() && _s[_ix]==' ') _ix++;
    return _s[_ix++];
}

result expr() {
    if(token!='(') {
        result r(x[token-'A'], y[token-'A']);
        token = nextToken();
        return r;
    }
    else {
        token = nextToken();
        result l(expr()), r(expr());
        token = nextToken();
        if(l.second!=r.first) ans=-1;
        else if(ans!=-1) ans+=l.first*l.second*r.second;
        return mp(l.first, r.second);
    }
}

int main() {
    cin >> n;
    rep(i, n) {
        char name;
        cin >> name;
        cin >> x[name-'A'] >> y[name-'A'];
    }
    string s;
    while(cin>>s) {
        ans = 0;
        parse(s);
        if(ans>=0) cout << ans << endl;
        else cout << "error" << endl;
    }
    return 0;
}

