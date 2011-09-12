#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

static const int dat[3] = {10, 12, 16};

int main() {
    for(int x=2992; x<10000; x++) {
        int s[3] = {0, 0, 0};
        rep(i, 3) for(int b=x; b; b/=dat[i]) s[i]+=b%dat[i];
        if(s[0]==s[1] && s[1]==s[2]) printf("%d\n", x);
    }
    return 0;
}
