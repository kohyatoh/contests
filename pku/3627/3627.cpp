#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int N, B, a[30000];

int main() {
    scanf("%d%d", &N, &B);
    rep(i, N) scanf("%d", a+i);
    sort(a, a+N);
    reverse(a, a+N);
    int s = 0, c = 0;
    while(s<B) s += a[c++];
    printf("%d\n", c);
    return 0;
}
