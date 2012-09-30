#include <iostream>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)

int n, x[4096][4096];
long long a[4096], s[4096], c[4096][4096];

int main() {
    cin >> n;
    rep (i, n) cin >> a[i];
    rep (i, n) s[i+1] = s[i]+a[i];
    rep (w, n) if (w) rep (i, n-w) {
        int j = i+w+1;
        c[i][j] = c[i][i+1]+c[i+1][j], x[i][j] = i+1;
        if (w>1) for (int k=x[i][j-1]; k<=x[i+1][j]; k++) {
            if (c[i][j]>c[i][k]+c[k][j]) c[i][j] = c[i][k]+c[k][j], x[i][j] = k;
        }
        c[i][j] += s[j]-s[i];
    }
    cout << c[0][n] << endl;
    return 0;
}
