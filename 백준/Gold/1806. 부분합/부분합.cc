#include <iostream>
using namespace std;

int arr[100000];

int main()
{
	int N, S;
	cin >> N >> S;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int ans = -1;
	long long sum = 0;
	int start = 0, end = 0;
	while (1) {
		if (sum >= S)
			sum -= arr[start++];
		else if (end == N)
			break;
		else
			sum += arr[end++];

		if (sum >= S && (ans == -1 || end - start < ans))
			ans = end - start;
	}
	if (ans == -1)
		cout << 0;
	else
		cout << ans;
}