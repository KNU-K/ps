#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> vec(30,0);
int main() {
	for (int i = 0; i < 28;i++) {
		int x;
		cin >> x;
		vec[x - 1] = 1;
	}
	int idx = 1;
	for (auto e : vec) {
		if (e == 0) {
			cout << idx << "\n";
		}
		idx++;
	}
}