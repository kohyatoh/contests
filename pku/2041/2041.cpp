#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

int n;
string mes, msg;

int main() {
    cin >> n;
    rep(q, n) {
        cin >> mes >> msg;
        int n=msg.size();
        for(int k=mes.size()-1; k>=0; k--) {
            if(mes[k]=='J') msg=msg[n-1]+msg.substr(0, n-1);
            else if(mes[k]=='C') msg=msg.substr(1)+msg[0];
            else if(mes[k]=='A') reverse(msg.begin(), msg.end());
            else if(mes[k]=='E') {
                if(n%2==0) msg=msg.substr(n/2)+msg.substr(0, n/2);
                else msg=msg.substr(n/2+1)+msg[n/2]+msg.substr(0, n/2);
            }
            else {
                int d=mes[k]=='P' ? 9 : 1;
                rep(i, n) if('0'<=msg[i] && msg[i]<='9') {
                    msg[i] = '0' + (msg[i]-'0'+d)%10;
                }
            }
        }
        cout << msg << endl;
    }
}
