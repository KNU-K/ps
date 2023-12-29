#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int totalOfBeer = 20;
typedef struct {
	int x;
	int y;
}POINT;
typedef struct {
	POINT p;
	bool isVisited;
}STORE_POINT;

vector<STORE_POINT> stores;
POINT home;
POINT festival;
POINT dir[4] = {
	{50,0},
	{-50,0},
	{0,50},
	{0,-50}
};
//1 beer per 50 meter
int bfs() {
	queue<POINT> q;
	q.push({ home.x, home.y });

	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		q.pop();
		// festival 까지 바로 갈 수 있냐?
		// festival 이면 끝 성공
		int dest_x = (cx > festival.x) ? cx - festival.x : festival.x - cx;
		int dest_y = (cy > festival.y) ? cy - festival.y : festival.y - cy;

		int totalOfDest = dest_x + dest_y;
		if (totalOfDest <= totalOfBeer * 50) {
			return 1;
		}
		// 편의점 갈수있냐 subset 되냐?
		// 편의점은 queue 에 넣기
		for (int i = 0; i < stores.size();i++) {
			if (stores[i].isVisited == true) continue;

			int dest_x = (cx > stores[i].p.x) ? cx - stores[i].p.x : stores[i].p.x - cx;
			int dest_y = (cy > stores[i].p.y) ? cy - stores[i].p.y : stores[i].p.y - cy;

			int totalOfDest = dest_x + dest_y;
			if (totalOfDest <= totalOfBeer * 50) {
				q.push(stores[i].p);
				stores[i].isVisited = true;
			}

		}
			
		
	}
	// 실패
	return -1;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		cin >> home.x >> home.y;
		stores.clear();
		for (int i = 0; i < n;i++) {
			int x, y;
			cin >> x >> y;
			stores.push_back({ { x,y }, false });
		}
		cin >> festival.x >> festival.y;
		if (bfs()== -1) {
			cout << "sad\n";
		}
		else {
			cout << "happy\n";
		}
	}
}