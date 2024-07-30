function solution(numbers) {
    var answer = 0;
    var array = new Array(0,0,0,0,0,0,0,0,0,0);
    numbers.forEach((number, _)=>{
        array[number] = 1;
    })
    array.forEach((e,index)=>{
        if(e === 0 ){
            answer += index;
        }
    })
    return answer;
}