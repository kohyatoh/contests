#include <stdio.h>
#include <algorithm>

int n, cnt[4];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char ch;
        scanf(" %c", &ch);
        cnt[ch - '1']++;
    }
    printf("%d %d\n",
            *std::max_element(cnt, cnt+4),
            *std::min_element(cnt, cnt+4));
    return 0;
}
