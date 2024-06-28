#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int size, query;
    cin>>size>>query;
    
    vector<vector<int>> org(size+1, vector<int>(size+1, 0));
    vector<vector<int>> sum(size+1, vector<int>(size+1, 0));
    
    for (int i=1;i<=size;i++){
        for (int j=1;j<=size;j++){
            cin >> org[i][j];
            sum[i][j] = sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+org[i][j];
        }
    }

    for (int i=0;i<query;i++){
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;
        int result = sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1];
        cout<<result<<"\n";
    }
    return 0;
}