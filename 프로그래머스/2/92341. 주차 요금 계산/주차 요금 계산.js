function solution(fees, records) {
    records = records
        .map(record => record.split(' '))
        .sort((a, b) => a[1] - b[1])
    
         let result = {};
    records.forEach((record,idx)=>{
         if(!result[record[1]]) result[record[1]] =0
         if(record[2] === 'IN'){
             if(idx+1 != records.length&&records[idx+1][2] === 'OUT'){
                  const [inHour, inMin] = record[0].split(':')    
                  const [outHour, outMin] = records[idx+1][0].split(':')  
                  const [newH, newM] = [outHour - inHour, outMin-inMin];
                  result[record[1]] += (newH*60+newM)
                    
             }else{
                    const [hour, min] = record[0].split(':')    
                    const [newH, newM] = [23- hour, 59-min];
                    result[record[1]] += (newH*60 + newM);
            }
         }
     })
    const rtn= [];
    Object.keys(result).map(e=>{
            if(result[e] <= fees[0]){
               rtn.push([e,fees[1]]);
            }else{
                rtn.push([e,Math.ceil((result[e]-fees[0]) / fees[2])*fees[3]+ fees[1]])
            }
        }
    )
        
    rtn.sort((a,b)=>a[0]-b[0])
    return rtn.map(e=>e[1]);
}