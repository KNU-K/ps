function solution(numbers) {
    var answer = [];
    const arr = new Array(300).fill(0);
    numbers.forEach((value1,idx1)=>{
        numbers.forEach((value2,idx2)=>{
            
            if(idx1 !== idx2&&!arr[value1 + value2]) {
                arr[value1 + value2] = 1;  
                answer.push(value1+value2);
            }
        })
    })
    return answer.sort((a,b)=>a-b);
}