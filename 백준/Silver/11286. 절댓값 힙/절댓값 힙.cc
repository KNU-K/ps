#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <stack>
#include <cstring>
#include <queue>
using namespace std;

int main() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	int n;
	cin >> n;
	for (int i = 0; i < n;i++) {
		int x;
		cin >> x;

		if (x == 0) {
			if (pq.empty()) {
				cout << 0 << "\n";
				continue;
			}
			cout <<pq.top().second << "\n";

			pq.pop();
		}
		else {
			pq.push({ (x < 0 ? -x : x),x });
		}
	}
}