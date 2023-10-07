#include <iostream>
#include <string>
using namespace std;


int main() {
    string txt;
    getline(cin, txt);
    if (txt == " ") {
        cout << 0; return 0;
    }
    int cnt = 0;
    for (int i = 1; i < txt.length() - 1; i++) {
        if (txt[i] == ' ') {
            cnt++;
        }
    }
    cout << cnt + 1;
}