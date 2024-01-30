#include <iostream>
#define quadrant(x,y) ((x>0)?(y>0?1:4):(y>0?2:3))
using namespace std;
int main() {
	int x, y;
	cin >> x >> y;
	cout << quadrant(x, y);
}