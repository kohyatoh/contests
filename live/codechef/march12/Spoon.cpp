#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int n, m;
char p[128][128];

bool solve() {
    rep (i, n) {
        if (string(p[i]).find("spoon") != string::npos) return true;
    }
    rep (i, m) {
        string s(n, 0);
        rep (j, n) s[j] = p[j][i];
        if (s.find("spoon") != string::npos) return true;
    }
    return false;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        rep (i, n) scanf(" %s", p[i]);
        rep (i, n) rep (j, m) if (p[i][j] < 'Z') p[i][j] += 'a' - 'A';
        puts(solve() ? "There is a spoon!" : "There is indeed no spoon!");
    }
    return 0;
}
