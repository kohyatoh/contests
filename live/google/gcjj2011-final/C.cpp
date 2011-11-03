#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

string A, B;

struct pat {
    string p;
    pat(const string& p) : p(p) {}
    int star() const { return count(p.begin(), p.end(), '*'); }
};

bool operator<(const pat& a, const pat& b) {
    if(a.p.size()!=b.p.size()) return a.p.size() > b.p.size();
    const int ca = a.star(), cb = b.star();
    if(ca!=cb) return ca > cb;
    return a.p > b.p;
}

struct tuple3 {
    int i, j, k;
    tuple3(int i, int j, int k) : i(i), j(j), k(k) {}
};

bool operator<(const tuple3& l, const tuple3& r) {
    return l.i!=r.i ? l.i<r.i : l.j!=r.j ? l.j<r.j : l.k<r.k;
}

string solve() {
    string a = "$"+A, b = "$"+B;
    priority_queue<pair<pat, tuple3> > q;
    q.push(mp(pat("$"), tuple3(1, 1, 1)));
    set<tuple3> vis;
    while(!q.empty()) {
        pair<pat, tuple3> vv(q.top());
        q.pop();
        if(vis.find(vv.second)!=vis.end()) continue;
        vis.insert(vv.second);
        const string& p = vv.first.p;
        const int l = vv.second.i;
        const int r = vv.second.j;
        const int len = vv.second.k;
        if(l==(int)a.size() && r==-1) return p;

        const string tk = a.substr(l-len, len);
        if(tk==a.substr(a.size()-len)
                && (len==(int)a.size() || pat(p).star()>0)
                && (r==-1 || tk!=b.substr(b.size()-len))) {
            // make end
            q.push(mp(pat(p), tuple3(a.size(), -1, len)));
        }

        if(l==(int)a.size()) continue;
        if(r==-1) {
            // b is consumed, but a is remaining.
            q.push(mp(pat(p+'*'), tuple3(a.size(), -1, 0)));
            q.push(mp(pat(p+a[l]), tuple3(l+1, -1, len+1)));
            continue;
        }

        // a and b remaining.
        for(char ch='a'; ch<='z'; ch++) {
            // +ch
            const string tk = a.substr(l-len, len)+ch;
            const size_t posa = a.find(tk, l-len);
            const size_t posb = b.find(tk, r-len);
            if(posa!=string::npos) {
                const int nr = posb==string::npos ? -1 : posb+tk.size();
                q.push(mp(pat(p+ch), tuple3(posa+tk.size(), nr, len+1)));
            }
            // +'*'+ch
            const size_t ax = a.find(ch, l);
            const size_t bx = b.find(ch, r);
            if(ax!=string::npos) {
                const int nr = bx==string::npos ? -1 : bx+1;
                q.push(mp(pat(p+"*"+ch), tuple3(ax+1, nr, 1)));
            }
        }
    }
    return "$!";
}

int main() {
    int T;
    cin >> T;
    rep(i, T) {
        cin >> A >> B;
        string ans = solve();
        printf("Case #%d: %s\n", i+1, ans.c_str()+1);
    }
    return 0;
}
