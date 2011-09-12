#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

char a[20];

int main() {
    scanf("%s", a);
    int pos=-1;
    rep(i, 10) {
        if(a[i]=='?') pos=i;
        else if(a[i]=='X') a[i]=10;
        else a[i]-='0';
    }
    int ans=-1;
    rep(i, 11) {
        if(pos<9 && i==10) continue;
        a[pos]=i;
        int s=0;
        rep(j, 10) s+=a[j]*(10-j);
        if(s%11==0) { ans=i; break; }
    }
    if(ans==10) printf("X\n");
    else printf("%d\n", ans);
    return 0;
}
