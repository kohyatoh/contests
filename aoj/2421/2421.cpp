#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

struct Node;
struct Fun;

int h, w, cr, cc;
char scr[512][512];
Node *lnk[512][512];
Fun *evt[512][512];
map<string, vector<pair<string, Fun*> > > scrp;
map<string, Node*> dmls;
map<string, Fun*> funs;
Node *act;

void newline() {
    cr++;
    cc = 0;
}

void draw(const string& s, Node *hl, Fun *fn) {
    rep (i, s.size()) {
        if (0 <= cr && cr < h && 0 <= cc && cc < w) {
            scr[cr][cc] = s[i];
            lnk[cr][cc] = hl;
            evt[cr][cc] = fn;
            cc++;
        }
        if (cc == w) newline();
    }
}

struct Node {
    string tag;
    string text;
    vector<Node*> cs;
    bool visible;

    Node(const string& tag) : tag(tag), visible(true) {}
    void dump() const { dump(0); }
    void dump(int dep) const {
        rep (_, dep) cerr << ' ';
        cerr << '<' << tag << '>';
        cerr << " visi = " << visible;
        cerr << " text = " << text << endl;
        rep (i, cs.size()) cs[i]->dump(dep+2);
        rep (_, dep) cerr << ' ';
        cerr << "</" << tag << '>' << endl;;
    }

    void render() const {
        if (!visible) return ;
        if (tag == "$text") draw(text, 0, 0);
        else if (tag == "script") ;
        else if (tag == "link") {
            assert(cs.size() == 1 && cs[0]->tag == "$text");
            assert(dmls[cs[0]->text]);
            draw(cs[0]->text, dmls[cs[0]->text], 0);
        }
        else if (tag == "button") {
            assert(cs.size() == 1 && cs[0]->tag == "$text");
            //assert(funs[cs[0]->text]);
            draw(cs[0]->text, 0, funs[cs[0]->text]);
        }
        else if (tag == "br") newline();
        else {
            rep (i, cs.size()) cs[i]->render();
        }
    }

    void init() {
        visible = true;
        if (tag == "script") {
            assert(cs.size() == 1 && cs[0]->tag == "$text");
            string file = cs[0]->text;
            vector<pair<string, Fun*> > fs = scrp[file];
            rep (i, fs.size()) {
                funs[fs[i].first] = fs[i].second;
            }
        }
        rep (i, cs.size()) cs[i]->init();
    }

    void apply(const vector<string>& vs, int k, bool visi) {
        if (vs[k] == tag) {
            if (k == (int)vs.size()-1) {
                visible = visi;
            }
            else {
                k++;
            }
        }
        rep (i, cs.size()) cs[i]->apply(vs, k, visi);
    }
};

struct Fun {
    vector<pair<vector<string>, bool> > asn;
    void exec() {
        rep (i, asn.size()) {
            act->apply(asn[i].first, 0, asn[i].second);
        }
    }
};

vector<string> lex_dml(const string& s) {
    vector<string> ts;
    int pos = 0;
    rep (i, s.size()) {
        if (s[i] == '<') {
            ts.push_back(s.substr(pos, i-pos));
            pos = i;
        }
        else if (s[i] == '>') {
            ts.push_back(s.substr(pos, i+1-pos));
            pos = i+1;
        }
    }
    ts.push_back(s.substr(pos));
    return ts;
}

bool isbegin(const string& t) {
    if (t.size() < 3) return false;
    if (t[0] != '<' || t[t.size()-1] != '>') return false;
    for (int i = 1; i < (int)t.size()-1; i++) {
        assert(t[i] != ' ');
        if (!islower(t[i]) && !isupper(t[i])) return false;
    }
    return true;
}

bool isend(const string& t) {
    if (t.size() < 4) return false;
    if (t[0] != '<' || t[1] != '/' || t[t.size()-1] != '>') return false;
    for (int i = 2; i < (int)t.size()-1; i++) {
        assert(t[i] != ' ');
        if (!islower(t[i]) && !isupper(t[i])) return false;
    }
    return true;
}

Node *parse_dml(const vector<string>& ts) {
    Node *root = new Node("$root");
    vector<Node*> stk;
    stk.push_back(root);
    rep (i, ts.size()) {
        if (ts[i].size() == 0) continue;
        if (isbegin(ts[i])) {
            Node *node = new Node(ts[i].substr(1, ts[i].size()-2));
            stk.back()->cs.push_back(node);
            if (ts[i] != "<br>") stk.push_back(node);
        }
        else if (isend(ts[i])) {
            assert(stk.back()->tag == ts[i].substr(2, ts[i].size()-3));
            stk.pop_back();
        }
        else {
            Node *node = new Node("$text");
            node->text = ts[i];
            stk.back()->cs.push_back(node);
        }
    }
    assert(stk.size() == 1);
    return root;
}

vector<string> parse_prop(const string& s) {
    vector<string> ps;
    int pos = 0;
    rep (i, s.size()) {
        if (s[i] == '.') {
            ps.push_back(s.substr(pos, i-pos));
            pos = i+1;
        }
    }
    assert(s.substr(pos) == "visible");
    return ps;
}

string _s;
unsigned _ix;

vector<pair<vector<string>, bool> > parse_expr() {
    unsigned pos = _ix;
    vector<string> props;
    vector<bool> rev;
    while (_s[_ix] != ';') {
        if (_s[_ix] == '!' || _s[_ix] == '=') {
            props.push_back(_s.substr(pos, _ix-pos));
            if (_s[_ix] == '!') {
                _ix += 2;
                pos = _ix;
                rev.push_back(true);
            }
            else {
                _ix += 1;
                pos = _ix;
                rev.push_back(false);
            }
        }
        else {
            _ix++;
        }
    }
    string val = _s.substr(pos, _ix-pos);
    bool cur = val == "true";
    vector<pair<vector<string>, bool> > rs;
    for (int i = (int)props.size()-1; i >= 0; i--) {
        if (rev[i]) cur = !cur;
//        cerr << props[i] << " = " << cur << endl;
        rs.push_back(make_pair(parse_prop(props[i]), cur));
    }
    _ix++;
    return rs;
}

pair<string, Fun*> parse_fun() {
    Fun *fun = new Fun();
    const unsigned st = _ix;
    while (_s[_ix] != '{') _ix++;
    const string id = _s.substr(st, _ix-st);
    _ix++;
//    cerr << id << endl;
    while (_s[_ix] != '}') {
        vector<pair<vector<string>, bool> > es(parse_expr());
        rep (i, es.size()) fun->asn.push_back(es[i]);
    }
    _ix++;
    return make_pair(id, fun);
}

vector<pair<string, Fun*> > parse_ds(const string& s) {
    _s = s;
    _ix = 0;
    vector<pair<string, Fun*> > fs;
    while (_ix < _s.size()) {
        fs.push_back(parse_fun());
    }
    return fs;
}

void render(Node *file) {
    rep (i, h) rep (j, w) {
        scr[i][j] = '.';
        lnk[i][j] = 0;
        evt[i][j] = 0;
    }
    cr = cc = 0;
    file->render();
    act = file;
}

void click(int x, int y) {
    if (lnk[y][x]) {
        funs.clear();
        lnk[y][x]->init();
        render(lnk[y][x]);
    }
    else if (evt[y][x]) {
        evt[y][x]->exec();
        render(act);
    }
}

void getl(string& s) {
    getline(cin, s);
    assert(s.size() == 0 || s[s.size()-1] != '\r');
}

int main() {
    string s;
    getl(s);
    const int n = atoi(s.c_str());
    rep (_, n) {
        getl(s);
        if (s.substr(s.size()-4) == ".dml") {
            const string file = s.substr(0, s.size()-4);;
//            cerr << file << endl;
            getl(s);
            vector<string> ts = lex_dml(s);
//            rep (i, ts.size()) cerr << i << ": " << ts[i] << endl;
            Node *root = parse_dml(ts);
//            root->dump();
            dmls[file] = root;
        }
        else if (s.substr(s.size()-3) == ".ds") {
            const string file = s.substr(0, s.size()-3);;
//            cerr << file << endl;
            getl(s);
            vector<pair<string, Fun*> > fs = parse_ds(s);
            scrp[file] = fs;
        }
        else assert(false);
    }
    getl(s);
    const int m = atoi(s.c_str());
    rep (_, m) {
        int K;
        char buf[32];
        getl(s);
        sscanf(s.c_str(), "%d %d %d %s", &w, &h, &K, buf);
        dmls[buf]->init();
        render(dmls[buf]);
        rep (_, K) {
            int x, y;
            getl(s);
            sscanf(s.c_str(), "%d%d", &x, &y);
            click(x, y);
        }
        rep (i, h) {
            rep (j, w) putchar(scr[i][j]);
            putchar('\n');
        }
    }
    return 0;
}
