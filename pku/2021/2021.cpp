#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int T, n, r[100], fage[100];
string fname[100], cname[100];
pair<int, string> v[100];

int calc(int k) {
    if(r[k]!=-1) return r[k];
    if(fname[k]=="Ted") return r[k]=fage[k];
    rep(i, n) if(fname[k]==cname[i]) return r[k]=calc(i)+fage[k];
    return 0;
}

int main() {
    cin >> T;
    rep(q, T) {
        cin >> n;
        rep(i, n) cin >> fname[i] >> cname[i] >> fage[i];
        rep(i, n) r[i]=-1;
        rep(i, n) {
            v[i].first = calc(i);
            v[i].second = cname[i];
        }
        sort(v, v+n);
        cout << "DATASET " << q+1 << endl;
        rep(i, n) cout << v[i].second << ' ' << 100-v[i].first << endl;
    }
}
