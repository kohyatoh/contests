#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

string exc[100];

int main() {
    string s;
    int q=0;
    while(getline(cin, s)) {
        int K, E;
        sscanf(s.c_str(), "%d%d", &K, &E);
        set<string> keys;
        rep(i, K) { getline(cin, s); keys.insert(s); }
        vector<int> v;
        int maxc=0;
        rep(i, E) {
            getline(cin, exc[i]);
            s=exc[i];
            rep(k, s.size()) {
                if('A'<=s[k] && s[k]<='Z') s[k]=s[k]+'a'-'A';
                else if(s[k]<'a' || 'z'<s[k]) s[k]=' ';
            }
            stringstream sin(s);
            int c=0;
            while(sin>>s) c+=keys.count(s);
            if(maxc<c) { maxc=c; v.clear(); v.push_back(i); }
            else if(maxc==c) v.push_back(i);
        }
        cout << "Excuse Set #" << ++q << endl;
        rep(i, v.size()) cout << exc[v[i]] << endl;
        cout << endl;
    }
    return 0;
}

