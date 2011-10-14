#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>
#include <map>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)


int main() {
    for(;;) {
        string s;
        getline(cin, s);
        if(s=="END") return 0;
        map<char, int> cnt;
        rep(i, s.size()) cnt[s[i]]++;
        priority_queue<int> q;
        for(map<char, int>::iterator it=cnt.begin(); it!=cnt.end(); ++it) {
            q.push(-it->second);
        }
        int ans = 0;
        if(q.size()==1) ans = s.size();
        while(q.size()>=2) {
            const int a = -q.top();
            q.pop();
            const int b = -q.top();
            q.pop();
            ans += a+b;
            q.push(-(a+b));
        }
        const int t = 8*s.size();
        printf("%d %d %.1f\n", t, ans, (double)t/ans);
    }
}
