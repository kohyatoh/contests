#include <stdio.h>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

bool is(char ch) {
    return ('a'<=ch && ch<='z') || ('A'<=ch && ch<='Z') || ('0'<=ch && ch<='9');
}

char buf[128];

int main() {
    map<string, int> cnt;
    while(gets(buf)) {
        int pre = -1;
        for(int i=0; i==0 || buf[i-1]; i++) {
            if(is(buf[i])) {
                if(pre==-1) pre = i;
            }
            else if(pre!=-1) {
                string w(buf+pre, i-pre);
                rep(i, w.size()) w[i] = tolower(w[i]);
                cnt[w]++;
                pre = -1;
            }
        }
    }
    int ans = -1;
    for(map<string, int>::iterator it=cnt.begin(); it!=cnt.end(); ++it) {
        ans = max(ans, it->second);
    }
    printf("%d occurrences\n", ans);
    for(map<string, int>::iterator it=cnt.begin(); it!=cnt.end(); ++it) {
        if(ans==it->second) printf("%s\n", it->first.c_str());
    }
    return 0;
}
