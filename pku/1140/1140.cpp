#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;

int vis[1024];

int main() {
    for(;;) {
        int n, d;
        scanf("%d%d", &n, &d);
        if(n==0 && d==0) return 0;
        string ans(".");
        memset(vis, 0, sizeof(vis));
        int re = -1;
        for(int i=1; n>0; i++) {
            if(vis[n]!=0) {
                re = i-vis[n];
                break;
            }
            vis[n] = i;
            n *= 10;
            ans += (char)(n/d+'0');
            n %= d;
        }
        for(int i=0; i<(int)ans.size(); i+=50) puts(ans.substr(i, 50).c_str());
        if(n==0) puts("This expansion terminates.");
        else printf("The last %d digits repeat forever.\n", re);
    }
}
