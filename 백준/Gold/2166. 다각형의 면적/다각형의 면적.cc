#include <iostream>
#include <vector>
#include <cstdio>
#define abs(x) (x<0? -x:x)
#define ll long long
using namespace std;
typedef struct {
	ll x;
	ll y;
}POINT;
vector<POINT> v;
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll x, y;
		cin >> x >> y;
		v.push_back({x,y});
	}
	long double a=0, b=0;
	for (int i = 0; i < n-1;i++) {
		a += (v[i].x * v[i + 1].y);
		a -= (v[i].y * v[i + 1].x);
	}
	a += v[n - 1].x * v[0].y;
	a -= v[0].x * v[n-1].y;
	a = abs(a);
	a /= 2;
	printf("%.1Lf", a);
}



