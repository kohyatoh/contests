#include <unistd.h>

int N, n;
double fv[1000000];
char* fp[1000000];
char buf[15000000];

char* select(int k) {
    int l=0, r=N-1;
    register char* tp;
    register double tv;
    while(l<r) {
        register double d = (fv[l]+fv[r])/2;
        register int i=l-1, j=r+1;
        for(;;) {
            while(fv[++i]<d);
            while(fv[--j]>d);
            if(i>=j) break;
            tv = fv[i];
            fv[i] = fv[j];
            fv[j] = tv;
            tp = fp[i];
            fp[i] = fp[j];
            fp[j] = tp;
        }
        if(k<i) r=i-1;
        else l=j+1;
    }
    return fp[k];
}

int main() {
    int i, c;
    register char* s=buf;
    while(c=read(0, s, 15000000)) s+=c;
    s=buf;
    while(*s!=' ') { N*=10; N+=(*s)-'0'; s++; }
    s++;
    while(*s!='\n') { n*=10; n+=(*s)-'0'; s++; }
    s++;
    for(i=0; i<N; i++) {
        register int a=0, b=0;
        c=1;
        fp[i] = s;
        if(*s=='-') { c*=-1; s++; }
        while(*s!='/') { a*=10; a+=(*s)-'0'; s++; }
        s++;
        if(*s=='-') { c*=-1; s++; }
        while(*s!='\n') { b*=10; b+=(*s)-'0'; s++; }
        s++;
        fv[i] = c*a/(double)b;
    }
    s = select(N-n);
    c = 0;
    while(*(s+c++)!='\n');
    write(1, s, c);
    return 0;
}
