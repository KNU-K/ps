function solution(d, budget) {
    var answer = 0;
    d.sort((a,b) => a-b)
     .forEach((value, index)=>{
        if((budget - value) < 0) return;
        budget -= value;
        answer ++;
    })
    return answer;
}