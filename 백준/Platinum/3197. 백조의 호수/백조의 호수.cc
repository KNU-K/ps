#include<iostream>
#include<queue>
using namespace std;
typedef struct{
    int x,y;
}point;
point dir[4] ={
    {1,0},
    {-1,0},
    {0,1},
    {0,-1}
};
int isVisited[1501][1501] ={0,};
pair<int,int> swan[2];
queue<pair<int,int>> q;

    queue<pair<int,int>> q1;
int swan_cnt = 0;
int map[1501][1501];

int x,y;

bool isMapLimited(int i,int j){
    return (0<=i)&&(i<x) && (0<=j)&&(j<y);
}

void meltIce(){
    int qSize = q.size();
    while(qSize--){
        pair<int,int> cur = q.front();
        q.pop();
        
        for(int i=0;i<4;i++){
            pair<int,int> next = {cur.first + dir[i].x, cur.second + dir[i].y};
            if(!isMapLimited(next.first, next.second))continue;
            
            if(map[next.first][next.second] == 2){
                map[next.first][next.second] = 1;
                q.push(next);
            }
        }
    }
}
bool isAbleToMeet(){
    queue<pair<int,int>> newQ;
    while(!q1.empty()){
        pair<int,int> cur = q1.front();
        q1.pop();
         if(cur.first == swan[1].first && cur.second == swan[1].second) return true;
         
        for(int i=0;i<4;i++){
            pair<int,int> next = {cur.first + dir[i].x, cur.second + dir[i].y};
            if(!isMapLimited(next.first, next.second))continue;
            if((map[next.first][next.second] == 1||map[next.first][next.second] == 3)&& isVisited[next.first][next.second] == 0){
                q1.push(next);
                isVisited[next.first][next.second] = 1;
            }else if(isVisited[next.first][next.second] ==0){
                newQ.push(next);
                isVisited[next.first][next.second] = 1;
            }
        }
    }
    q1 = newQ;
    return false;
    
}
int main(){
    cin.tie(0);
    cout.tie(0);
    
	ios::sync_with_stdio(false);
    cin >> x >> y;
    for(int i=0;i<x;i++){
        string m;
        cin >> m;
        for(int j=0; j<m.length(); j++){
            if(m[j]=='.'){
                map[i][j] = 1;
            }else if(m[j]=='X'){
                
                map[i][j] = 2;
            }else{
                
                map[i][j] = 3;
            }
            if(map[i][j] == 3){
                if(q1.empty()){
                    q1.push({i,j});
                }
                q.push({i,j});
                swan[swan_cnt++] = {i,j};
            }else if(map[i][j] == 1){
                q.push({i,j});
            }
        }
    }
    q1.push(swan[0]);
    
    int t=0;
    while(!q.empty()){
        if(isAbleToMeet()){
            cout << t;
            return 0;
        }
        t++;
        meltIce();
        
    
    }


}