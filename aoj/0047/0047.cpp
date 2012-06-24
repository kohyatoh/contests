#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int a[3] = { 1, 0, 0 };
    char x, y;
    while (scanf(" %c,%c", &x, &y) != EOF) swap(a[x-'A'], a[y-'A']);
    rep (i, 3) if (a[i]) putchar('A'+i);
    putchar('\n');
    return 0;
}
