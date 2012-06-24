#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int a[16];

bool rec() {
    int f = -1;
    rep (i, 9) if (a[i]) { f = i; break; }
    if (f == -1) return true;
    bool ans = false;
    if (a[f] >= 3) {
        a[f] -= 3;
        ans |= rec();
        a[f] += 3;
    }
    if (ans) return true;
    if (a[f] && a[f+1] && a[f+2]) {
        rep (i, 3) a[f+i]--;
        ans |= rec();
        rep (i, 3) a[f+i]++;
    }
    return ans;
}

bool is() {
    rep (i, 9) if (a[i] > 4) return false;
    bool ans = false;
    rep (i, 9) if (a[i] >= 2) {
        a[i] -= 2;
        ans |= rec();
        a[i] += 2;
        if (ans) return true;
    }
    return ans;
}

int main() {
    char buf[16];
    while (scanf("%s", buf) != EOF) {
        rep (i, 16) a[i] = 0;
        rep (i, 13) a[buf[i]-'1']++;
        bool f = false;
        rep (i, 9) {
            a[i]++;
            if (is()) {
                if (f) putchar(' ');
                f = true;
                printf("%d", i+1);
            }
            a[i]--;
        }
        if (!f) putchar('0');
        putchar('\n');
    }
}
