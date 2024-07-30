function solution(s) {
    
    const dict = {"zero":0
                  ,"one":1
                  ,"two":2
                  ,"three":3
                  ,"four":4
                  ,"five":5
                  ,"six":6
                  ,"seven":7
                  ,"eight":8
                  ,"nine":9}
    var answer = "";
    var temp = ""
    for(e of s){
            if(isNaN(e)) {
                temp += e;
                if(dict[temp]!=undefined){
                    answer += dict[temp].toString();
                    temp ="";
                }
                continue;
            }
            if(!(0<=parseInt(e)&&9>=parseInt(e))) continue;
            answer += e;
    }
    
    return parseInt(answer);
}