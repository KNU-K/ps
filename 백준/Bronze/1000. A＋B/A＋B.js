const fs = require("fs")

const readline = fs.readFileSync('dev/stdin').toString().split(" ")

console.log(Number(readline[0]) + Number(readline[1]))