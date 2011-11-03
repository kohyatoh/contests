#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

char word[256];
int cnt[32];

int main() {
    int N, M, P;
    scanf("%d%d%d", &N, &M, &P);
    rep(i, N) rep(j, M) {
        char ch;
        scanf(" %c", &ch);
        cnt[ch-'A']++;
    }
    rep(i, P) {
        scanf("%s", word);
        for(int i=0; word[i]; i++) cnt[word[i]-'A']--;
    }
    rep(i, 26) while(cnt[i]--) putchar(i+'A');
    putchar('\n');
    return 0;
}
