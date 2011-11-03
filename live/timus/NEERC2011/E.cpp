#include <stdio.h>
#include <string>
#include <vector>
#include <set>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n;
string ns[2000], of[2000];

bool can(int p) {
    if(n%p!=0) return false;
    const int m = n/p;
    rep(i, p) of[i] = "";
    rep(i, n) if(ns[i].size()) {
        const int ix = i/m;
        if(of[ix].size() && of[ix]!=ns[i]) return false;
        if(of[ix].size()==0) of[ix] = ns[i];
    }
    set<string> see;
    rep(i, p) if(of[i].size()) {
        if(see.count(of[i])) return false;
        see.insert(of[i]);
    }
    return true;
}

char buf[128];

int main() {
    scanf("%d", &n);
    rep(i, n) {
        scanf(" %s", buf);
        ns[i] = buf;
        if(ns[i]=="unknown") ns[i] = "";
    }
    vector<int> ans;
    for(int i=1; i<=n; i++) if(can(i)) ans.push_back(i);
    if(ans.size()==0) puts("Igor is wrong.");
    else {
        rep(i, ans.size()) {
            printf("%d%c", ans[i], i<(int)ans.size()-1 ? ' ' : '\n');
        }
    }
    return 0;
}

