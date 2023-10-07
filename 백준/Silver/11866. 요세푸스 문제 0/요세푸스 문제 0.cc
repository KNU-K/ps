#include <iostream>
#include <queue>
using namespace std;

int main() {
	queue<int> q;
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	int cnt = 1;
	cout << "<";
	while (!q.empty()) {
		if (cnt % k == 0) {
			if(q.size()==1)
				cout << q.front() << ""; 
			else
				cout << q.front() << ", ";
			q.pop();
		}
		else {
			q.push(q.front());
			q.pop();
		}
		cnt++;
	}
	cout << ">";
}
