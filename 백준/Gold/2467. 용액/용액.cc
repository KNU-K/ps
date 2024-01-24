#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; ++i)
        cin >> v[i];
    int left = 0, right = N - 1, leftNum = v[0], rightNum = v[N - 1];
    while (left < right)
    {
        int sum = abs(v[left] + v[right]);
        if (abs(leftNum + rightNum) > sum)
        {
            leftNum = v[left];
            rightNum = v[right];
        }
        if (abs(v[left + 1] + v[right]) < abs(v[left] + v[right - 1]))
            ++left;
        else
            --right;
    }
    cout << leftNum << " " << rightNum;
    return 0;
}