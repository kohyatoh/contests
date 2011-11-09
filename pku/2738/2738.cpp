#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

vector<int> zAlgorithm(int n, const char *f) {
    vector<int> z(n, 0);
    z[0] = n;
    int l = 0, r = 0;
    for(int k=1; k<n; k++) {
        if(k > r) {
            int i = k;
            while(i<n && f[i]==f[i-k]) i++;
            if(i>k) { z[k] = i-k; l = k; r = i-1; }
        }
        else {
            if(z[k-l]<r-k+1) z[k] = z[k-l];
            else {
                int i = r+1;
                while(i<n && f[i]==f[i-k]) i++;
                z[k] = i-k; l = k; r = i-1;
            }
        }
    }
    return z;
}

char f[500000];

int main() {
    while(scanf(" %s", f)!=EOF) {
        const int n = strlen(f);
        vector<int> z = zAlgorithm(n, f);
        bool first = true;
        for(int i=n-1; i>=0; i--) if(z[i]==n-i) {
            if(!first) putchar(' ');
            first = false;
            printf("%d", z[i]);
        }
        putchar('\n');
    }
    return 0;
}
