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
	while (!q.empty()) {
		int curNum = q.front().num;
		int curTime = q.front().time;
		q.pop();
		if (curNum == e) {
			return curTime;
		}
		int nextNum = curNum * 2;
		int nextTime = curTime;
		if (isMapLimited(nextNum) && !visited[nextNum]) {
			q.push({ nextNum, nextTime });
			visited[nextNum] = 1;
		}
		nextNum = curNum - 1;
		nextTime = curTime + 1;
		if (isMapLimited(nextNum) && !visited[nextNum]) {
			q.push({ nextNum, nextTime });
			visited[nextNum] = 1;
		}

		nextNum = curNum + 1;
		nextTime = curTime + 1;
		if (isMapLimited(nextNum) && !visited[nextNum]) {
			q.push({ nextNum, nextTime });
			visited[nextNum] = 1;
		}
		
		

	}
}
int main() {
	int n, k;
	cin >> n >> k;

	cout << bfsSearch(n, k);
}