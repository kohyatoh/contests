#include <stdio.h>
#include <math.h>

int main() {
    int n, e, d, ns=0, es=0;
    scanf("%d%d", &n, &e);
    while(--n) { scanf("%d", &d); ns+=d; }
    while(--e) { scanf("%d", &d); es+=d; }
    printf("%d\n", (int)ceil(sqrt((double)ns*ns+es*es)));
    return 0;
}

