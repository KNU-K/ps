#include <iostream>
#include <deque>
#include <queue>
using namespace std;

struct e { int idx, v; };

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, L, x; cin >> N >> L;
    int sum = 0;
    deque<int> dq;
    priority_queue<int> pq;
    for (int i = 0; i < N; i++) {
        cin >> x;
        dq.push_back(x);
        sum += x;
        if (!dq.empty() && dq.size() == L) {
            pq.push(sum);
            sum -= dq.front();
            dq.pop_front();
        }
    }
    int st = pq.top();
    if (st == 0) {
        cout << "SAD\n";
        return 0;
    }
    cout << pq.top() << "\n";

    int ans = 0;
    while (!pq.empty()) {
        if (pq.top() == st) {
            ans++;
        }
        pq.pop();
    }
    cout << ans;
}