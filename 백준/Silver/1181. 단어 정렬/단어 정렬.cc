#include <iostream>
using namespace std;
string words[20001];
string sortedWords[20001];
void sort_merge(int s, int middle, int e) {
	int i = s;
	int j = middle+1;
	int k = s;
	while (i <= middle && j <= e) {
		if (words[i].length() > words[j].length()) sortedWords[k++] = words[j++];
		else if (words[i].length() < words[j].length())  sortedWords[k++] = words[i++];
		else{
			if (words[i] <= words[j]) sortedWords[k++] = words[i++];
			else sortedWords[k++] = words[j++];
		}
	}
	if (i > middle) {
		for (; j <= e; j++) {
			sortedWords[k++] = words[j];
		}
	}
	else {
		for (; i <= middle; i++) {
			sortedWords[k++] = words[i];
		}
	}

	for (int i = s; i <= e;i++) {
		words[i] = sortedWords[i];
	}

}
void sort_divided(int s, int e) {
	if (s != e) {
		int middle = (s + e) / 2;
		sort_divided(s, middle);
		sort_divided(middle + 1, e);
		sort_merge(s,middle,e);
	}
}
void sort(int s,int e) {
	sort_divided(s,e);
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> words[i];
	
	sort(0, n - 1);
	string posit = "";
	for (int i = 0; i < n;i++) {
		if (posit == "") {
			posit = words[i];
			cout << words[i] << "\n";
			continue;
		}
		else {
			if (posit == words[i]) continue;
			else {

				posit = words[i];
				cout << words[i] << "\n";
			}
		}
	}
}