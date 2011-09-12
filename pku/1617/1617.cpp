#include <iostream>
#include <string>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int v[100];

int main() {
    for(;;) {
        string key, ciph;
        cin >> key;
        if(key=="THEEND") return 0;
        cin >> ciph;
        string plain(ciph);
        int k=0;
        for(char ch='A'; ch<='Z'; ch++) {
            rep(i, key.size()) if(key[i]==ch) v[k++]=i;
        }
        int tl=ciph.size()/key.size();
        rep(i, k) rep(j, tl) plain[j*k+v[i]]=ciph[i*tl+j];
        cout << plain << endl;
    }
}

