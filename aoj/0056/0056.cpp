#include <stdio.h>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#define NUM (60000)
int pt[NUM];
int cnt[NUM];

int main() {
    vector<int> ps;
    for (int i = 2; i < NUM; i++) if (pt[i] == 0) {
        ps.push_back(i);
        for (int j = i+i; j < NUM; j+=i) pt[j] = i;
    }
    rep (i, ps.size()) rep (j, i+1) {
        if (ps[i]+ps[j] >= NUM) break;
        cnt[ps[i]+ps[j]]++;
    }
    for (;;) {
        int n;
        scanf("%d", &n);
        if (n == 0) return 0;
        printf("%d\n", cnt[n]);
    }
}
