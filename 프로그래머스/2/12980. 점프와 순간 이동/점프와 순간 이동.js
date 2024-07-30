/**
1. 한번에 K칸을 앞으로 이동 ( K만큼 건전지 사용 )
2. 현재까지 온 거이에 2배로 순간이동 ( 건전지 사용 x )
최단 경로로

처음위치 0 -> n
**/
function solution(n)
{
    let bat =0 ;
    while(n!=0){
        if(n%2 === 0) n/=2;
        else{
            n-=1;
            bat++;
        }
    }
    return bat;
}