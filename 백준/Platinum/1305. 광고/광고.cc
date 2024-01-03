#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n;
string text, pattern;
vector<int> failure;

int main() {
    cin >> n >> text;
    pattern = text;
    failure.resize(n + 1, 0);
    int j = 0;
    for (int i = 1; i < n; i++) {
        while (j > 0 && pattern[j] != text[i]) {
            j = failure[j - 1];
        }
        if (pattern[j] == text[i]) {
            failure[i] = ++j;
        }
    }

    cout << n - failure[n - 1];
    return 0;
}
