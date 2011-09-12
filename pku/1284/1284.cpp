#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int pt[100000], cnt[100000];

int main() {
    for(int i=4; i<100000; i+=2) pt[i]=2;
    for(int i=3; i<1000; i+=2) if(pt[i]==0) {
        for(int j=i*i; j<100000; j+=i) pt[j] = i;
    }
    for(int i=2; i<100000; i++) {
        cnt[i] = i;
        for(int p=i; p>1; ) {
            int b = pt[p] ? pt[p] : p;
            cnt[i] -= cnt[i]/b;
            while(p%b==0) p/=b;
        }
    }
    for(int p; scanf("%d", &p)!=EOF; ) printf("%d\n", cnt[p-1]);
    return 0;
}
