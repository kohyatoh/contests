#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    for(int i=0; i<10; i++) {
        //int n=rand()%100+1;
        int n=100;
        //int m=rand()%100001;
        int m=100000;
        printf("%d %d\n", n, m);
        for(int k=0; k<n; k++) {
            printf("%d ", rand()%100000);
        }
        for(int k=0; k<n; k++) {
            printf("%d ", rand()%1000+1);
        }
        printf("\n");
    }
    printf("0 0\n");
    return 0;
}

