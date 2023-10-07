#include <iostream>
#include <queue>
using namespace std;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	priority_queue<int,vector<int>,greater<int>> q;
	int t;
	cin >> t;
	while (t--) {
		int x;
		cin >> x;
		if (x == 0) {
			if (q.empty()) {
				cout << "0\n";
			}
			else {
				cout<<q.top()<<"\n";
				q.pop();
			}
		}
		else {
			q.push(x);
		}
	}
}