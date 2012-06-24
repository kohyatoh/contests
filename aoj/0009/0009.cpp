#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int ni[1000000], sum[1000000];

int main() {
    ni[0] = ni[1] = 1;
    for (int i = 2; i < 1000000; i++) if (ni[i] == 0) {
        for (int j = i+i; j < 1000000; j+=i) ni[j] = 1;
    }
    for (int i = 1; i < 1000000; i++) sum[i] = sum[i-1] + 1-ni[i];
    int n;
    while (scanf("%d", &n) != EOF) printf("%d\n", sum[n]);
    return 0;
}
