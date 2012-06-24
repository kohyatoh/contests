#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int a[10];

int main() {
    rep (i, 10) scanf("%d", a+i);
    sort(a, a+10);
    reverse(a, a+10);
    rep (i, 3) printf("%d\n", a[i]);
    return 0;
}
