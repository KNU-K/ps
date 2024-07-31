function getPairs(str) {
    let pairs = [];
    str = str.toUpperCase();
    for (let i = 0; i < str.length - 1; i++) {
        let pair = str.slice(i, i + 2);
        if (/^[A-Z]{2}$/.test(pair)) {
            pairs.push(pair);
        }
    }
    return pairs;
}

function getIntersectionAndUnion(arr1, arr2) {
    let map1 = arr1.reduce((acc, val) => {
        acc[val] = (acc[val] || 0) + 1;
        return acc;
    }, {});
    
    let map2 = arr2.reduce((acc, val) => {
        acc[val] = (acc[val] || 0) + 1;
        return acc;
    }, {});
    
    let intersection = 0;
    let union = 0;
    let allKeys = new Set([...Object.keys(map1), ...Object.keys(map2)]);
    
    allKeys.forEach(key => {
        let count1 = map1[key] || 0;
        let count2 = map2[key] || 0;
        intersection += Math.min(count1, count2);
        union += Math.max(count1, count2);
    });
    
    return { intersection, union };
}

function solution(str1, str2) {
    let pairs1 = getPairs(str1);
    let pairs2 = getPairs(str2);
    
    let { intersection, union } = getIntersectionAndUnion(pairs1, pairs2);
    
    if (union === 0) {
        return 65536;
    }
    
    let jaccardSimilarity = intersection / union;
    return Math.floor(jaccardSimilarity * 65536);
}
