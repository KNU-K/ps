#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>
#define XYcost(x,y) (x>y?x-y : y-x)
using namespace std;
vector<pair<double, double>> star;
vector<pair<double, pair<int, int>>> mat;
int parent[101];

int _find(int x){
	if (parent[x] == x) return x;

	return parent[x] = _find(parent[x]);
}
void _union(int x, int y) {
	x = _find(x);
	y = _find(y);
	if (x <= y) parent[y] = x;
	else parent[x] = y;
}
double getCost(double x1, double y1, double x2, double y2) {
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	int n; // edge
	cin >> n;
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}
	for (int i = 1; i <= n; i++) {
		double x, y;
		cin >> x >> y;
		star.push_back({ x,y });
	}
	for (int i = 0; i < n-1; i++) {
		for (int j = 1; j < n; j++) {
			double cost = getCost(star[i].first, star[i].second, star[j].first, star[j].second);
			mat.push_back({ cost,{i,j} });
		}
	}
	sort(mat.begin(),mat.end());
	double ans = 0;
	for (int i = 0; i < mat.size(); i++) {
		if (_find(mat[i].second.first) != _find(mat[i].second.second)) {
			_union(mat[i].second.first, mat[i].second.second);
			ans += mat[i].first;
		}
	}
	printf("%.2lf", ans);

}