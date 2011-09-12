#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int size[3];
vector<int> v[3];

int to_time(const string& s) { return atoi(s.c_str())*60+atoi(s.c_str()+3); }

int main() {
    for(;;) {
        rep(i, 3) cin >> size[i];
        if(size[0]==0 && size[1]==0 && size[2]==0) return 0;
        rep(i, 3) v[i].clear();
        int ans=0;
        for(;;) {
            string s;
            cin >> s;
            if(s=="#") break;
            int at=to_time(s);
            int k;
            cin >> k;
            int t = (k-1)/2;
            int b = v[t].size()<size[t] ? -100 : v[t][v[t].size()-size[t]];
            if(b<=at+30) {
                v[t].push_back(max(b, at)+30);
                ans += k;
            }
        }
        cout << ans << endl;
    }
}
