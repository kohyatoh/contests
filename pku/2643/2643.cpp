#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <map>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

map<string, string> party;
map<string, int> votes;
char s[100], p[100];

int main() {
    const int n=atoi(gets(s));
    rep(i, n) {
        gets(s);
        gets(p);
        party[s]=p;
    }
    const int m=atoi(gets(s));
    rep(i, m) {
        gets(s);
        if(party.find(s)!=party.end()) votes[s]++;
    }
    int mx=-1;
    string ans="tie";
    for(map<string, int>::iterator it=votes.begin(); it!=votes.end(); it++) {
        if(mx<it->second) mx=it->second, ans=party[it->first];
        else if(mx==it->second) ans="tie";
    }
    printf("%s\n", ans.c_str());
    return 0;
}
