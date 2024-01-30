#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	int i = 1;
	while (n--) {
		int x, y;
		cin >> x >> y;
		cout <<"Case #"<<i<<": "<< x + y << "\n";
		i++;
	}

}