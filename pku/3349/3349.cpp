#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define HS (1<<22)
#define P (10000007)

int hash(const int *a) {
    unsigned h = 0;
    rep(i, 6) h = h*P+a[i];
    return h%HS;
}

bool less(const int *a, const int *b) {
    rep(i, 6) {
        if(a[i]<b[i]) return true;
        if(a[i]>b[i]) return false;
    }
    return false;
}

bool same(const int *a, const int *b) {
    rep(i, 6) if(a[i]!=b[i]) return false;
    return true;
}

int n, a[6], b[6], w[100000][6], next[100000], head[HS];

int main() {
    memset(head, -1, sizeof(head));
    scanf("%d", &n);
    rep(k, n) {
        rep(i, 6) scanf(" %d", a+i);
        rep(i, 6) b[i] = a[i];
        rep(r, 12) {
            if(r==6) reverse(a, a+6);
            rotate(a, a+1, a+6);
            if(less(a, b)) rep(i, 6) b[i] = a[i];
        }
        const int h = hash(b);
        for(int x=head[h]; x!=-1; x=next[x]) if(same(b, w[x])) {
            puts("Twin snowflakes found.");
            return 0;
        }
        rep(i, 6) w[k][i] = b[i];
        next[k] = head[h];
        head[h] = k;
    }
    puts("No two snowflakes are alike.");
    return 0;
}
