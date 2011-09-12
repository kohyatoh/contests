#include <stdio.h>
#include <string.h>

int n;
char f[256];

bool can(int x, int dir) {
    while(x>=0 && x<n && f[x]!='.') {
        if(f[x]=='|' || f[x]=='/' || f[x]=='\\') return false;
        x += dir;
    }
    return true;
}

int main() {
    for(;;) {
        gets(f);
        if(f[0]=='#') return 0;
        n = strlen(f);
        double ans = 0;
        for(int i=0; i<n; i++) {
            if(f[i]=='.') ans += 1.0/n;
            if(f[i]=='/' && can(i-1, -1)) ans += 1.0/n;
            if(f[i]=='\\' && can(i+1, 1)) ans += 1.0/n;
            if(f[i]=='|') {
                if(can(i-1, -1)) ans += 0.5/n;
                if(can(i+1, 1)) ans += 0.5/n;
            }
        }
        printf("%d\n", (int)(ans*100));
    }
}
