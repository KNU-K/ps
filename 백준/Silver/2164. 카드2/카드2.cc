#include <iostream>
#include <queue>
using namespace std;
queue<int> cards;

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cards.push(i);

	while (cards.size() != 1) {
		cards.pop();
		cards.push(cards.front());
		cards.pop();
	}
	cout << cards.front();
}