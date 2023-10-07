#include <iostream>
using namespace std;

int main() {
    int alarmHour, alarmMin;
    cin >> alarmHour >> alarmMin;

    alarmMin -= 45;
    if (alarmMin < 0) {
        alarmMin += 60; 
        alarmHour = (alarmHour - 1 < 0 ? alarmHour + 23 : alarmHour-1);
    }
    cout << alarmHour << " " << alarmMin;
}