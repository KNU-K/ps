#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int r;
        string txt;
        cin >> r >> txt;
        for (int i = 0; i < txt.length(); i++) {
            for (int j = 0; j < r; j++)cout << txt[i];
        }
        cout << "\n";
    }
}