#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, v[1000], s;

int main() {
    for(;;) {
        n=0;
        do {
            if(scanf("%d", v+n++)==EOF) return 0;
        } while(v[n-1]);
        for(;;) {
            scanf("%d", &s);
            if(s==0) break;
            int ans[4], maxt=0, minn=5, maxv=0, z[4];
            ans[0] = -1;
            rep(a, n) rep(b, a+1) rep(c, b+1) rep(d, c+1) {
                if(v[a]+v[b]+v[c]+v[d]!=s) continue;
                int t=(a>b)+(b>c)+(c>d)+(v[a]>0);
                int n=(v[a]>0)+(v[b]>0)+(v[c]>0)+(v[d]>0);
                int mv=std::max(std::max(v[a], v[b]), std::max(v[c], v[d]));
                bool f=false;
                if(maxt<t) f=true;
                else if(maxt==t) {
                    if(minn>n) f=true;
                    else if(minn==n) {
                        if(maxv<mv) f=true;
                        else if(maxv==mv) ans[0]=-2;
                    }
                }
                if(f) {
                    maxt=t, minn=n, maxv=mv;
                    ans[0]=d, ans[1]=c, ans[2]=b, ans[3]=a;
                }
            }
            if(ans[0]==-1) printf("%d ---- none\n", s);
            else if(ans[0]==-2) printf("%d (%d): tie\n", s, maxt);
            else {
                printf("%d (%d):", s, maxt);
                rep(i, 4) if(v[ans[i]]) printf(" %d", v[ans[i]]);
                putchar('\n');
            }
        }
    }
}
