#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long Int;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int f[128][128];

bool can(const string& s, int w, int h) {
    const int n = s.size();
    rep (i, w) rep (j, h) f[i][j] = -1;
    int x = 0, y = 0, d = 0;
    rep (i, n) {
        f[x][y] = s[i];
        rep (z, 4) {
            const int nd = (d+z)%4;
            const int nx = x+dx[nd], ny = y+dy[nd];
            if (nx >= 0 && nx < w && ny >= 0 && ny < h) {
                if (f[nx][ny] == -1) {
                    x = nx;
                    y = ny;
                    d = nd;
                    break;
                }
            }
        }
    }
    rep (i, w) rep (j, h) if (f[i][j] != f[i][0]) return false;
    return true;
}

int solve(string s) {
    const int n = s.size();
    int ans = -1;
    for (int i = 2; i < n; i++) if (n%i == 0) {
        if (can(s, i, n/i)) {
            if (ans == -1 || ans > i+n/i) ans = i+n/i;
        }
    }
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    rep (_q, T) {
        string s;
        cin >> s;
        cout << "Case " << _q+1 << ": " << solve(s) << endl;
    }
    return 0;
}
