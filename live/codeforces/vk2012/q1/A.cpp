#include <stdio.h>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int n, k, a[200];

int main() {
    scanf("%d%d", &n, &k);
    rep (i, n) scanf("%d", a+i);
    while (n && a[n-1] == 0) n--;
    if (k > n) k = n;
    while (k < n && a[k]==a[k-1]) k++;
    printf("%d\n", k);
    return 0;
}
