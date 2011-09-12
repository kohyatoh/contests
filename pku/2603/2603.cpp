#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int a[10], np[10000];

int main() {
    np[0]=np[1]=1;
    for(int i=4; i<10000; i+=2) np[i]=1;
    for(int i=3; i<10000; i+=2) if(np[i]==0) {
        for(int j=i*i; j<10000; j+=i) np[j]=1;
    }
    rep(i, 10) scanf("%d", a+i);
    int m=1;
    rep(k, 10000) if(np[k]==0) {
        int cnt=0;
        rep(i, 10) while(a[i]%k==0) a[i]/=k, cnt++;
        m = (m*(cnt+1))%10;
    }
    printf("%d\n", m);
    return 0;
}

