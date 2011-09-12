#include <stdio.h>
#include <vector>
#define rep(i, n) for(int i=0; i<(int)(n); i++)

struct node {
    char ch;
    std::vector<node*> v;
    node(char ch) : ch(ch) {}
    ~node() { rep(i, v.size()) delete v[i]; }
    node *get(char ch) {
        rep(i, v.size()) if(v[i]->ch==ch) return v[i];
        return (node*)0;
    }
    node *add(char ch) {
        v.push_back(new node(ch));
        return v.back();
    }
};

char buf[128];

int main() {
    gets(buf);
    int n, m;
    sscanf(buf, "%d%d", &n, &m);
    node root(0);
    rep(i, n) {
        gets(buf);
        node *p=&root, *nx;
        for(char *s=buf; *s; s++) {
            if((nx=p->get((char)*s))==0) nx=p->add(*s);
            p = nx;
        }
    }
    int ans=0;
    rep(i, m) {
        char ch;
        node *p=&root;
        while((ch=getchar())!='\n') {
            if(p) p=p->get(ch);
        }
        if(p) ans++;
    }
    printf("%d\n", ans);
    return 0;
}

