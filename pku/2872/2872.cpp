#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int of(char ch) {
    if(ch=='-') return 0;
    if(ch=='\'') return 1;
    return ch-'a'+2;
}

struct Node {
    int is, ch[28];
    Node() { is = 0; memset(ch, -1, sizeof(ch)); }
};

char buf[1024];

int main() {
    gets(buf);
    int n = atoi(buf);
    vector<Node> vs(1);
    rep(_, n) {
        gets(buf);
        int cur = 0;
        for(int i=0; buf[i]; i++) {
            const int ix = of(buf[i]);
            if(vs[cur].ch[ix]==-1) {
                vs[cur].ch[ix] = vs.size();
                vs.push_back(Node());
            }
            cur = vs[cur].ch[ix];
        }
        vs[cur].is = 1;
    }
    gets(buf);
    int m = atoi(buf);
    rep(k, m) {
        bool ok = true;
        for(;;) {
            gets(buf);
            if(strcmp(buf, "-1")==0) break;
            int cur = 0;
            for(int i=0; buf[i]; i++) {
                const int ix = of(buf[i]);
                if(vs[cur].ch[ix]==-1) {
                    cur = 0;
                    break;
                }
                cur = vs[cur].ch[ix];
            }
            if(vs[cur].is==0) {
                if(ok) {
                    printf("Email %d is not spelled correctly.\n", k+1);
                    ok = false;
                }
                puts(buf);
            }
        }
        if(ok) printf("Email %d is spelled correctly.\n", k+1);
    }
    puts("End of Output");
    return 0;
}
