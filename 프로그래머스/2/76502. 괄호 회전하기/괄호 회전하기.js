const isPerfectBracketStructure=(str)=>{
    const newArray = str.split('')
    const stack = new Array();
    
    for(let i=0;i<str.length;i++){
        // console.log(str[i]);
        if(str[i] === "[" || 
           str[i] === "(" ||
           str[i] === "{")
            stack.push(str[i]);
        else if(str[i] === "]" || 
           str[i] === ")" ||
           str[i] === "}"){
            const top = stack[stack.length-1]
            if(str[i] === "]" && 
               top === "[")
                stack.pop();
            else if(str[i] === ")" && 
                    top === "(")
                stack.pop();
            else if(str[i] === "}" &&
                    top === "{")
                stack.pop();
            else
                return false;
        }else{
            continue;
        }
        
    }
    if(stack.length !==0) return false;
    return true;
}
const shiftStrByLeft=(str)=>{
    const newArray = str.split('')
    newArray.push(str[0])
    newArray.shift()
    return newArray.join('')
}
function solution(s) {
    let result = 0;
    for(let i=0;i<s.length;i++){
        
        if(isPerfectBracketStructure(s))result++
        s=shiftStrByLeft(s)
    }
    return result;
}