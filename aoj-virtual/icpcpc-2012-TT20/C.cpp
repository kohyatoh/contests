#include <stdio.h>
#include <string.h>
#include <string>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const char chars[] = "WAKJSD";

int H, W, f[512][512], of[512][512];
char buf[512];


int decode(char c) {
    if ('0' <= c && c <= '9') return c - '0';
    else return c - 'a' + 10;
}

void draw(int x, int y, int o, int w) {
    if (f[x][y] != o) return ;
    if (of[x][y] != -1) return ;
    of[x][y] = w;
    rep (d, 4) draw(x+dx[d], y+dy[d], o, w);
}

int main() {
    for (int _q = 0;; _q++) {
        scanf("%d%d", &H, &W);
        if (H == 0) return 0;
        memset(f, 0, sizeof(f));
        memset(of, -1, sizeof(of));
        rep (k, H) {
            scanf(" %s", buf);
            rep (i, W) {
                const int b = decode(buf[i]);
                rep (j, 4) if (b&(1<<(3-j))) f[k+2][2+4*i+j] = 1;
            }
        }
        W *= 4;
        rep (i, H+4) f[i][0] = f[i][W+3] = 1;
        rep (i, W+4) f[0][i] = f[H+3][i] = 1;
        rep (i, H+4) of[i][0] = of[i][W+3] = -2;
        rep (i, W+4) of[0][i] = of[H+3][i] = -2;
/*        rep (i, H+4) {
            rep (j, W+4) printf("%d", f[i][j]);
            printf("\n");
        }*/
        int n = 0;
        set<int> bk;
        for (int i = 1; i < H+3; i++) for (int j = 1; j < W+3; j++) {
            if (of[i][j] == -1) {
                if (f[i][j]) bk.insert(n);
                draw(i, j, f[i][j], n++);
            }
        }
/*        rep (i, H+4) {
            rep (j, W+4) printf("%d ", of[i][j]);
            printf("\n");
        }*/
        map<int, set<int> > ks;
        for (int i = 1; i < H+3; i++) for (int j = 1; j < W+3; j++) {
            if (f[i][j] == 0) {
                rep (d, 4) {
                    const int x = i+dx[d];
                    const int y = j+dy[d];
                    if (f[x][y] == 1) ks[of[i][j]].insert(of[x][y]);
                }
            }
        }
        for (int i = 1; i < H+3; i++) for (int j = 1; j < W+3; j++) {
            if (f[i][j] == 1) {
                rep (d, 4) {
                    const int x = i+dx[d];
                    const int y = j+dy[d];
                    if (f[x][y] == 0 && ks[of[x][y]].size() == 1) {
                        ks[of[i][j]].insert(of[x][y]);
                    }
                }
            }
        }
        string ans;
        for (set<int>::iterator it = bk.begin(); it != bk.end(); ++it) {
            const int m = ks[*it].size();
            ans += chars[m];
        }
        sort(ans.begin(), ans.end());
        printf("Case %d: %s\n", _q+1, ans.c_str());
    }
}
