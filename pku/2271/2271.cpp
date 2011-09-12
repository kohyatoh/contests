#include <iostream>
#include <string>
using namespace std;

int main() {
    int w=0;
    string s;
    while(cin>>s) {
        if(s=="<br>") cout<<endl, w=0;
        else if(s=="<hr>") {
            if(w!=0) cout<<endl;
            cout<<string(80, '-')<<endl, w=0;
        }
        else {
            if(w+(w!=0)+s.size()>80) cout<<endl<<s, w=s.size();
            else if(w!=0) cout<<' '<<s, w+=1+s.size();
            else cout<<s, w+=s.size();
        }
    }
    if(w!=0) cout<<endl;
    return 0;
}
