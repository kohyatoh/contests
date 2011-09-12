#include <stdio.h>

int n, pt[30000];

int main() {
    for(int i=2; i<30000; i++) if(pt[i]==0) {
        for(int j=i+i; j<30000; j+=i) pt[j] = i;
    }
    scanf("%d", &n);
    int ans=1, maxp=0;
    while(n--) {
        int a;
        scanf("%d", &a);
        const int p = pt[a]==0 ? a : pt[a];
        if(maxp < p) maxp=p, ans=a;
    }
    printf("%d\n", ans);
    return 0;
}
