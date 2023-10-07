#include <iostream>
using namespace std;

typedef struct DIRECTORY {
	int age;
	string name;
}dir;

dir directoryList[100001];
dir sortedDirectory[100001];
void sort_merge(int s, int middle, int e) {
	int i = s;
	int j = middle + 1;
	int k = s;
	while (i <= middle && j <= e) {
		if (directoryList[i].age < directoryList[j].age) {
			sortedDirectory[k++] = directoryList[i++];
		}else if (directoryList[i].age > directoryList[j].age) {
			sortedDirectory[k++] = directoryList[j++];
		}else {
			sortedDirectory[k++] = directoryList[i++];
		}
	}
	if (i <= middle) {
		for (; i <= middle; i++) {
			sortedDirectory[k++] = directoryList[i];
		}
	}
	else {
		for (; j <= e; j++) {
			sortedDirectory[k++] = directoryList[j];
		}
	}

	for (int i = s; i <= e; i++) {
		directoryList[i] = sortedDirectory[i];
	}

}
void sort_divided(int s, int e) {
	if (s != e) {
		int middle = (s + e) / 2;
		sort_divided(s, middle);
		sort_divided(middle + 1, e);
		sort_merge(s, middle, e);
	}
}
void sort(int s, int e) {
	sort_divided(s, e);
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n;i++) cin >> directoryList[i].age >> directoryList[i].name;		
	sort(0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << directoryList[i].age << " " << directoryList[i].name<<"\n";
	}
}