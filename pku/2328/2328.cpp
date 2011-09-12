#include <iostream>
#include <string>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int d[11];

int main() {
    for(;;) {
        int n;
        string t1, t2;
        rep(i, 11) d[i]=0;
        while(t1!="right") {
            cin >> n;
            if(n==0) return 0;
            cin >> t1 >> t2;
            if(t2=="high") for(int i=n; i<11; i++) d[i]=1;
            if(t2=="low") for(int i=0; i<=n; i++) d[i]=1;
        }
        if(d[n]) cout << "Stan is dishonest" << endl;
        else cout << "Stan may be honest" << endl;
    }
}
