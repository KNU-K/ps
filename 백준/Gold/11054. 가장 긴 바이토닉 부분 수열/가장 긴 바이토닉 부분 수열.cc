#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[1001] = { 0, };
int inc[1001] = { 0, };  // 증가하는 부분 수열의 길이
int decs[1001] = { 0, };  // 감소하는 부분 수열의 길이

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 증가하는 부분 수열의 길이 계산
    for (int i = 0; i < n; i++) {
        inc[i] = 1;  // 각 원소에서 시작하는 최소 길이는 1
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && inc[i] < inc[j] + 1) {
                inc[i] = inc[j] + 1;
            }
        }
    }

    // 감소하는 부분 수열의 길이 계산
    for (int i = n - 1; i >= 0; i--) {
        decs[i] = 1;  // 각 원소에서 시작하는 최소 길이는 1
        for (int j = n - 1; j > i; j--) {
            if (arr[i] > arr[j] && decs[i] < decs[j] + 1) {
                decs[i] = decs[j] + 1;
            }
        }
    }

    // 가장 긴 바이토닉 부분 수열의 길이 계산
    int max_len = 0;
    for (int i = 0; i < n; i++) {
        max_len = max(max_len, inc[i] + decs[i] - 1);
    }

    cout << max_len << "\n";

    return 0;
}
