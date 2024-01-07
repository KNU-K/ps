#include <iostream>
#include <stack>
using namespace std;
int arr[1000001];

int main() {
	int n;
	stack<int> s;
	stack<int> ans;
	cin >> n;
	for (int i = 0; i < n;i++) {
		cin >> arr[i];
	}

	for (int i = n-1; i >=0;i--) {
		int pivot = arr[i];
		if (i == n - 1) {
			ans.push(-1);
		}
		else {
			while(!s.empty() &&pivot >= s.top()) {
				s.pop();
			}
			if (s.empty()) {
				ans.push(-1);
				
			}
			else {
				if (pivot < s.top()) {
					ans.push(s.top());
				}
			}
		}
		s.push(pivot);
	}
	while (!ans.empty()) {
		cout << ans.top() << " ";
		ans.pop();
	}
	
}