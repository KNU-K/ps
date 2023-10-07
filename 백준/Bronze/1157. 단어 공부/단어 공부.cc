#include <iostream>
#include <algorithm>
using namespace std;

int alpha[26] = { 0, };

int main() {
    string txt;
    cin >> txt;
    for (int i = 0; i < txt.length(); i++) {
        if ('a' <= txt[i] && txt[i] <= 'z') {
            alpha[txt[i] - 'a']++;
        }
        else if ('A' <= txt[i] && txt[i] <= 'Z') {
            alpha[txt[i] - 'A']++;
        }
    }
    int maxNum = -1;
    int maxIdx = -1;
    for (int i = 0; i < 26; i++) {
        if (maxNum < alpha[i]) {
            maxNum = alpha[i];
            maxIdx = i;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (i != maxIdx && maxNum == alpha[i]) {
            cout << "?";
            return 0;
        }
    }
    cout << (char)(maxIdx + 'A');

}
