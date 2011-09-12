#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

bool np[1000000];
int k, ps[100000], of[1000000];

int main() {
    np[1] = true;
    for(int i=3; i<1000; i+=2) if(!np[i]) {
        for(int j=i*i; j<1000000; j+=i) np[j]=true;
    }
    for(int i=3; i<1000000; i+=2) if(!np[i]) ps[k++]=i;
    for(;;) {
        int n;
        scanf("%d", &n);
        if(n==0) return 0;
        rep(i, k) if(!np[n-ps[i]]) {
            printf("%d = %d + %d\n", n, ps[i], n-ps[i]);
            break;
        }
    }
}
