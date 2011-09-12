#include <stdio.h>
#include <set>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int a[1000000], t[4000000];

int main() {
    std::set<int> s;
    rep(i, 500200) {
        t[a[i]]=1;
        if(a[i]<=i+1 || t[a[i]-i-1]) a[i+1]=a[i]+i+1;
        else a[i+1]=a[i]-i-1;
    }
    for(;;) {
        int k;
        scanf("%d", &k);
        if(k==-1) return 0;
        printf("%d\n", a[k]);
    }
}

