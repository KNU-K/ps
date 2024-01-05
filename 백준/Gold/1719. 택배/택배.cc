#include <iostream>
#include <queue>
#include <vector>
#define INF 9999999
using namespace std;
vector<pair<int,int>> matrix[1001];
int pv[201]; //previous vertax
int dist[201];

// n is vertices
// m is edges
int n, m;
void dijkstra(int sv) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({ 0, sv });


	while (!q.empty()) {
		int c = q.top().first;
		int v = q.top().second;
		q.pop();

		if (c > dist[v]) continue;

		for(auto e: matrix[v]){
			if (e.second + c < dist[e.first]) {
				dist[e.first] = e.second + c;

				pv[e.first] = v;
				q.push({ dist[e.first],e.first });
			}
		}
	}

}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> m;	
	for (int i = 0; i < m; i++) {
		int x, y, c;
		cin >> x >> y >> c;
		matrix[x].push_back({y,c});
		matrix[y].push_back({x,c});
	}

	for (int i = 1; i <= n; i++) {
		for (int a = 1; a <= n; a++) {
			dist[a] = INF;
			pv[a] = a;
		}
		dijkstra(i);

		for (int j = 1; j <= n; j++) {
			if (i == j) {
				cout << "- ";
				continue;
			}
			int temp = j;
			while (pv[temp] != i) {
				temp = pv[temp];
			}
			cout << temp << " ";
		}
		//1 1 1 3 2 5
		cout << "\n";

	}
}