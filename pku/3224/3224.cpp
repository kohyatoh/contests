#include <stdio.h>
#include <algorithm>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, w[200];

int main() {
    scanf("%d", &n);
    rep(i, n) rep(j, n) {
        int x;
        scanf("%d", &x);
        if(x==3) w[i]++;
    }
    printf("%d\n", std::max_element(w, w+n)-w+1);
    return 0;
}

