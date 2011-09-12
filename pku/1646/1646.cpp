#include <iostream>
#include <string>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int Q, n;

int main() {
    cin >> Q;
    rep(q, Q) {
        string s, lo, co;
        cin >> n;
        while((int)lo.size()<n) { cin>>s; lo+=s; }
        cin >> co;
        string cd(co.size()-1, 1);
        rep(i, co.size()-1) cd[i]=1+(co[i+1]-co[i]+26)%26;
        int anss=30, ansm=0;
        for(int m=5; m<21; m++) {
            string to(n, 100), td(n, 100);
            rep(i, n) to[min(i-i%m+m, n)-i%m-1]=lo[i];
            rep(i, n-1) td[i+1]=1+(to[i+1]-to[i]+26)%26;
            unsigned i=0;
            while((i=td.find(cd, i))!=string::npos) {
                int s=(to[i-1]-co[0]+26)%26;
                if(s>0 && anss>s) anss=s, ansm=m;
                i++;
            }
        }
        if(anss!=30) cout << anss << " " << ansm << endl;
        else cout << "Crib is not encrypted." << endl;
    }
    return 0;
}

