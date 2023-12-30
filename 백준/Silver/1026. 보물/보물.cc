#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool cmp(const int& v1, const int& v2) {
	return v1 < v2;
}
bool cmp1(const int& v1, const int& v2) {
	return v1 > v2;
}
int main() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	sort(a.begin(), a.end(), cmp);
	sort(b.begin(), b.end(), cmp1);
	int rs = 0;
	for (int i = 0; i < n;i++) {
		rs += a[i] * b[i];
	}
	cout << rs<<"\n";


}