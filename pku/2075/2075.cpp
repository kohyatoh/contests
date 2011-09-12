#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <queue>
#include <map>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

struct Edges {
    static const int n=1000, m=5000;
    int E, from[m], to[m], head[n], next[m];
    double cost[m];
    void init() { E=0; memset(head, -1, sizeof(head)); }
    void add_edge(int s, int t, double c) {
        from[E]=s; to[E]=t; cost[E]=c; next[E]=head[s]; head[s]=E; E++;
    }
} es;

int N, vis[1000];

double mintree() {
    double ans=0;
    int k=0;
    priority_queue<pair<double, int> > q;
    q.push(mp(0, 0));
    while(!q.empty()) {
        pair<double, int> v=q.top();
        q.pop();
        int cur=v.second;
        if(vis[cur]) continue;
        vis[cur] = 1;
        ans -= v.first;
        if(++k==N) return ans;
        for(int x=es.head[cur]; x!=-1; x=es.next[x]) if(vis[es.to[x]]==0) {
            q.push(mp(-es.cost[x], es.to[x]));
        }
    }
    return -1;
}

double spool;
map<string, int> of;

int main() {
    es.init();
    cin >> spool >> N;
    string s, t;
    rep(i, N) { cin>>s; of[s]=i; }
    int m;
    cin >> m;
    rep(i, m) {
        double d;
        cin >> s >> t >> d;
        es.add_edge(of[s], of[t], d);
        es.add_edge(of[t], of[s], d);
    }
    double sum=mintree();
    if(sum>spool) printf("Not enough cable\n");
    else printf("Need %.1f miles of cable\n", sum);
    return 0;
}
