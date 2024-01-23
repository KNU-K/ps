#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[1001] = {0};
int inc[1001] = {0};
int desc[1001] = {0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Calculate increasing LIS
    for (int i = 0; i < n; i++) {
        inc[i] = 1; // Minimum length is 1
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && inc[i] < inc[j] + 1) {
                inc[i] = inc[j] + 1;
            }
        }
    }

    // Calculate decreasing LIS
    for (int i = n - 1; i >= 0; i--) {
        desc[i] = 1; // Minimum length is 1
        for (int j = n - 1; j > i; j--) {
            if (arr[i] > arr[j] && desc[i] < desc[j] + 1) {
                desc[i] = desc[j] + 1;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, inc[i] + desc[i] - 1); // Subtract 1 because we counted the element twice
    }

    cout << ans << "\n";

    return 0;
}
