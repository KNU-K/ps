function solution(a, b) {
    var answer = 0;
    a.forEach((e, index)=>{
        answer += e * b[index];
    })
    return answer;
}