#include <stdio.h>
#include <string.h>

int n, sh[100][4];

void decide(int at, int b, int p) {
    int c = p%4 ? p%4 : 4;
    if(p>4) {
        if(c==1) c=2;
        decide(at+1, b+2, p-c);
    }
    if(c>0) sh[at][0]=b;
    if(c>1) sh[at][1]=b+1;
    if(c>2) sh[at][2]=b+(p-c)+2;
    if(c>3) sh[at][3]=b+(p-c)+3;
}

void print(int n) { if(n>0) printf("%d", n); else printf("Blank"); }

int main() {
    for(;;) {
        scanf("%d", &n);
        if(n==0) return 0;
        memset(sh, 0, sizeof(sh));
        decide(0, 1, n);
        printf("Printing order for %d pages:\n", n);
        for(int i=0; sh[i][0]>0; i++) {
            printf("Sheet %d, front: ", i+1);
            print(sh[i][3]); printf(", "); print(sh[i][0]); printf("\n");
            if(sh[i][1]==0) break;
            printf("Sheet %d, back : ", i+1);
            print(sh[i][1]); printf(", "); print(sh[i][2]); printf("\n");
        }
    }
}

