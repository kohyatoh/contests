#include <iostream>
#include <map>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n, m;

int main() {
    cin >> n >> m;
    map<string, int> hp;
    string s;
    int v;
    rep(i, n) {
        cin >> s >> v;
        hp[s] = v;
    }
    rep(i, m) {
        int ans=0;
        do {
            cin >> s;
            if(hp.find(s)!=hp.end()) ans += hp[s];
        } while(s!=".");
        cout << ans << endl;
    }
    return 0;
}

