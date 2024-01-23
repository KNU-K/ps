#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
int vec1[500001];
int lis[500001];
int record[500001];
int main() {
	int n;
	cin >> n;
	int lastIdx = -1;
	int startIdx = 10000000;
	for (int i = 0; i < n;i++) {
		int idx, idxb;
		cin >> idx >> idxb;
		lastIdx = max(idx, lastIdx);
		startIdx = min(idx, startIdx);
		vec1[idx] = idxb;
	}

	lis[startIdx] = vec1[startIdx];
	int k = startIdx;
	record[startIdx] = startIdx;
	for (int i = startIdx + 1; i <= lastIdx;i++) {
		if (vec1[i] == 0) {
			record[i] = -1;
			continue;
		}
		if (lis[k] < vec1[i]) {
			lis[++k] = vec1[i];
			record[i] = k;
		}
		else {
			auto idx = lower_bound(lis+startIdx, lis +k, vec1[i]);
			(*idx) = vec1[i];
			record[i] = idx - lis;
		}
	}
	stack<int> ans;
	int pivot = k;
	int ans_cnt = 0;
	for (int i = lastIdx; i >= startIdx;i--) {
		if (record[i] == -1) continue;
		if (record[i] == pivot) {
			pivot--;
		}
		else {
			ans_cnt++;
			ans.push(i);
		}
	}
	cout << ans_cnt << "\n";
	while (!ans.empty()) {
		cout << ans.top() << "\n";
		ans.pop();
	}

}