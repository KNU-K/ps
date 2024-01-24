#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <deque>
#include <queue>

using namespace std;

int n, k; // 보석 갯수/ 가방 갯수

long long c[300001];// 가방에 들어갈수 있는 무게

vector<pair<long long, long long>>item;// 보석 무게 / 보석 가격

priority_queue<int> pq; 

long long answer=0;


int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> k;
	

	for (int i = 0; i < n; i++) { // 보석들 받기
		pair<long long, long long>temp;

		cin >> temp.first >> temp.second;
		item.push_back(temp);
		
	}


	for (int i = 0; i < k; i++) { // 가방 무게 받기  // 가방 한개당 한개의 보석
		cin >> c[i];
	}
	
	sort(item.begin(), item.end());// 아이템

	sort(c, c + k); // 가방

	int idx = 0;
	for (int i = 0; i < k; i++) {

		while (idx < n && item[idx].first <= c[i]) {
			pq.push(item[idx].second);
			idx += 1;
		}

		if (!pq.empty()) {
			answer += pq.top();
			pq.pop();
		}
	}
	
	cout << answer;


	return 0;

}