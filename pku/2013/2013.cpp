#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n;
char name[200][200];

void print(int i) {
    printf("%s\n", name[i]);
    if(i+2<n) print(i+2);
    if(i+1<n) printf("%s\n", name[i+1]);
}

int main() {
    for(int q=0;; q++) {
        scanf("%d", &n);
        if(n==0) return 0;
        rep(i, n) scanf("%s", name[i]);
        printf("SET %d\n", q+1);
        print(0);
    }
}
