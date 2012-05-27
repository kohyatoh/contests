#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int N, M, K, A[16], B[16];

bool is(int *a) {
    static int loc[16];
    rep (i, N) loc[a[i]] = i;
    rep (i, M) {
        if (a[(loc[A[i]]+1)%N] == B[i]) return false;
        if (a[(loc[A[i]]-1+N)%N] == B[i]) return false;
    }
    return true;
}

bool dig() {
    static int a[16];
    rep (i, N) a[i] = i;
    rep (_, K) {
        int i = rand() % N;
        int j = rand() % (N-1);
        if (i <= j) j++;
        swap(a[i], a[j]);
    }
    return is(a);
}

int main() {
    scanf("%d%d%d", &N, &M, &K);
    rep (i, M) scanf("%d%d", A+i, B+i);
    int hit = 0, sum = 0;
    rep (i, 1000000) {
        sum++;
        if (dig()) hit++;
    }
    printf("%.9f\n", (double)hit/sum);
    return 0;
}
