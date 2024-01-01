#include <iostream>
#include <cstring>
using namespace std;

int d[10010];

int main()
{
    int T; cin >> T;
    while (T--)
    {
        int N; cin >> N;
        d[0] = 1;
        for (int i = 1; i <= 3; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (j - i < 0) continue;
                d[j] += d[j - i];
            }
        }

        cout << d[N] << '\n';
        memset(d, 0, sizeof(d));
    }
}