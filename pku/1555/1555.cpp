#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int k[100];

int main() {
    while(cin>>k[0]) {
        rep(i, 8) cin>>k[i+1];
        ostringstream sout;
        rep(i, 9) if(k[i]!=0) {
            if(sout.str().size()==0) {
                if(k[i]>1 || k[i]<-1) sout << k[i];
                else if(k[i]==-1) sout<<"-";
            }
            else {
                if(k[i]>=1) sout << " + ";
                if(k[i]<=-1) sout << " - ";
                if(abs(k[i])!=1) sout << abs(k[i]);
            }
            if(i==8 && abs(k[i])==1) sout << "1";
            if(i<8) sout << "x";
            if(i<7) sout << "^" << (8-i);
        }
        if(sout.str().size()==0) sout << "0";
        cout << sout.str() << endl;
    }
    return 0;
}
