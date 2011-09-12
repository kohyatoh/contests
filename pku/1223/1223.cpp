#include <stdlib.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, ansn, type;
string f, b, ans[128], cur[128];

int est(int fi) {
    int ml=0, p=0;
    for(int i=fi; i<f.size(); i++) {
        if(cur[f[i]].size()) ml += cur[f[i]].size();
        else {
            if(p==0) p=f[i];
            if(f[i]==p || type<=2) ml+=1;
            else ml+=2;
        }
    }
    return ml;
}

void rec(int fi, int bi) {
    // cerr << fi << ' ' << bi << endl;
    if(ansn>1) return ;
    if(fi==f.size()) {
        if(bi==b.size()) {
            ansn++;
            rep(i, 128) ans[i]=cur[i];
        }
        return ;
    }
    if(cur[f[fi]].size()) {
        if(bi+cur[f[fi]].size()>b.size()) return ;
        rep(i, cur[f[fi]].size()) if(b[bi+i]!=cur[f[fi]][i]) return ;
        rec(fi+1, bi+cur[f[fi]].size());
    }
    else {
        int L=1;
        rep(k, 128) if(cur[k].size()) {
            int m=min(cur[k].size(), b.size()-bi);
            int ix=0;
            while(ix<m && cur[k][ix]==b[bi+ix]) ix++;
            if(ix==m) return ;
            L = max(L, ix+1);
        }
        for(; bi+L<=(int)b.size(); L++) {
            cur[f[fi]] = b.substr(bi, L);
            if(bi+est(fi)>b.size()) break;
            rec(fi+1, bi+L);
        }
        cur[f[fi]] = "";
    }
}

int main() {
    string s;
    getline(cin, s);
    n = atoi(s.c_str());
    rep(q, n) {
        getline(cin, f);
        getline(cin, b);
        type=0;
        rep(i, f.size()) {
            bool e=true;
            rep(j, i) if(f[i]==f[j]) e=false;
            if(e) type++;
        }
        ansn = 0;
        rec(0, 0);
        cout << "DATASET #" << q+1 << endl;
        if(ansn==1) {
            rep(i, 128) if(ans[i].size()) {
                cout << (char)i << " = " << ans[i] << endl;
            }
        }
        else {
            cout << "MULTIPLE TABLES" << endl;
        }
    }
}

