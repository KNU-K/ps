function solution(files) {
    return files.sort((a, b) => {
        const parseFile = (file) => {
            const match = file.match(/^([a-zA-Z\-\. ]+)([0-9]+)(.*)$/);
            return [match[1], match[2], match[3]];
        };

        const [headA, numberA] = parseFile(a).map((v, i) => i === 0 ? v.toLowerCase() : parseInt(v));
        const [headB, numberB] = parseFile(b).map((v, i) => i === 0 ? v.toLowerCase() : parseInt(v));

        if (headA < headB) return -1;
        if (headA > headB) return 1;
        if (numberA < numberB) return -1;
        if (numberA > numberB) return 1;
        return 0;
    });
}
