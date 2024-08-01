function solution(N, stages) {
    var answer = new Array(N).fill(0);  
    var answer2 = new Array(N).fill(0);
    /**
        N = 스테이지 수
        stages.length = 사용자의 수
        str[i] = 사용자가 위치한 스테이지
    **/
    stages
        .sort((a,b)=> a-b)
        .forEach((e, idx)=>{
            for(i = 1; i< e; i++){
                if(i === N+1) break;
                answer[i-1] ++;
            }
            for(i = 1; i< e+1; i++){
                if(i === N+1) break;
                answer2[i-1] ++;
            }
        })
    const result = []; // 빈 배열로 초기화

    answer.forEach((e, idx) => {
        if (answer2[idx] === 0) {
            result.push({ [idx + 1]: 0 });
        } else {
            // 계산된 값을 저장할 변수 이름을 resultValue로 변경
            const resultValue = (answer2[idx] - e) / parseInt(answer2[idx]);
            result.push({ [idx + 1]: resultValue });
        }
    });
    result.sort((a, b) => {
        const keyA = Object.keys(a)[0];
        const keyB = Object.keys(b)[0];

        const valueA = a[keyA];
        const valueB = b[keyB];

        return valueB - valueA;
    });
    return result.map(e=>parseInt(Object.keys(e)[0]))
}