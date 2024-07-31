function solution(n, words) {
    var answer = [];
    const array = new Array(n+1);
    for(let i=1;i<=n;i++){
        array[i] = new Array();
    }
    let curPlayerNum = 1;
    let preWord = "";
    let step = 1;
    for(let x=0;x<words.length;x++){
        if(curPlayerNum > n){
            curPlayerNum %= n;
            step ++;
        }
        // console.log(x, preWord, words[x])
        if(x !==0 && preWord[preWord.length-1] !== words[x][0])
             // return "a"
            return [curPlayerNum,step]
        for(let i=1;i<=n;i++){
            const temp = array[i];
            
            // console.log(step, temp, e);
            for(let j=0;j<temp.length; j++){
                
               // console.log(temp[j],words[x])
                if(temp[j] === words[x]){
                    
            return [curPlayerNum,step]
                }
            }
        }
        array[curPlayerNum].push(words[x]); 
        preWord = words[x];
        curPlayerNum++;
        
        // console.log(step);
    }
    return [0,0] 
}