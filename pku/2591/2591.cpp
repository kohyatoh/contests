#include <stdio.h>

int n, s[10000000];

int main() {
    s[0] = 1;
    for(int k=1, i2=0, i3=0; k<10000000; k++) {
        s[k] = 2*s[i2]<3*s[i3] ? 2*s[i2]+1 : 3*s[i3]+1;
        if(s[k]==2*s[i2]+1) i2++;
        if(s[k]==3*s[i3]+1) i3++;
    }
    while(scanf("%d", &n)!=EOF) printf("%d\n", s[n-1]);
    return 0;
}

