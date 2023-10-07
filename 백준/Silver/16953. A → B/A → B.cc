#include <iostream>
#include <queue>
using namespace std;
bool isMapLimited(long long v) {
	return (1 <= v && v <= 1000000000);
}
long long bfsSearch(long long s, long long e) {
	queue<pair<long long, long long>> q;
	q.push({ s,1 });

	while (!q.empty()) {
		long long cur = q.front().first;
		long long count = q.front().second;
		q.pop();
		if (cur == e)return count;
		long long nv = cur * 2;
		if (isMapLimited(nv)) {
			q.push({ nv,count + 1 });
		}
		nv = cur * 10 + 1;
		if (isMapLimited(nv)) {
			q.push({ nv,count + 1 });

		}
	}
	return -1;
}
int main() {
	long long a, b;
	cin >> a >> b;
	cout << bfsSearch(a, b);
}