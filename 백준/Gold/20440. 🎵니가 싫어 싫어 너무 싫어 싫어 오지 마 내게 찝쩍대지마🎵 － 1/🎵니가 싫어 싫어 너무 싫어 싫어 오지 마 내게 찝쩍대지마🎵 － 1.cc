#include <iostream>
#include <vector>
#include <algorithm>

#define N 1000001

using namespace std;

struct Interval {
    int p, q;
};

vector<int> V;
int n, s[N * 2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<Interval> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i].p >> a[i].q;
        V.push_back(a[i].p);
        V.push_back(a[i].q);
    }

    sort(V.begin(), V.end());
    V.erase(unique(V.begin(), V.end()), V.end());

    for (int i = 0; i < n; i++) {
        int idx_p = lower_bound(V.begin(), V.end(), a[i].p) - V.begin() + 1;
        int idx_q = lower_bound(V.begin(), V.end(), a[i].q) - V.begin() + 1;
        s[idx_p]++;
        s[idx_q]--;
    }

    int r = 0, x = 0, y = 0;
    for (int i = 1; i < N * 2; i++) {
        s[i] += s[i - 1];
        if (s[i] > r) {
            r = s[i];
        }
    }

    for (int i = 0; i < N * 2; i++) {
        if (s[i] == r) {
            if (x == 0) {
                x = i;
            }
            if (y == 0) {
                y = i;
            } else {
                y = i;
            }
        } else if (x != 0 && s[i] != r) {
            break;
        }
    }

    cout << r << '\n' << V[x - 1] << ' ' << V[y];

    return 0;
}
