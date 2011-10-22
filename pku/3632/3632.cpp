#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int a[40];

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        rep(i, n) scanf("%d", a+i);
        printf("%d\n", (*max_element(a, a+n)-*min_element(a, a+n))*2);
    }
    return 0;
}
