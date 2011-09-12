#include <iostream>
#include <queue>

int N, L;

int main() {
    std::cin >> N;
    std::priority_queue<int> q;
    while(N--) { std::cin>>L; q.push(-L); }
    long long ans=0;
    for(;;) {
        int a=q.top();
        q.pop();
        if(q.empty()) break;
        int b=q.top();
        q.pop();
        ans -= a+b;
        q.push(a+b);
    }
    std::cout << ans << std::endl;
    return 0;
}

