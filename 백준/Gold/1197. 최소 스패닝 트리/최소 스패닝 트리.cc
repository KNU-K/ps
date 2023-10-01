#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int parent[10001];
typedef struct{
	int s;
	int d;
	int w;
}Edge;

int findfunc(int x){
	if(parent[x] == x) return x;
	
	return parent[x] = findfunc(parent[x]);
}
void unionfunc(int x, int y){
	x = findfunc(x);
	y = findfunc(y);

	if(x != y){
		parent[y] = x;
	}
}
bool isSame(int x, int y){
	x = findfunc(x);
	y = findfunc(y);

	if(x == y)return true;
	return false;
}


bool cmp(Edge e1, Edge e2){

	return e1.w < e2.w;
}
int main(){
	int v,e;
	vector<Edge> vec;
	cin >> v >> e;
	for(int i=0;i<=v;i++){
		parent[i] = i;		
	}
	for(int i=0;i<e;i++){
		int s,d, w;
		cin >> s >> d>> w;
		vec.push_back({s,d,w});
	}
	sort(vec.begin(), vec.end(), cmp);
	
	
	int vecSize = vec.size();
	int sum =0;
	for(int i=0;i<vecSize;i++){

		Edge curEdge = vec[i];
		
		if(!isSame(curEdge.s, curEdge.d)){
			unionfunc(curEdge.s, curEdge.d);
			sum += curEdge.w;
		}
	}
	cout << sum ;
}