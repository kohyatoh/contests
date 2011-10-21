#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
    int b, w;
    scanf("%d%d", &b, &w);
    if(b>w) swap(b, w);
    int ans = w ? 1 : -1;
    for(int i=2; i*i<=b+w; i++) if(i*i/2<=b && i*i-i*i/2<=w) ans = i;
    if(ans==-1) puts("Impossible");
    else printf("%d\n", ans);
    return 0;
}
