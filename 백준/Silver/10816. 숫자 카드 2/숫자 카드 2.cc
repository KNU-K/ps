#include <iostream>
#include <algorithm>
using namespace std;
int cards[500001];
int n;
int binSearchL(int s, int e, int target) {
	int mid = (s + e) / 2;
	if (s > e) return -1;
	if (cards[mid] == target) {
		if (mid - 1 >=0 && cards[mid - 1] == target) {
			return binSearchL(s, mid - 1, target);
		}
		else {
			return mid;
		}
	}
	else if (cards[mid] > target) {
		//왼
		return binSearchL(s, mid - 1, target);
	}
	else {
		//오
		return binSearchL(mid + 1, e, target);
	}
}
int binSearchR(int s, int e, int target) {
	int mid = (s + e) / 2;
	if (s > e) return -1;
	if (cards[mid] == target) {
		if (mid+1 < n &&cards[mid + 1] == target) {
			return binSearchR(mid+1,e, target);
		}
		else { 
			return mid;
		}
	}
	else if (cards[mid] > target) {
		//왼
		return binSearchR(s, mid - 1, target);
	}
	else {
		//오
		return binSearchR(mid + 1, e, target);
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> cards[i];
	}
	
	sort(cards, cards + n);
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		int resultLeftPivot = binSearchL(0, n - 1, x);
		int resultRightPivot = binSearchR(0, n - 1, x);
		if (resultLeftPivot == -1 && resultRightPivot == -1) {
			cout << "0 ";
		}
		else {
			cout << resultRightPivot - resultLeftPivot + 1<<" ";
		}
	}
}