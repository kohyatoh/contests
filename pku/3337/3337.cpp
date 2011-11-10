#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <iostream>
#include <string>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int val[32], add[32], used[32];
string s;

bool pre(char ch, int a) {
    rep(i, s.size()) if(i>=2 && islower(s[i]) && s[i-1]==ch && s[i-2]==ch) {
        val[s[i]-'a'] += a;
        s = s.substr(0, i-2) + s.substr(i);
        return true;
    }
    return false;
}

bool post(char ch, int a) {
    rep(i, s.size()-2) if(islower(s[i]) && s[i+1]==ch && s[i+2]==ch) {
        add[s[i]-'a'] += a;
        s = s.substr(0, i+1) + s.substr(i+3);
        return true;
    }
    return false;
}

int main() {
    getline(cin, s);
    int T = atoi(s.c_str());
    while(T--) {
        getline(cin, s);
        printf("Expression: %s\n", s.c_str());
        int m = 0;
        rep(i, s.size()) if(!isspace(s[i])) s[m++] = s[i];
        s.resize(m);
        rep(i, 32) {
            val[i] = i+1;
            add[i] = used[i] = 0;
        }
        rep(i, s.size()) if(islower(s[i])) used[s[i]-'a'] = 1;
        while(pre('+', 1));
        while(pre('-', -1));
        while(post('+', 1));
        while(post('-', -1));
        int v = 0;
        rep(i, s.size()) if(islower(s[i])) {
            if(i>0 && s[i-1]=='-') v -= val[s[i]-'a'];
            else v += val[s[i]-'a'];
        }
        printf("value = %d\n", v);
        rep(i, 32) if(used[i]) {
            printf("%c = %d\n", i+'a', val[i]+add[i]);
        }
    }
    return 0;
}
