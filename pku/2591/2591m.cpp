#include <stdio.h>

int n, k, i2, i3, s[10000000];

int main() {
    s[0] = 1;
    k = 1;
    while(scanf("%d", &n)!=EOF) {
        for(; k<n; k++) {
            if(2*s[i2]==3*s[i3]) {
                s[k] = 2*s[i2]+1;
                i2++, i3++;
            }
            else if(2*s[i2]<3*s[i3]) {
                s[k] = 2*s[i2]+1;
                i2++;
            }
            else {
                s[k] = 3*s[i3]+1;
                i3++;
            }
        }
        printf("%d\n", s[n-1]);
    }
    return 0;
}

