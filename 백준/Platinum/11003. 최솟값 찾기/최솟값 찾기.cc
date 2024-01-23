#include <iostream>
#include <deque>
using namespace std;

struct e {int idx, v;};
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, L, x; cin >> N >> L;
    
    deque<e> dq;
    for(int i=0; i<N; i++){
        cin >> x;
        if(!dq.empty() && dq.front().idx == i - L)
            dq.pop_front();
        while(!dq.empty() && dq.back().v > x)
            dq.pop_back();
        dq.push_back({i, x});
        cout << dq.front().v << " ";
    }
}