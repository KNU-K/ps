#include <iostream>
using namespace std;

string blackStartedChessBoard[8] = { "BWBWBWBW",
                                    "WBWBWBWB",
                                    "BWBWBWBW",
                                    "WBWBWBWB",
                                    "BWBWBWBW",
                                    "WBWBWBWB",
                                    "BWBWBWBW",
                                    "WBWBWBWB" };
string whiteStartedChessBoard[8] = { "WBWBWBWB",
                                    "BWBWBWBW",
                                    "WBWBWBWB",
                                    "BWBWBWBW",
                                    "WBWBWBWB",
                                    "BWBWBWBW",
                                    "WBWBWBWB",
                                    "BWBWBWBW" };
string pbBoard[51];
int searchBlackStartedChessBoard(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (pbBoard[x+i][y+j] != blackStartedChessBoard[i][j]) cnt++;
        }
    }
    return cnt;
}
int searchWhiteStartedChessBoard(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (pbBoard[x + i][y + j] != whiteStartedChessBoard[i][j]) cnt++;
        }
    }
    return cnt;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> pbBoard[i];
    }
    int blackCnt = 2601;
    int whiteCnt = 2601;
    for (int i = 0; i < n - 7; i++) {
        for (int j = 0; j < m -7; j++) {      
            int tempBlackCnt = searchBlackStartedChessBoard(i, j);
            int tempWhiteCnt = searchWhiteStartedChessBoard(i, j);
            if (tempBlackCnt == 0 || tempWhiteCnt == 0) {
                cout << 0;
                return 0;
            }
            if (tempBlackCnt < blackCnt) blackCnt = tempBlackCnt;
            if (tempWhiteCnt < whiteCnt) whiteCnt = tempWhiteCnt;

        }
    }
    cout << (blackCnt > whiteCnt ? whiteCnt : blackCnt);
}