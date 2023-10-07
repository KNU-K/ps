#include <iostream>
using namespace std;
typedef struct maxNum {
	int data;
	int idx;
};
int main() {
	maxNum m;
	m.data = -1;
	m.idx = -1;
	for (int i = 1; i <= 9; i++) {
		int x;
		cin >> x;
		if (m.data < x) {
			m = { x,i };
		}
	}
	cout << m.data << "\n" << m.idx;
}