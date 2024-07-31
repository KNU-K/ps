function solution(s) {
    var answer = new Array();
    const parsedData = s.split("},{")
                        .map((e)=>e
                             .replaceAll("{","")
                             .replaceAll("}","")
                             .split(","))
                        .sort((a,b)=>a.length - b.length)
                        .map((e)=>{
                            e.forEach((ee1)=>{
                            let flag = false;
                            for(ee of answer){
                                if(parseInt(ee1) === parseInt(ee)){
                                    flag = true;
                                    break;
                                }
                            }
                            if(!flag)
                                answer.push(parseInt(ee1))
                                })
                        })
            
    return answer
}