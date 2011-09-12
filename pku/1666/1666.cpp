#include <stdio.h>
#include <vector>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int main() {
    for(;;) {
        int n;
        scanf("%d", &n);
        if(n==0) return 0;
        vector<int> v(n), tv(n);
        rep(i, n) scanf("%d", &v[i]);
        int k=0;
        bool f=true;
        while(f) {
            k++;
            rep(i, n) tv[(i+n-1)%n]=v[i]/2;
            rep(i, n) {
                v[i]=v[i]/2+tv[i];
                if(v[i]%2) v[i]++;
            }
            f=false;
            rep(i, n-1) if(v[i]!=v[i+1]) f=true;
        }
        printf("%d %d\n", k, v[0]);
    }
}

