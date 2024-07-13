#include <iostream>
#include <map>
using namespace std;
int mat[200001];

int main(){
    int n, k, num;
    cin >> n >> k;
    map<int, long long> m;
    long long cnt = 0;
    m[0] = 1;
    for (int i=1; i<=n; i++){
        cin >> num;
        mat[i] = mat[i-1] + num;
        cnt += m[mat[i] - k];
        m[mat[i]]++;
    }
    cout << cnt;
}