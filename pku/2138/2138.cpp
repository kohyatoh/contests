#include <stdio.h>
#include <string.h>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

struct SC {
    bool operator()(const string& l, const string& r) {
        return l.size()!=r.size() ? l.size()<r.size() : l<r;
    }
};

int n, vis[1001];
string s[1001];
char st[100], buf[100];

int main() {
    scanf("%d %s", &n, st);
    rep(i, n) { scanf("%s", buf); s[i]=buf; }
    sort(s, s+n, SC());
    queue<int> q;
    int six=lower_bound(s, s+n, string(st), SC())-s;
    q.push(six);
    vis[six]=1;
    int mxi=six;
    while(!q.empty()) {
        int ix=q.front();
        q.pop();
        mxi=ix;
        for(int i=ix+1; i<n && s[i].size()<s[ix].size()+2; i++) if(!vis[i]) {
            if(s[i].size()==s[ix].size()) continue;
            bool yes=true;
            rep(j, s[ix].size()) if(s[ix][j]!=s[i][j]) {
                yes = strcmp(s[ix].c_str()+j, s[i].c_str()+j+1)==0;
                break;
            }
            if(yes) {
                q.push(i);
                vis[i]=1;
            }
        }
    }
    printf("%s\n", s[mxi].c_str());
    return 0;
}
