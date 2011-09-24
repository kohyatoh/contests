#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

int n, m[50], d[50][50], cnt[50], pnt[50];
string name[50];

int main() {
    for(;;) {
        cin >> n;
        if(n==0) return 0;
        rep(i, n) {
            cin >> name[i] >> m[i];
            rep(j, m[i]) cin >> d[i][j];
        }
        memset(cnt, 0, sizeof(cnt));
        rep(i, n) rep(j, m[i]) cnt[d[i][j]]++;
        memset(pnt, 0, sizeof(pnt));
        rep(i, n) rep(j, m[i]) pnt[i] += n+1-cnt[d[i][j]];
        pair<int, string> ans(1<<30, string());
        rep(i, n) ans = min(ans, mp(pnt[i], name[i]));
        cout << ans.first << ' ' << ans.second << endl;
    }
}
