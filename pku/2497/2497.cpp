#include <stdio.h>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define mp make_pair

int Q, t, n, d[30];
int ns[3], sc[3];
pair<int, pair<int, int> > v[3];
char name[3][8] = {"Steve", "Linus", "Bill"};

int main() {
	scanf("%d", &Q);
	rep(q, Q) {
		scanf("%d%d", &t, &n);
		rep(i, n) scanf("%d", d+i);
		rep(i, 3) {
			ns[i]=sc[i]=0;
			for(int j=0, ct=0; j<n && ct+d[j]<=t; j++) {
				ns[i]++;
				ct += d[j];
				sc[i] += ct;
			}
			v[i]=mp(-ns[i], mp(sc[i], (i+2)%3));
			if(i==0) sort(d, d+n);
			if(i==1) reverse(d, d+n);
		}
		sort(v, v+3);
		printf("Scenario #%d:\n", q+1);
		printf("%s wins with %d solved problems and a score of %d.\n",
				name[v[0].second.second], -v[0].first, v[0].second.first);
		printf("\n");
	}
	return 0;
}

