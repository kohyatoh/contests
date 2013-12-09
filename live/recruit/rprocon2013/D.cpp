#include <stdio.h>
#include <string.h>
#include <iostream>
#include <map>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int f[210][210], u[30];

int main() {
    int T;
    cin >> T;
    rep (_, T) {
        int n;
        cin >> n;
        memset(f, 0, sizeof(f));
        rep (k, n) {
            int x, y, w, h;
            cin >> x >> y >> w >> h;
            rep (i, w) rep (j, h) {
                if (f[x+i][y+j]) f[x+i][y+j] = -1;
                else f[x+i][y+j] = k+1;
            }
        }
        memset(u, 0, sizeof(u));
        rep (i, 210) rep (j, 210) {
            if (f[i][j] > 0) u[f[i][j]-1] = 1;
        }
        bool ans = false;
        rep (i, n) if (!u[i]) ans = true;
        puts(ans ? "TRUE" : "FALSE");
    }
    return 0;
}
