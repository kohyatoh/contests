#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, c[12], v[3];
char ch[3];

int value_of(char ch) {
    if('0'<=ch && ch<='9') return ch-'0';
    if(ch=='A') return 11;
    return 10;
}

int main() {
    for(int z=0;; z++) {
        scanf("%d", &n);
        if(n==0) return 0;
        rep(i, 12) c[i]=4*n;
        c[0]=c[1]=0;
        c[10]=4*4*n;
        rep(i, 3) {
            scanf(" %c", ch+i);
            v[i]=value_of(ch[i]);
            c[v[i]]--;
        }
        int p=v[1]+v[2];
        if(p>21) p=12;
        double ans=0;
        rep(i, p) {
            int r=i-v[0];
            if(r>0 && r<12) ans += 1.*c[r]/(52*n-3);
            if(v[0]==11 && i==12) ans += 1.*c[11]/(52*n-3);
        }
        if(z>0) printf("\n");
        printf("%.3f%%\n", ans*100);
    }
}
