const scoreList = {"S":1,"D":2,"T":3}
function solution(dartResult) {
    const result = []
    dartResult
        .split("")
        .forEach((e,idx)=>{
            if(e === "*"){
                const size = result.length
                console.log(result)
                for(let i=size-1;;i--){
                    
                    if(i <= size-3) break;
                    console.log(result[i])
                    result[i] *=2;
                }
            }else if(e === "#"){
                result[result.length-1] *= -1;
            }else if(isNaN(e)){
                const list = []
                for(let i=idx-1; i>=0;i--){
                    if(!isNaN(dartResult[i])) list.push(dartResult[i])
                    else break;
                }
                result.push(Math.pow(parseInt(list.reverse().join('')),scoreList[e]))
            }
        })
    console.log(result)
    return result.reduce((a,b)=>a+b)

}