#include <stdio.h>
#include <vector>
#include <map>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long Int;

int main() {
    for (;;) {
        int n;
        scanf("%d", &n);
        if (n == 0) return 0;
        map<int, Int> of;
        vector<int> ids;
        int c = 0;
        rep (_, n) {
            int id, p, q;
            scanf("%d%d%d", &id, &p, &q);
            ids.push_back(id);
            of[id] += (Int)p*q;
        }
        rep (i, n) if (of[ids[i]] >= 1000000) {
            printf("%d\n", ids[i]);
            of[ids[i]] = 0;
            c++;
        }
        if (c == 0) puts("NA");
    }
    return 0;
}
