#include <stdio.h>
#include <ctype.h>

char f[1024];
int p;

bool sentence() {
    if(f[p]=='\0' || isspace(f[p])) return false;
    const char ch = f[p++];
    if('p'<=ch && ch<='z') return true;
    else if(ch=='N') return sentence();
    else if(ch=='C' || ch=='D' || ch=='E' || ch=='I') return sentence() && sentence();
    return false;
}

bool check() {
    p = 0;
    if(!sentence()) return false;
    return f[p]=='\0' || isspace(f[p]);
}

int main() {
    while(scanf(" %s", f)!=EOF) puts(check() ? "YES" : "NO");
    return 0;
}
