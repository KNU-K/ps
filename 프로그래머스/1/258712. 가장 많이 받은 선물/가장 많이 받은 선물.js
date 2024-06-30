function solution(friends, gifts) {
    const n = friends.length
    var answer = new Array(n).fill(0)
    const dp = new Array(n).fill(0)
    const map = new Map()
    const board = Array.from(new Array(n),()=>new Array(n).fill(0))
    friends.forEach((f,i)=>{
        map.set(f,i)
    })
    gifts.map(g=>g.split(' '))
        .forEach(([from,to])=>{        
        board[map.get(from)][map.get(to)]++
        dp[map.get(from)]++
        dp[map.get(to)]--
    })
    
    for(let i=0;i<n-1;i++){
        for(let j=i+1;j<n;j++){
            if(board[i][j]>board[j][i]){
                answer[i]++
            }else if(board[i][j]<board[j][i]){
                answer[j]++
            }else{
                if(dp[i]>dp[j]){
                    answer[i]++
                }else if(dp[i]<dp[j]){
                    answer[j]++
                }
            }
        }
    }
    return Math.max(...answer);
}