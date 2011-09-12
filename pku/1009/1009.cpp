#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int w, n, p[2000], s[2000], sum, x[2000];
int zn, z[6000];

int main() {
    for(;;) {
        scanf("%d", &w);
        printf("%d\n", w);
        if(w==0) return 0;
        n=-1, sum=0;
        do {
            n++;
            scanf("%d%d", p+n, s+n);
            x[n]=sum;
            sum+=s[n];
        } while(p[n]>0 || s[n]>0);
        x[n]=sum;
        int rp=-1, rs=0;
        rep(i, n) {
            zn = 0;
            z[zn++] = x[i];
            if(s[i]>1) z[zn++] = x[i]+1;
            z[zn++] = x[i+1];
            if(s[i]>1) z[zn++] = x[i+1]-1;
            rep(j, i) {
                if(x[i]<x[j]+w && x[j]+w<x[i+1]) z[zn++]=x[j]+w;
                if(x[i]<x[j]+w-1 && x[j]+w-1<x[i+1]) z[zn++]=x[j]+w-1;
                if(x[i]<x[j]+w+1 && x[j]+w+1<x[i+1]) z[zn++]=x[j]+w+1;
                if(x[i]<x[j+1]+w && x[j+1]+w<x[i+1]) z[zn++]=x[j+1]+w;
                if(x[i]<x[j+1]+w-1 && x[j+1]+w-1<x[i+1]) z[zn++]=x[j+1]+w-1;
                if(x[i]<x[j+1]+w+1 && x[j+1]+w+1<x[i+1]) z[zn++]=x[j+1]+w+1;
            }
            for(int j=i+1; j<n; j++) {
                if(x[i]<x[j]-w && x[j]-w<x[i+1]) z[zn++]=x[j]-w;
                if(x[i]<x[j]-w-1 && x[j]-w-1<x[i+1]) z[zn++]=x[j]-w-1;
                if(x[i]<x[j]-w+1 && x[j]-w+1<x[i+1]) z[zn++]=x[j]-w+1;
                if(x[i]<x[j+1]-w && x[j+1]-w<x[i+1]) z[zn++]=x[j+1]-w;
                if(x[i]<x[j+1]-w-1 && x[j+1]-w-1<x[i+1]) z[zn++]=x[j+1]-w-1;
                if(x[i]<x[j+1]-w+1 && x[j+1]-w+1<x[i+1]) z[zn++]=x[j+1]-w+1;
            }
            std::sort(z, z+zn);
            zn = std::unique(z, z+zn)-z;
            int a=0, b=i;
            rep(j, zn-1) {
                while(a<i && x[a+1]+w<=z[j]) a++;
                while(b<n && x[b+1]-w<=z[j]) b++;
                int md=0;
                if(j==0 && x[i]%w) md=max(md, abs(p[i]-p[i-1]));
                if(j==zn-2 && (x[i+1])%w) md=max(md, abs(p[i]-p[i+1]));
                if(a<i && x[a]+w<=z[j]) md=max(md, abs(p[i]-p[a]));
                if(0<a && x[a]+w==z[j] && z[j]%w) md=max(md, abs(p[i]-p[a-1]));
                if(a<i && x[a+1]+w==z[j+1] && (z[j+1])%w) md=max(md, abs(p[i]-p[a+1]));
                if(b<n && x[b]-w<=z[j]) md=max(md, abs(p[i]-p[b]));
                if(i<b && x[b]-w==z[j] && z[j]%w) md=max(md, abs(p[i]-p[b-1]));
                if(b<n && x[b+1]-w==z[j+1] && (z[j+1])%w) md=max(md, abs(p[i]-p[b+1]));
                if(rp==md) rs+=z[j+1]-z[j];
                else {
                    if(rp>=0) printf("%d %d\n", rp, rs);
                    rp=md, rs=z[j+1]-z[j];
                }
            }
        }
        printf("%d %d\n", rp, rs);
        printf("%d %d\n", 0, 0);
    }
}
