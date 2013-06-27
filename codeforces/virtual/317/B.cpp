#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair
typedef long long Int;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int cnt[80][80], ok[80][80];

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    cnt[0][0] = n;
    bool cont = true;
    while (cont) {
        cont = false;
        rep (i, 80) rep (j, 80) ok[i][j] = cnt[i][j] >= 4;
        rep (i, 80) rep (j, 80) if (ok[i][j]) {
            const int am = cnt[i][j] / 4;
            cnt[i][j] -= 4*am;
            cont = true;
            rep (d, 4) {
                const int nx = i + dx[d], ny = j + dy[d];
                if (nx < 0 || ny < 0) continue;
                cnt[nx][ny] += am;
                if (i != 0 && nx == 0) cnt[nx][ny] += am;
                if (j != 0 && ny == 0) cnt[nx][ny] += am;
            }
        }
    }
//    rep (i, 10) {
//        rep (j, 10) printf("%d ", cnt[i][j]);
//        printf("\n");
//    }
    rep (_, q) {
        int x, y;
        scanf("%d%d", &x, &y);
        x = abs(x), y = abs(y);
        printf("%d\n", x < 80 && y < 80 ? cnt[x][y] : 0);
    }
    return 0;
}
