#include <iostream>
#include <queue>
using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    
	ios::sync_with_stdio(false);
    priority_queue<int, vector<int>, greater<int>> right;
    priority_queue<int> left;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int tmp;
        int tmpL;
        int tmpR;
        cin >> tmp;
        if(left.empty()||left.size() == right.size()){
            left.push(tmp);
            
            if(!right.empty()){
                tmpL = left.top();
                tmpR = right.top();
                if(tmpL > tmpR){
                    left.pop();
                    right.pop();
                    right.push(tmpL);
                    left.push(tmpR);
                }
            }
        }else{
            right.push(tmp);
        
            if(!left.empty()){
                tmpL = left.top();
                tmpR = right.top();
                if(tmpL > tmpR){
                    left.pop();
                    right.pop();
                    right.push(tmpL);
                    left.push(tmpR);
                }
            }
        }
        if(right.empty()||left.top() < right.top()){
            cout << left.top()<<"\n";
        }else{
            cout << right.top()<<"\n";
        }
    }
}