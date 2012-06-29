#include <stdio.h>
#include <string.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

bool pal(const char *s) {
    const int n = strlen(s);
    rep (i, n) if (s[i] != s[n-1-i]) return false;
    return true;
}

int main() {
    int ans = 0;
    char s[128];
    while (scanf("%s", s) != EOF) if (pal(s)) ans++;
    printf("%d\n", ans);
    return 0;
}
