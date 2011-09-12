#include <iostream>
#include <sstream>
#include <string>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, a[100], root[100], dig[100];

void tprint(int ix) {
    cout << '(' << ix;
    for(int i=1; i<=n+1; i++) if(root[i]==ix) {
        cout << ' ';
        tprint(i);
    }
    cout << ')';
}

int main() {
    string s;
    while(getline(cin, s)) {
        istringstream sin(s);
        n = 0;
        while(sin>>a[n]) n++;
        rep(i, 100) root[i]=-1;
        rep(i, 100) dig[i]=0;
        rep(i, n) dig[a[i]]++;
        for(int m=0; m<n; m++) for(int i=1; i<=n+1; i++) if(dig[i]==0) {
            dig[i]=-1;
            rep(j, n) if(a[j]>0) {
                root[i] = a[j];
                dig[a[j]]--;
                a[j] = 0;
                break;
            }
            break;
        }
        for(int i=1; i<=n+1; i++) if(root[i]==-1) tprint(i);
        cout << endl;
    }
    return 0;
}
