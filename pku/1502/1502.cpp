#include <stdlib.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, a[200][200];

int main() {
    cin >> n;
    string s;
    rep(i, n) {
        rep(j, i) {
            cin >> s;
            if(s=="x") a[i][j]=a[j][i]=1<<28;
            else a[i][j]=a[j][i]=atoi(s.c_str());
        }
    }
    rep(k, n) rep(i, n) rep(j, n) a[i][j]=min(a[i][j], a[i][k]+a[k][j]);
    int ans=0;
    rep(i, n) ans=max(ans, a[0][i]);
    cout << ans << endl;
    return 0;
}

