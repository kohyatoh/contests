#include <stdio.h>
#include <string>
#include <map>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

const string delim1="$", delim2="#", delim3="--";
int n, len[1000], cm[1000];
char s[100], s2[100];

int main() {
    for(;;) {
        map<string, int> id;
        for(n=0; ; n++) {
            scanf("%s", s);
            if(s==delim3) return 0;
            if(s==delim1) break;
            scanf("%d%d", len+n, cm+n);
            id[s] = n;
        }
        for(;;) {
            scanf("%s", s);
            if(s==delim2) break;
            int h, m;
            scanf("%s %d:%d", s2, &h, &m);
            m = (h*60+m)%(24*60);
            int st=id[s], et=id[s2], c=0, d=0, t=0, nc=0;
            for(int k=st; k<=et; k++) {
                t += len[k]*cm[k];
                rep(i, len[k]) {
                    d++;
                    if(d<=10) nc = 1000;
                    else if(d<=30) nc = 250;
                    else nc = 100;
                    int me = m+cm[k];
                    if(me>=24*60) m-=24*60, me-=24*60;
                    if(m<6*60 && me>0) c += nc/5*6;
                    else c += nc;
                    m = me%(24*60);
                }
            }
            if(2*d<t) c += c/10;
            printf("%d\n", c);
        }
    }
}

