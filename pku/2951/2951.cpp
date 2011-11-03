#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int memo[401][21][32];

int rec(int b, int w, int h) {
    if(w*h<=b) return 1;
    if(memo[b][w][h]!=0) return memo[b][w][h];
    int ans = w*h;
    for(int i=1; i<w; i++) ans = min(ans, rec(b, i, h)+rec(b, w-i, h));
    for(int i=1; i<h; i++) ans = min(ans, rec(b, w, i)+rec(b, w, h-i));
    return memo[b][w][h] = ans;
}

int main() {
    for(;;) {
        int w, h, m;
        scanf("%d%d%d", &w, &h, &m);
        if(w==0 && h==0 && m==0) return 0;
        int l = 0, r = w*h;
        while(r-l>1) {
            const int mid = (l+r)/2;
            if(rec(mid, w, h)<=m) r = mid;
            else l = mid;
        }
        printf("%d\n", r);
    }
}
