#include <stdio.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

char s[256];
int ix, v[8];

int term() {
    char ch = s[ix++];
    if('p'<=ch && ch<='t') return v[ch-'p'];
    if(ch=='N') return 1-term();
    const int l=term(), r=term();
    if(ch=='K') return l&&r;
    if(ch=='A') return l||r;
    if(ch=='C') return !l||r;
    if(ch=='E') return l==r;
    return -1;
}

int parse(int b) {
    rep(i, 5) v[i] = (b&(1<<i))>0;
    ix = 0;
    return term();
}

int main() {
    for(;;) {
        gets(s);
        if(s[0]=='0') return 0;
        bool yes = true;
        rep(i, 1<<5) if(parse(i)==0) { yes=false; break; }
        puts(yes ? "tautology" : "not");
    }
}

