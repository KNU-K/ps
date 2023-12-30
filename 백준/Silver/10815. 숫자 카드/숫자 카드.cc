#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int arr[2][10000001] = { 0, };
int main() {
	int n,x;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> x;
		if (x < 0) {
			arr[1][x * -1] ++;
		}
		else {
			arr[0][x]++;
		}
	}
	cin >> n;
	vector<int> ans;
	for (int i = 0; i < n;i++) {
		cin >> x;
		if (x < 0) {
			if (arr[1][x * -1] != 0) {
				ans.push_back(1);
			}
			else {
				ans.push_back(0);
			}
		}
		else {
			if(arr[0][x] != 0) {
				ans.push_back(1);
			}
			else {
				ans.push_back(0);
			}
		}
	}
	for (auto e : ans) {
		cout << e << " ";
	}
	
	
}