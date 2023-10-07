#include <iostream>
#define min(a,b) (a>b? b:a)
#define abs(a) (a<0 ? a*-1: a)
using namespace std;
int main() {
    int x, y, w, h;
    cin >> x >> y >> w >> h;
    
   cout <<min((abs(w - x) < x ? abs(w - x) : x), (abs(h - y) < y ? abs(h - y) : y));
}