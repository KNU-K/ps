#include<iostream>

using namespace std;

int N, M, H[100000], a, b, k, o[100001], sum=0;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>N>>M;

    for(int i=0; i<N; i++) cin>>H[i];

    for(int i=0; i<M; i++)
    {
        cin>>a>>b>>k;
        o[a-1]+=k;
        o[b]-=k;
    }
    
    for(int i=0; i<N; i++)
    {
        sum+=o[i];
        H[i]+=sum;
        cout<<H[i]<<' ';
    }

    return 0;
}