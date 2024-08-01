const dict = {}; // Initialize as an object

const init = () => {
    let x = 1;
    for (let i = 'A'.charCodeAt(0); i <= 'Z'.charCodeAt(0); i++) {
        dict[String.fromCharCode(i)] = x++; 
    }
};
let cnt = 27;
let str = "";
function solution(msg) {
    const result = new Array();
    init();
    const msgArray = msg.split("");
    for(let i=0;i<msg.length;i++){
        if(str.length===0){
            str+=msgArray[i]
        }else{
            str+=msgArray[i] 
            if(!Object.keys(dict).includes(str)){
                dict[str] = cnt++
                
                result.push(dict[str.slice(0,str.length-1)]);
                str = "";
                i--;
            }
        }
    }
    if(str.length) result.push(dict[str])
    return result; 
}