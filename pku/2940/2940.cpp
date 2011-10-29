#include <stdio.h>
#include <iostream>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
typedef long long Int;

int main() {
    for(;;) {
        int n;
        scanf("%d", &n);
        if(n==0) return 0;
        Int ans = 0, cur = 0;
        while(n--) {
            int a;
            scanf("%d", &a);
            ans += cur>0 ? cur : -cur;
            cur += a;
        }
        cout << ans << endl;
    }
}
