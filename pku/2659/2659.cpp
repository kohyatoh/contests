#include <stdio.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int w, h, k, f[100][100];

int main() {
	scanf("%d%d%d", &w, &h, &k);
	rep(i, k) {
		int r, s, p, t;
		scanf("%d%d%d%d", &r, &s, &p, &t);
		rep(i, w) rep(j, h) {
			if(r-1-p/2<=i && i<r+p/2 && s-1-p/2<=j && j<s+p/2) {
				if(t==0) f[i][j]=1;
			}
			else {
				if(t==1) f[i][j]=1;
			}
		}
	}
	int ans=0;
	rep(i, w) rep(j, h) ans+=f[i][j]==0;
	printf("%d\n", ans);
	return 0;
}
