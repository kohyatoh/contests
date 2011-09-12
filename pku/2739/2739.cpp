#include <stdio.h>

int n, np[20000], m, p[10000];

int main() {
    for(int i=3; i<400; i+=2) if(!np[i]) {
        for(int j=i*i; j<15000; j+=i) np[j]=1;
    }
    p[m++]=2;
    for(int i=3; i<15000; i+=2) if(!np[i]) p[m++]=i;
    for(;;) {
        scanf("%d", &n);
        if(n==0) return 0;
        int s=0, ans=0;
        for(int i=0, j=0; p[i]<=n; i++) {
            s+=p[i];
            while(j<i && s>n) s-=p[j++];
            if(s==n) ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}

