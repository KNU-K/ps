#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef struct POINT{
    int x,y;
}POINT;

POINT dir[4] = {
    {1,0},
    {-1,0},
    {0,1},
    {0,-1}
};
queue<POINT> fire;
queue<POINT> man;

string map[1001];
int visited[1001][1001]={0,};

int w,h;
int isMapLimited(int nx, int ny){
    return (0<=nx) && (nx<h) && (0<=ny) && (ny<w);
}
int bfs(){
    visited[man.front().x][man.front().y] = 1;
    while(!man.empty()){
        int fireSz = fire.size();

        while(fireSz--){   
            POINT cur =fire.front();
            fire.pop();
            for(int i=0;i<4;i++){
                POINT next = {cur.x + dir[i].x, cur.y + dir[i].y};
                if(!isMapLimited(next.x,next.y))continue;
                if(map[next.x][next.y] != '.')continue;
                    
                map[next.x][next.y] = '*';
                fire.push({next.x, next.y});
                
            }
        }


        int manSz = man.size();
        while(manSz--){
            POINT cur = man.front();
            man.pop();
            if(cur.x == h-1||cur.x == 0||cur.y == 0||cur.y == w-1 )
            return visited[cur.x][cur.y];

            for(int i=0;i<4;i++){
                POINT next = {cur.x + dir[i].x, cur.y + dir[i].y};
                if(!isMapLimited(next.x,next.y))continue;
                if(map[next.x][next.y] != '.')continue;
                if(visited[next.x][next.y]!=0) continue;;
                man.push({next.x, next.y});
                
                visited[next.x][next.y] = visited[cur.x][cur.y] +1;
            }
        }
        
    }
    return -1;
}
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){

        cin >> w >> h;
        for(int i=0;i<h;i++){
            cin >> map[i];
            for(int j=0;j<w;j++){
                visited[i][j] =0;
                if(map[i][j] == '*'){
                    fire.push({i,j});
                }else if(map[i][j] == '@'){
                    man.push({i,j});
                }
            }
        }
        int res = bfs();
        if(res == -1){
            cout << "IMPOSSIBLE\n";
        }else{
            cout << res<<"\n";
        }
        while (!fire.empty()) fire.pop();
        while (!man.empty()) man.pop();

    }
}