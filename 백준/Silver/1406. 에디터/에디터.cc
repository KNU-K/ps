#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    string str;
    stack<char> left, right;
    char cmd, a;

    cin >> str;

    for (char ch : str) {
        left.push(ch);
    }

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> cmd;

        switch (cmd) {
        case 'P':
            cin >> a;
            left.push(a);
            break;
        case 'L':
            if (!left.empty()) {
                right.push(left.top());
                left.pop();
            }
            break;
        case 'D':
            if (!right.empty()) {
                left.push(right.top());
                right.pop();
            }
            break;
        case 'B':
            if (!left.empty()) {
                left.pop();
            }
            break;
        }
    }

    while (!left.empty()) {
        right.push(left.top());
        left.pop();
    }

    while (!right.empty()) {
        cout << right.top();
        right.pop();
    }

    cout << "\n";

    return 0;
}
