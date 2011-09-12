#include <stdlib.h>
#include <iostream>
#include <string>
#include <queue>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, g[200][200], dig[200];

string _s;
unsigned _ix;
string token;

string nextToken();
void tree(int r);

void parse(string ex) {
    _s = ex;
    _ix = 0;
    token = nextToken();
    tree(0);
}

string nextToken() {
    while(_ix<_s.size() && _s[_ix]==' ') _ix++;
    if(_ix==_s.size()) return "";
    unsigned k=1;
    if('0'<=_s[_ix] && _s[_ix]<='9') {
        while(_ix+k<_s.size() && '0'<=_s[_ix+k] && _s[_ix+k]<='9') k++;
    }
    _ix += k;
    return _s.substr(_ix-k, k);
}

void tree(int r) {
    // token=='(';
    token = nextToken();
    int z=atoi(token.c_str());
    n++;
    if(r!=0) g[r][z]=g[z][r]=1;
    token = nextToken();
    while(token=="(") {
        tree(z);
    }
    token = nextToken();
}

int main() {
    string s;
    while(getline(cin, s)) {
        n = 0;
        rep(i, 200) rep(j, 200) g[i][j]=0;
        rep(i, 200) dig[i]=0;
        parse(s);
        rep(i, 200) rep(j, 200) if(g[i][j]) dig[i]++;
        priority_queue<int> q;
        rep(i, 200) if(dig[i]==1) q.push(-i);
        int c=0;
        while(c<n-1 && !q.empty()) {
            int v=-q.top();
            q.pop();
            dig[v]--;
            rep(i, 200) if(g[v][i] && dig[i]>0) {
                if(c++) cout << ' ';
                cout << i;
                if(--dig[i]==1) q.push(-i);
            }
        }
        cout << endl;
    }
    return 0;
}
