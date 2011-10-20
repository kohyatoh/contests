#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int parse(char *p) {
    int a = (p[0]-'0')*10+p[1]-'0';
    int e = p[3]-'0';
    while(e--) a *= 10;
    return a;
}

int solve(int n) {
    if(n==1) return 0;
    if(n%2==0) return solve(n/2)*2;
    return (solve(n-1)+2)%n;
}

int main() {
    char buf[8];
    for(;;) {
        scanf("%s", buf);
        const int n = parse(buf);
        if(n==0) return 0;
        printf("%d\n", solve(n)+1);
    }
}
