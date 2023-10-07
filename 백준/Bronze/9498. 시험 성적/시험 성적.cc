#include <iostream>
using namespace std;
int main() {
	int score;
	cin >> score;
	cout<<(90 <= score && score <= 100 ? 'A' :
		80 <= score && score <= 89 ? 'B' :
		70 <= score && score <= 79 ? 'C' :
		60 <= score && score <= 69 ? 'D' : 'F');
}