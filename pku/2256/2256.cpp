#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

double v[3];

int of(char ch) {
    if(ch=='I') return 0;
    if(ch=='U') return 1;
    return 2;
}

double val(const char *p) {
    double v=atof(p);
    while(('0'<=*p && *p<='9') || *p=='.') p++;
    if(*p=='m') return v*0.001;
    if(*p=='k') return v*1000;
    if(*p=='M') return v*1000000;
    return v;
}

int main() {
    string s;
    getline(cin, s);
    int T=atoi(s.c_str());
    rep(q, T) {
        getline(cin, s);
        rep(i, 3) v[i]=-1;
        rep(i, s.size()) if(s[i]=='=') v[of(s[i-1])] = val(s.c_str()+i+1);
        printf("Problem #%d\n", q+1);
        if(v[0]==-1) printf("I=%.2fA\n", v[2]/v[1]);
        if(v[1]==-1) printf("U=%.2fV\n", v[2]/v[0]);
        if(v[2]==-1) printf("P=%.2fW\n", v[0]*v[1]);
        puts("");
    }
    return 0;
}

