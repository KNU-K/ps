#include <iostream>
#include <queue>
using namespace std;
typedef struct POINT {
	int data;
	string result;
}p;
int visited[10001] = { 0, };
bool islimtedNum(int data) {
	return 0 <= data && data < 10000;
}
string bfsSearch(int s, int e) {
	queue<p> q;
	q.push({ s,"" });
	visited[s] = 1;
	while (!q.empty()) {
		p cur = q.front();
		q.pop();
		if (cur.data == e) {
			return cur.result;
		}
		/*
		D: D 는 n을 두 배로 바꾼다. 결과 값이 9999 보다 큰 경우에는 10000 으로 나눈 나머지를 취한다. 그 결과 값(2n mod 10000)을 레지스터에 저장한다.
		S: S 는 n에서 1 을 뺀 결과 n-1을 레지스터에 저장한다. n이 0 이라면 9999 가 대신 레지스터에 저장된다.
		L: L 은 n의 각 자릿수를 왼편으로 회전시켜 그 결과를 레지스터에 저장한다. 이 연산이 끝나면 레지스터에 저장된 네 자릿수는 왼편부터 d2, d3, d4, d1이 된다.
		R: R 은 n의 각 자릿수를 오른편으로 회전시켜 그 결과를 레지스터에 저장한다. 이 연산이 끝나면 레지스터에 저장된 네 자릿수는 왼편부터 d4, d1, d2, d3이 된다.
		*/
		p next = { (cur.data * 2)% 10000, cur.result + "D" };
		if (islimtedNum(next.data) && !visited[next.data]) {
			visited[next.data] = 1;
			q.push(next);
		}

		next = { (cur.data - 1 < 0) ? 9999 : (cur.data - 1), cur.result + "S" };
		if (islimtedNum(next.data) && !visited[next.data]) {
			visited[next.data] = 1;
			q.push(next);

		}

		next = { ((cur.data % 1000) * 10) + (cur.data / 1000), cur.result + "L" };
		if (islimtedNum(next.data) && !visited[next.data]) {
			visited[next.data] = 1;
			q.push(next);

		}
		next = { ((cur.data % 10) * 1000) + (cur.data / 10), cur.result + "R" };
		if (islimtedNum(next.data) && !visited[next.data]) {
			visited[next.data] = 1;
			q.push(next);

		}

	}
}
void initializeVisited() {
	for (int i = 0; i < 10001; i++) {
		visited[i] = 0;
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--) {
		initializeVisited();
		int s, e;
		cin >> s >> e;
		cout << bfsSearch(s, e)<<"\n";
	}
}