#include <iostream>
#include <queue>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int t;
	priority_queue<int> pq;
	cin >> t;

	while (t--) {
		int x;
		cin >> x;
		if (x == 0) {
			if (pq.empty()) {
				cout << "0\n";
			}
			else {
				cout << pq.top()<<"\n";
				pq.pop();
			}
		}
		else {
			pq.push(x);
		}
	}
	
}