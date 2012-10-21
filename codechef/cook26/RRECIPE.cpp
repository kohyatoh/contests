#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long Int;
#define MOD (10000009)

char s[2000000];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", s);
        const int n = strlen(s);
        Int ans = 1;
        for (int i = 0; i <= n-1-i; i++) {
            if (s[i] == '?' && s[n-1-i] == '?') ans = (ans * 26) % MOD;
            if (s[i] != '?' && s[n-1-i] != '?' && s[i] != s[n-1-i]) ans = 0;
        }
        cout << ans << endl;
    }
    return 0;
}
