const toUpperString = str => str.toUpperCase();

const solution = (cacheSize, cities) => {
    if (cacheSize === 0) return cities.length * 5;

    let cache = [];
    let answer = 0;

    cities.forEach(city => {
        let cityUpper = toUpperString(city);
        let index = cache.indexOf(cityUpper);

        if (index !== -1) {
            // Cache hit
            answer += 1;
            cache.splice(index, 1);
        } else {
            // Cache miss
            answer += 5;
            if (cache.length === cacheSize) cache.shift();
        }
        cache.push(cityUpper);
    });

    return answer;
};
