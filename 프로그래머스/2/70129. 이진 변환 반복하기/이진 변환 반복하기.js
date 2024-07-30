const getCntOfNumberOne = (str)=>{
    let cnt =0;
    let zeroCnt =0;
    for(let i=0;i<str.length;i++){
        const ch = str[i]; 
        if(ch === '1'){
            cnt ++;
        }else if(ch === '0'){
            zeroCnt ++;
        }
    }
    return [cnt,zeroCnt];
}
const makeStringTypeOfBinaryNumber = (num)=>{
    let str = "";
    
    while(1){
        
        const dividedNumber  = num % 2
        str += dividedNumber.toString();
        
        if(num === 1) break;
        num = parseInt(num/2);
    }
    return str.split('').reverse().join('');
}
function solution(s) {
    var answer = [];
    let stepCnt = 0;
    let totalOfZeroCnt = 0;
    while(1){
        if(s === "1")break
        stepCnt ++;
        const [cnt,zeroCnt] = getCntOfNumberOne(s);
        totalOfZeroCnt += zeroCnt;
        s = makeStringTypeOfBinaryNumber(cnt);
    }
    return [stepCnt,totalOfZeroCnt];
}