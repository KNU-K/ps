const encode3Number = (n)=>{
    let str = ""
    
    while(1){
        const d = n % 3
        str += d.toString();
    
        if(n < 3) break; 
        n = parseInt(n/3);
    }
    return str.split('')
              .reverse()
              .join('')
}
const decode3Number = (n)=>{
    let digit = 1;
    let result = 0;
   // return n;
    for(let i=n.length-1;i!=-1;i--, digit*=3){
        
        if(parseInt(n[i]) !=0){
            result += digit * parseInt(n[i]);
            //console.log( [result, digit, parseInt(n[i])])
        }
    }
    return result;
    
}
function solution(n) {
    return decode3Number(
        encode3Number(n)
        .split('')
        .reverse()
        .join('')
    );
}