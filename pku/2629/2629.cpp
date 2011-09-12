#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int cnt[2][26];
char a[2][2000];

int main() {
    while(gets(a[0])) {
        gets(a[1]);
        memset(cnt, 0, sizeof(cnt));
        rep(i, 2) for(char *p=a[i]; *p; *p++) cnt[i][*p-'a']++;
        rep(c, 26) rep(i, min(cnt[0][c], cnt[1][c])) putchar(c+'a');
        putchar('\n');
    }
    return 0;
}
