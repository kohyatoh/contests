#include <stdio.h>
#include <string.h>

char f[1000001], g[1000001];

int main() {
    for(int _q=0;; _q++) {
        gets(f);
        if(strcmp(f, "0")==0) return 0;
        const int n = strlen(f);
        int carry = 0;
        for(int i=n-1; i>=0; i--) {
            g[i] = f[i] - carry;
            if(i<n-1) g[i] -= (g[i+1]-'0');
            carry = g[i]<'0';
            if(carry) g[i] += 10;
        }
        g[n] = '\0';
        printf("%d. ", _q+1);
        puts(g[0]!='0' ? g : "IMPOSSIBLE");
    }
}
