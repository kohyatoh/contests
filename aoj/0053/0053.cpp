#include <stdio.h>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#define NUM (200000)
int pt[NUM];
int sum[12000];

int main() {
    vector<int> ps;
    for (int i = 2; i < NUM; i++) if (pt[i] == 0) {
        ps.push_back(i);
        for (int j = i+i; j < NUM; j+=i) pt[j] = i;
    }
    rep (i, 10000) sum[i+1] = sum[i] + ps[i];
    for (;;) {
        int n;
        scanf("%d", &n);
        if (n == 0) return 0;
        printf("%d\n", sum[n]);
    }
}
