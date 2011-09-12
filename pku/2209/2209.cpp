#include <stdio.h>

int ipow(int a, int p) { int r=1; while(p--) r*=a; return r; }
int n, p;

int main() {
    scanf("%d%d", &n, &p);
    int s=0, a;
    while(n--) {
        scanf("%d", &a);
        int f=ipow(a, p);
        if(f>0) s+=f;
    }
    printf("%d\n", s);
    return 0;
}
