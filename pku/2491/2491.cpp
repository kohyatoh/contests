#include <stdio.h>
#include <iostream>
#include <set>
#include <map>
#include <string>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int Q, n;
map<string, string> pr, nx;
map<string, int> vis;

void print(const string& s) {
    if(vis[s]) return;
    vis[s]=1;
    if(pr.find(s)!=pr.end()) print(pr[s]);
    cout << s << endl;
}

int main() {
    cin >> Q;
    rep(q, Q) {
        string a, b;
        pr.clear(), nx.clear(), vis.clear();
        cin >> n;
        rep(i, n-1) {
            cin >> a >> b;
            pr[b]=a;
            nx[a]=b;
        }
        cout << "Scenario #" << q+1 << ":" << endl;
        for(map<string, string>::iterator it=pr.begin(); it!=pr.end(); it++) {
            print(it->first);
        }
        cout << endl;
    }
    return 0;
}
