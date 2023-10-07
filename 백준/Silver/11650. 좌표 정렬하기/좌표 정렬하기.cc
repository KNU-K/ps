#include <iostream>
using namespace std;
typedef struct POINT {
	int x, y;
}p;
p pointArr[100001];
p tempSortedPointArr[100001];
void mergePoint(int s, int mid, int e) {
	int i = s;
	int j = mid + 1;
	int k = s;
	while (i<=mid && j <=e){
		if (pointArr[i].x < pointArr[j].x) {
			tempSortedPointArr[k++] = pointArr[i++];
		}
		else if (pointArr[i].x > pointArr[j].x) {
			tempSortedPointArr[k++] = pointArr[j++];
		}
		else {
			if (pointArr[i].y < pointArr[j].y) tempSortedPointArr[k++] = pointArr[i++];
			else tempSortedPointArr[k++] = pointArr[j++];
		}
	}
	while(i <= mid) {
		tempSortedPointArr[k++] = pointArr[i++];
	}
	while(j<=e){
		tempSortedPointArr[k++] = pointArr[j++];
	}
	for (int i = s; i <= e; i++) {
		pointArr[i] = tempSortedPointArr[i];
	}
}
void sortPoint(int s, int e) {
	if (s!= e) {
		int mid = (s + e) / 2;
		sortPoint(s, mid);
		sortPoint(mid + 1, e);
		mergePoint(s,mid, e);
	}
}
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> pointArr[i].x >> pointArr[i].y;
	}
	sortPoint(0,t-1);

	for (int i = 0; i < t; i++) {
		cout << pointArr[i].x <<" "<< pointArr[i].y << "\n";
	}

}