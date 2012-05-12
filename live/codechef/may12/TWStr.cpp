#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair

int N, Q;
pair<string, int> rs[2000];

int get(const string& q) {
    return lower_bound(rs, rs+N, mp(q, -(int)2e9)) - rs;
}

int main() {
    cin >> N;
    rep (i, N) cin >> rs[i].first >> rs[i].second;
    sort(rs, rs+N);
    cin >> Q;
    rep (_, Q) {
        string q;
        cin >> q;
        const int l = get(q);
        const int r = get(q+'|');
        if (l == r) cout << "NO" << endl;
        else {
            int k = l;
            for (int i = l; i < r; i++) {
                if (rs[i].second > rs[k].second) k = i;
            }
            cout << rs[k].first << endl;
        }
    }
    return 0;
}
