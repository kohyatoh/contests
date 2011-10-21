#include <stdio.h>
#include <algorithm>
#include <numeric>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

char of[4][4] = {"", ".25", ".5", ".75"};

int main() {
    int a[6];
    for(;;) {
        rep(i, 6) scanf("%d", a+i);
        const int s = accumulate(a, a+6, 0);
        if(s==0) return 0;
        const int p = s - *max_element(a, a+6) - *min_element(a, a+6);
        printf("%d%s\n", p/4, of[p%4]);
    }
}
