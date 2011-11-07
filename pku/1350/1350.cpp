#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int main() {
    char f[8], g[8];
    for(;;) {
        int n;
        scanf("%d", &n);
        if(n==-1) return 0;
        bool ok = true;
        if(n<1000 || n>9999) ok = false;
        sprintf(f, "%d", n);
        bool same = true;
        rep(i, 4) if(f[0]!=f[i]) same = false;
        if(same) ok = false;
        printf("N=%d:\n", n);
        if(!ok) puts("No!!");
        else {
            int k = 0;
            while(n!=6174 && n!=0) {
                k++;
                sprintf(f, "%d", n);
                const int L = strlen(f);
                sort(f, f+L);
                memcpy(g, f, sizeof(f));
                reverse(f, f+L);
                n = atoi(f)-atoi(g);
                printf("%d-%d=%d\n", atoi(f), atoi(g), n);
            }
            printf("Ok!! %d times\n", k);
        }
    }
}
