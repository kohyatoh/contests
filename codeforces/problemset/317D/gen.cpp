#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <set>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define n (30)
#define nn (1<<n)

int *a, b[n];

int f(int k) {
    if (k == 0) return 0;
    if (a[k] != 0) return a[k];
    set<int> st;
    rep (j, n) if (k&(1<<j)) {
        st.insert(f(k&(nn-1-b[j])));
    }
    for (int i = 0; ; i++) {
        if (!st.count(i)) {
            return a[k] = i;
        }
    }
}

int main() {
    a = (int*)malloc(sizeof(int) * nn);
    memset(a, 0, sizeof(int) * nn);
    rep (i, n) {
        b[i] |= 1<<i;
        for (int j = i; j < n; j += i+1) b[i] |= 1<<j;
    }
    rep (i, n) {
        rep (j, n) printf("%d", (b[i]&(1<<j)) > 0);
        printf("\n");
    }
    rep (i, n) printf("%d,", f((1<<i)-1));
    printf("\n");
    return 0;
}
