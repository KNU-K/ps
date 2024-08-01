const dict={0:"0",1:"1",2:"2",3:"3",4:"4",5:"5",6:"6",7:"7",8:"8",9:"9"
            ,10:"A",11:"B",12:"C", 13:"D", 14:"E", 15:"F"}
const convertDecimaltoNBitNum = (num, solution)=>{
    if(num === 0) return num.toString();
    if(solution === 10) return num.toString();
    let str = ""
    while(1){
        
        if(num === 0) break;
        str += dict[num%solution]
    
        num = parseInt(num/solution);
    }
    return str.split('').reverse().join('')
}
function solution(n, t, m, p) {
    /** 10진수 이상은 그냥 놔두기 **/
    /**
        n: 진법
        t: 미리 구할 숫자의 갯수
        m: 게임에 참가하는 인원
        p: 튜브의 순서 (내 순서)
    **/
    /**
    me : 0 2 4 6 8 A C E 1
    no : 1 3 5 7 9 B D F 0 1 2 3 4 5 6
    **/
    var answer = '';
    let cnt = 1;
    let cnt2 = 1;
    let me = 0;
    for(let i =0;;i++){
        const decimalNumber = i
        const temp = convertDecimaltoNBitNum(decimalNumber,n);
        
        if(i === 0){
            
            if(cnt2 === p){
                answer = temp + answer;
            }else if(cnt2 === m){
                cnt2 = 0;
            }
            cnt2++;
            
            // console.log(cnt)
            cnt++;
            continue;
        }
        for(let j=0; j<temp.length; j++){
            // console.log(cnt2, p)
            // console.log(temp)
               // break;
            if(cnt >t * m) break;
            if(cnt2 === p){
                answer += temp[j]
            }
            if(cnt2 === m){
                cnt2 = 0;
            }
            cnt2++;
            
            cnt++;
        }
        if(cnt >t * m) break;
            
    }
    return answer;
}