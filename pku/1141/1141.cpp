#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define INF (1<<28)
inline void cmin(int &a, int b) { if(a>b) a = b; }

int memo[128][128];
string f;

int rec(int l, int r) {
    if(l>=r) return 0;
    if(memo[l][r]!=-1) return memo[l][r];
    int ans = INF;
    if(f[l]=='(' && f[r-1]==')') cmin(ans, rec(l+1, r-1));
    if(f[l]=='[' && f[r-1]==']') cmin(ans, rec(l+1, r-1));
    cmin(ans, 1+rec(l+1, r));
    cmin(ans, 1+rec(l, r-1));
    for(int i=l+1; i<r; i++) cmin(ans, rec(l, i)+rec(i, r));
    return memo[l][r] = ans;
}

string build(int l, int r) {
    if(l>=r) return "";
    const int a = rec(l, r);
    if(a==rec(l+1, r-1)) {
        if(f[l]=='(' && f[r-1]==')') return '(' + build(l+1, r-1) + ')';
        if(f[l]=='[' && f[r-1]==']') return '[' + build(l+1, r-1) + ']';
    }
    if(a==1+rec(l+1, r)) {
        if(f[l]=='(' || f[l]==')') return "()" + build(l+1, r);
        if(f[l]=='[' || f[l]==']') return "[]" + build(l+1, r);
    }
    if(a==1+rec(l, r-1)) {
        if(f[r-1]=='(' || f[r-1]==')') return build(l, r-1) + "()";
        if(f[r-1]=='[' || f[r-1]==']') return build(l, r-1) + "[]";
    }
    for(int i=l+1; i<r; i++) {
        if(a==rec(l, i)+rec(i, r)) return build(l, i)+build(i, r);
    }
    return "";
}

int main() {
    getline(cin, f);
    memset(memo, -1, sizeof(memo));
    cout << build(0, f.size()) << endl;
    return 0;
}
