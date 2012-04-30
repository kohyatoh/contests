#include <stdio.h>
#include <stdlib.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
    int n, m, x1, y1, x2, y2;
    scanf("%d%d%d%d%d%d", &n, &m, &x1, &y1, &x2, &y2);
    bool first = false;
    rep (d, 4) {
        const int x = x1 + dx[d];
        const int y = y1 + dy[d];
        if (x < 1 || x > n || y < 1 || y > m) continue;
        const int a = abs(x-x2), b = abs(y-y2);
        if (a <= 3 && b <= 3 && (a != 3 || b != 3)) first = true;
    }
    puts(first ? "First" : "Second");
    return 0;
}
