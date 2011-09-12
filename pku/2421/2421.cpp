#include <stdio.h>
#include <queue>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

struct node { int to, c; node(int to, int c) : to(to), c(c) {} };
bool operator<(const node& l, const node& r) { return l.c!=r.c?l.c>r.c:l.to>r.to; }

int n, q, g[100][100], u[100];

int main() {
	scanf("%d", &n);
	rep(i, n) rep(j, n) scanf("%d", g[i]+j);
	scanf("%d", &q);
	rep(i, q) {
		int a, b;
		scanf("%d%d", &a, &b);
		g[a-1][b-1]=g[b-1][a-1]=0;
	}
	priority_queue<node> q;
	q.push(node(0, 0));
	int ans=0;
	while(!q.empty()) {
		node v=q.top(); q.pop();
		if(u[v.to]) continue;
		u[v.to]=1;
		ans+=v.c;
		rep(i, n) if(u[i]==0) q.push(node(i, g[v.to][i]));
	}
	printf("%d\n", ans);
	return 0;
}
