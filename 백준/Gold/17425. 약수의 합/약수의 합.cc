#include <iostream>

using namespace std;

long long dp[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int i = 1; i < 1000001; i++) {
        for (int j = i; j < 1000001; j += i) {
            dp[j] += i;
        }
        dp[i] += dp[i - 1];
    }

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }
    return 0;
}