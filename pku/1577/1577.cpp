#include <stdio.h>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

struct BT {
    char val;
    BT *l, *r;
    BT(char ch) : val(ch), l(NULL), r(NULL) {}
    ~BT() {
        if(l!=NULL) delete l;
        if(r!=NULL) delete r;
    }
    void add(char ch) {
        if(ch<val) {
            if(l==NULL) l = new BT(ch);
            else l->add(ch);
        }
        else {
            if(r==NULL) r = new BT(ch);
            else r->add(ch);
        }
    }
    string str() {
        string s(1, val);
        if(l!=NULL) s += l->str();
        if(r!=NULL) s += r->str();
        return s;
    }
};

char s[128];

int main() {
    while(*s!='$') {
        vector<string> as;
        for(;;) {
            gets(s);
            if(*s=='*' || *s=='$') break;
            as.push_back(s);
        }
        BT bt('A');
        for(int i=as.size()-1; i>=0; i--) rep(j, as[i].size()) bt.add(as[i][j]);
        printf("%s\n", bt.str().c_str()+1);
    }
    return 0;
}
