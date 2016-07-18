#include <stdio.h>
#include <string.h>
using namespace std;

int xs[10], ys[10];
char f[10*10];

int rec(int k) {
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < i; j++) {
            if (xs[i] == xs[j] || ys[i] == ys[j]
                    || xs[i] - ys[i] == xs[j] - ys[j]
                    || xs[i] + ys[i] == xs[j] + ys[j]) return 0;
        }
    }
    if (k == 8) return 1;
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            xs[k] = x;
            ys[k] = y;
            if (rec(k + 1)) return 1;
        }
    }
    return 0;
}

int main() {
    int k = 0;
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            char c;
            scanf(" %c", &c);
            if (c == 'Q') {
                xs[k] = x;
                ys[k] = y;
                k++;
            }
        }
    }
    if (rec(k)) {
        memset(f, '.', sizeof(f));
        for (int i = 0; i < 8; i++) {
            f[xs[i] * 8 + ys[i]] = 'Q';
        }
        for (int x = 0; x < 8; x++) {
            for (int y = 0; y < 8; y++) {
                putchar(f[x * 8 + y]);
            }
            putchar('\n');
        }
    } else {
        puts("No Answer");
    }
    return 0;
}
