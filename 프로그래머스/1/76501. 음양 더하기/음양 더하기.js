function solution(absolutes, signs) {
    var answer = 0;
    signs.forEach((sign,index)=>{
        if(sign){
            answer += absolutes[index];
        }else{
            answer -= absolutes[index];
        }
    })
    return answer;
}