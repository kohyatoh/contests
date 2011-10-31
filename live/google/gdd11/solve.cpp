#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define foreach(it, c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define mp make_pair

#define BUF_SIZE (30000000)
#define REV_MIN_N (5000000)
#define FOR_MIN_N (5000000)
#define HASH_SIZE (10000001)

int LX, RX, UX, DX;

const char OPS[] = "LDRU";
#define OP_L (0)
#define OP_D (1)
#define OP_R (2)
#define OP_U (3)


struct point {
    char f[40];
    int cost; // calculated cost
    int hash; // hash value
    int last; // last operation
    const point *link; // for chained hash
    const point *pre; // fork-parent

    inline void init(const char *str) {
        memset(f, 0, sizeof(f));
        strcpy(f, str);
        cost = 0;
        hash = 0;
        last = -1;
        link = NULL;
        pre = NULL;
    }

    inline void init_as_goal(const char *str, const int n) {
        init(str);
        to_goal(n);
    }

    inline point& operator=(const point& r) {
        memcpy(this, &r, sizeof(point));
        return *this;
    }

    inline void fork(point *to) const {
        *to = *this;
        to->pre = this;
    }

    inline void mutate(const int from, const int to, const int op) {
        swap(f[from], f[to]);
        last = op;
    }

    int pos() const;
    string path() const;
    string rev_path() const;
private:
    void to_goal(const int n);
};


int point::pos() const {
    for(int i=0; i<40; i++) if(f[i]=='z') return i;
    assert(false);
}

string point::path() const {
    if(pre!=NULL) return pre->path() + OPS[last];
    return "";
}

string point::rev_path() const {
    if(pre!=NULL) return OPS[(last+2)%4] + pre->rev_path();
    return "";
}

void point::to_goal(const int n) {
    rep(i, n) if(f[i]!='=') {
        for(int j=i+1; j<n; j++) if(f[j]!='=') {
            if(f[i]>f[j]) swap(f[i], f[j]);
        }
    }
}

inline int calc_hash(const point& p) {
    int h = 0;
    rep(i, 40) h = (h*29LL+p.f[i])%(HASH_SIZE+2);
    return h;
}

inline bool f_equal(const point& l, const point& r) {
    const int *a=(int*)l.f, *b=(int*)r.f;
    rep(i, 9) if(a[i]!=b[i]) return false;
    return true;
}

class PointHash {
    const point *mTbl[HASH_SIZE];
public:
    bool insert(point *p) {
        if(get(p)==NULL) {
            p->link = mTbl[p->hash%HASH_SIZE];
            mTbl[p->hash%HASH_SIZE] = p;
            return true;
        }
        return false;
    }
    const point *get(point *p) {
        const point *x = mTbl[p->hash%HASH_SIZE];
        while(x!=NULL) {
            if(f_equal(*x, *p)) return x;
            x = x->link;
        }
        return NULL;
    }
    void clear() {
        memset(mTbl, 0, sizeof(mTbl));
    }
};

class CostComp {
public:
    bool operator()(const point *l, const point *r) {
        return l->cost < r->cost;
    }
};



point buf[BUF_SIZE];
point *cur, *bufend;
int cw, cn;
point start, goal;

int scost_of[40][128];
int dist[40][40];

void make_cost_table() {
    const int w = cw, n = cn, h = n/w;
    rep(i, n) rep(j, n) dist[i][j] = 1<<28;
    rep(i, n) if(goal.f[i]!='=') {
        dist[i][i] = 0;
        if(i%w!=0 && goal.f[i-1]!='=') dist[i][i-1] = 1;
        if(i%w!=w-1 && goal.f[i+1]!='=') dist[i][i+1] = 1;
        if(i/w!=0 && goal.f[i-w]!='=') dist[i][i-w] = 1;
        if(i/w!=h-1 && goal.f[i+w]!='=') dist[i][i+w] = 1;
    }
    rep(k, n) rep(i, n) rep(j, n) {
        dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
    }
    rep(i, n) rep(j, n) {
        if(goal.f[j]=='=' || goal.f[j]=='z') scost_of[i][(int)goal.f[j]] = 0;
//        else scost_of[i][(int)goal.f[j]] = dist[i][j];
//        else scost_of[i][(int)goal.f[j]] = dist[i][j]*dist[i][j];
        else scost_of[i][(int)goal.f[j]] = min(20, dist[i][j]*dist[i][j]);
    }
}

int calc_cost(const point& p) {
    const int n = cn;
    int s = 0;
    rep(i, n) s += scost_of[i][(int)p.f[i]];
    return s;
}


template<class T>
void mutate_and_push(const point& p, int from, int to, int op, T& q) {
    if(cur<bufend && p.f[to]!='=' && p.last!=(op+2)%4) {
        p.fork(cur);
        cur->mutate(from, to, op);
        cur->cost = calc_cost(*cur);
        cur->hash = calc_hash(*cur);
        if(q.push(cur)) cur++;
    }
}

template<class T>
void consume(T& q) {
    const int w = cw;
    const int h = cn/cw;
    while(!q.empty()) {
        const point& p = *q.pop();
        const int from = p.pos();
        if(from%w!=0) mutate_and_push(p, from, from-1, OP_L, q);
        if(from%w!=w-1) mutate_and_push(p, from, from+1, OP_R, q);
        if(from/w!=0) mutate_and_push(p, from, from-w, OP_U, q);
        if(from/w!=h-1) mutate_and_push(p, from, from+w, OP_D, q);
    }
}


class DoubleQueue {
protected:
    int cx, ix;
    vector<point*> mQ[2];
public:
    DoubleQueue(point *seed) {
        cx = 0;
        ix = 0;
        mQ[cx].push_back(seed);
    }
    bool empty() const {
        return ix >= (int)mQ[cx].size();
    }
    point* pop() {
        return mQ[cx][ix++];
    }
    bool push(point *p) {
        mQ[cx^1].push_back(p);
        return true;
    }
    void flip() {
        //cerr << "..." << cur-buf << "/" << BUF_SIZE << endl;
        mQ[cx].clear();
        cx ^= 1;
        ix = 0;
    }
};

class ReverseDoubleQueue : public DoubleQueue {
protected:
    PointHash &mHash;
public:
    ReverseDoubleQueue(PointHash &hash, point *seed)
        : DoubleQueue(seed), mHash(hash) {
    }
    bool push(point *p) {
        if(mHash.insert(p)) return DoubleQueue::push(p);
        return false;
    }
};

class ForwardDoubleQueue : public DoubleQueue {
protected:
    PointHash &mNet, &mVisited;
    point *mAns;
public:
    ForwardDoubleQueue(PointHash &net, PointHash &visited, point* seed)
        : DoubleQueue(seed), mNet(net), mVisited(visited), mAns(NULL) {
    }
    point *answer() const { return mAns; }
    bool push(point *p) {
        if(mAns==NULL && mNet.get(p)!=NULL) mAns = p;
        if(mVisited.insert(p)) return DoubleQueue::push(p);
        return false;
    }
};

class ForwardPruningDoubleQueue : public ForwardDoubleQueue {
    int mPSize;
    int mRParam;
public:
    ForwardPruningDoubleQueue(PointHash &net, PointHash &hash, point* seed, int psize, int rparam)
        : ForwardDoubleQueue(net, hash, seed), mPSize(psize), mRParam(rparam) {
    }
    void flip() {
        ForwardDoubleQueue::flip();
        sort(mQ[cx].begin(), mQ[cx].end(), CostComp());
        /*
        cerr << "flip" << endl;
        rep(i, cn/cw) {
            rep(j, cw) cerr << goal.f[i*cw+j];
            cerr << endl;
        }
        for(int k=0; k<1 && k<(int)mOut.size(); k++) {
            cerr << mOut[k]->cost << endl;
            rep(i, cn/cw) {
                rep(j, cw) cerr << mOut[k]->f[i*cw+j];
                cerr << endl;
            }
        }
        */
        //if(mOut.size()) cerr << mOut[0]->cost << endl;
        if((int)mQ[cx].size()>mPSize) {
            const int c = (bufend-cur)/mRParam;
            rep(i, c) {
                const int r = rand();
                swap(mQ[cx][r%mQ[cx].size()], mQ[cx][r%mPSize]);
            }
            mQ[cx].resize(mPSize);
        }
    }
};


PointHash net, visited;

string solve(const vector<int>& psizes, const vector<int>& rparams) {
    rep(i, cn/cw) {
        rep(j, cw) cerr << start.f[i*cw+j];
        cerr << endl;
    }
    net.clear();
    visited.clear();
    make_cost_table();

    ReverseDoubleQueue rq(net, &goal);
    int rev_steps = 0;
    while(cur-buf < REV_MIN_N && !rq.empty() && net.get(&start)==NULL) {
        rev_steps += 1;
        consume(rq);
        rq.flip();
    }
    point * const rev_end = cur;
    cerr << "  Rev: " << rev_end-buf << ", " << rev_steps << endl;
    if(net.get(&start)!=NULL) {
        string ans = net.get(&start)->rev_path();
        cerr << "+ found: " << ans.size() << ", " <<  ans << endl;
        return ans;
    }

    ForwardDoubleQueue fq(net, visited, &start);
    int for_steps = 0;
    while(cur-rev_end<FOR_MIN_N && !fq.empty() && fq.answer()==NULL) {
        for_steps += 1;
        consume(fq);
        fq.flip();
    }
    cerr << "  For: " << cur-rev_end << " : " << for_steps << endl;
    if(fq.answer()!=NULL) {
        point *p = fq.answer();
        string ans = p->path() + net.get(p)->rev_path();
        cerr << "+ found': " << ans.size() << " / " << ans << endl;
        return ans;
    }

    rep(i, psizes.size()) rep(j, rparams.size()) {
        cerr << "pruning: " << psizes[i] << ", " << rparams[j] << endl;
        visited.clear();
        cur = rev_end;
        ForwardPruningDoubleQueue pq(net, visited, &start, psizes[i], rparams[j]);
        int fpr_steps = 0;
        while(cur<bufend && !pq.empty() && pq.answer()==NULL) {
            fpr_steps += 1;
            consume(pq);
            pq.flip();
        }
        cerr << "  Fpr: " << cur-rev_end << " : " << fpr_steps << endl;
        if(pq.answer()!=NULL) {
            point *p = pq.answer();
            string ans = p->path() + net.get(p)->rev_path();
            cerr << "+ found'': " << ans.size() << " / " << ans << endl;
            return ans;
        }
        cerr << "- not found" << endl;
    }

    return "";
}

#define NUM (6000)
int N, W[NUM], H[NUM];
string fields[NUM];
string preloads[NUM];
extern char *optarg;
extern int optind, opterr;

int main(int argc, char *argv[]) {
    srand(time(NULL));
    int opt;
    string preload_filename;
    while((opt=getopt(argc, argv, "w:"))!=-1) {
        switch(opt) {
        case 'w':
            preload_filename = optarg;
            break;
        }
    }
    cin >> LX >> RX >> UX >> DX;
    cin >> N;
    rep(i, N) {
        char _;
        cin >> W[i] >> _ >> H[i] >> _ >> fields[i];
        rep(j, fields[i].size()) if(fields[i][j]=='0') fields[i][j]='z';
    }
    if(preload_filename.size()) {
        fstream fin(preload_filename.c_str(), ios::in);
        rep(i, N) getline(fin, preloads[i]);
        fin.close();
    }
    vector<int> psizes, rparams;
    psizes.push_back(160000);
    psizes.push_back(80000);
    psizes.push_back(40000);
//    psizes.push_back(20000);
    rparams.push_back(25000);
//    rparams.push_back(2500);
    rparams.push_back(250);
//    rparams.push_back(25);

    int c = 0;
    rep(i, N) {
        if(preloads[i].size()) {
            cout << preloads[i] << endl;
            c++;
        }
        else {
            cur = buf;
            bufend = buf+BUF_SIZE;
            cw = W[i];
            cn = W[i] * H[i];
            start.init(fields[i].c_str());
            goal.init_as_goal(fields[i].c_str(), cn);
            start.cost = calc_cost(start);
            start.hash = calc_hash(start);
            goal.hash = calc_hash(goal);
            cerr << i+1 << "/" << N << " ";
            cerr << start.f << " to " << goal.f << endl;
            string ans = solve(psizes, rparams);
            cout << ans << endl;
            if(ans.size()) c++;
            cerr << "accuracy: " << c << "/" << i+1 << endl;
        }
    }
    return 0;
}

