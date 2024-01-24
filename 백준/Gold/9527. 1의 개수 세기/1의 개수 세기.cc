#include <iostream>
using namespace std;
long long A = 0;
long long B = 0;
long long dp[55] = {};
 
long long BinaryNumber(long long x, long long  i = 54) 
{
    long long  ans = x & 1;
 
    for (; i > 0; --i) 
    {
        if (x & (1LL << i))
        {
            ans += dp[i - 1] + (x - (1LL << i) + 1);
            x -= 1LL << i;
        }
    }
 
    return ans;
}
 
 
int main()
{
    dp[0] = 1;
 
    for (long long  i = 1; i < 55; ++i) 
    {
        dp[i] = dp[i - 1] * 2 + (1LL << i);
    }
 
    cin >> A >> B;
    cout << BinaryNumber(B) - BinaryNumber(A - 1);
}