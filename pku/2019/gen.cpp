#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int n=250, b=rand()%(n-3), k=100000;
    printf("%d %d %d\n", n, b, k);
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) {
        printf("%d%c", rand()%251, j==n-1 ? '\n' : ' ');
    }
    int w=n-b+1;
    for(int i=0; i<k; i++) {
        printf("%d %d\n", rand()%w+1, rand()%w+1);
    }
    return 0;
}
