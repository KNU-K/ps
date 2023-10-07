#include <iostream>
#include <queue>
#define min(a,b) (a>b?b:a)
using namespace std;
typedef struct INFO {
	int num;
	int time;
}I;
int visited[100001] = { 0, };
int cnt = 0;
bool isMapLimited(int x) {
	return 0 <= x && x <= 100000;
}
int bfsSearch(int s, int e) {
	queue <I> q;
	q.push({ s,0 });
	visited[s] = 0;
	int result = 987654321;
	while (!q.empty()) {
		int curNum = q.front().num;
		int curTime = q.front().time;
		q.pop();
		visited[curNum] = 1;
		if (result < curTime) break;
		if (curNum == e) {
			result = min(result, curTime);
			cnt++;
			continue;
		}

		int nextNum = curNum - 1;
		int nextTime = curTime + 1;
		if (isMapLimited(nextNum) && !visited[nextNum]) {
			q.push({ nextNum, nextTime });
		}

		nextNum = curNum + 1;
		nextTime = curTime + 1;
		if (isMapLimited(nextNum) && !visited[nextNum]) {
			q.push({ nextNum, nextTime });
		}
		
		nextNum = curNum *2;
		nextTime = curTime + 1;
		if (isMapLimited(nextNum) && !visited[nextNum]) {
			q.push({ nextNum, nextTime });
		}

	}
	return result;
}
int main() {
	int n, k;
	cin >> n >> k;

	cout << bfsSearch(n, k) << "\n" << cnt;
}