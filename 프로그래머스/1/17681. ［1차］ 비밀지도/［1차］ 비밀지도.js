const makeBinaryMap = (n, size)=>{
    let str = ""
    while(1){
        
        str += (n % 2)===1?"#":" ";
        if(n === 1) break;
    
        n = parseInt(n/2);
    }
    let newMapElements = str.split("").reverse().join("")
    console.log(newMapElements.length!== size)
    if(newMapElements.length !== size){
        const blankCnt =  size - newMapElements.length;
        console.log(blankCnt);
        for(let i=0;i<blankCnt;i++){
            newMapElements = " "+ newMapElements; 
        }
    }
    return newMapElements;
}
function solution(n, arr1, arr2) {
    var answer = [];
    const newArray = new Array(n).fill(0);
    arr1.forEach((e, idx)=>newArray[idx]=makeBinaryMap(e | arr2[idx],n))
    return newArray;
}