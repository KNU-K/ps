const dict = {
    0:1,
    1:2,
    2:3,
    3:4,
    4:5,
    5:6,
    6:6
}
function solution(lottos, win_nums) {
    let countOfZero = 0
    lottos.sort((a,b)=>a-b).forEach((e)=>{
        if(e === 0) countOfZero ++
    })
    win_nums.sort((a,b)=>a-b)
    
    lottos.forEach((e,idx)=>{
        win_nums= win_nums.filter(s=>s!==e)  
    })
    return [dict[win_nums.length-countOfZero], dict[win_nums.length]];
}