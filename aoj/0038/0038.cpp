#include <stdio.h>
#include <string.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int cnt[13], ty[8];

bool straight() {
    rep (k, 10) {
        bool f = true;
        rep (i, 5) if (cnt[(k+i)%13] == 0) f = false;
        if (f) return true;
    }
    return false;
}

int main() {
    int a, b, c, d, e;
    while (scanf("%d,%d,%d,%d,%d", &a, &b, &c, &d, &e) != EOF) {
        memset(cnt, 0, sizeof(cnt));
        memset(ty, 0, sizeof(ty));
        a--, b--, c--, d--, e--;
        cnt[a]++;
        cnt[b]++;
        cnt[c]++;
        cnt[d]++;
        cnt[e]++;
        rep (i, 13) ty[cnt[i]]++;
        if (ty[4]) puts("four card");
        else if (ty[2] && ty[3]) puts("full house");
        else if (straight()) puts("straight");
        else if (ty[3]) puts("three card");
        else if (ty[2] >= 2) puts("two pair");
        else if (ty[2] >= 1) puts("one pair");
        else puts("null");
    }
    return 0;
}
