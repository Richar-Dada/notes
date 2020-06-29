// var climbStairs = function (n) {
//     const dp = [1, 1]
//     for (let i = 2; i <= n; i++) {
//         dp[i] = dp[i - 1] + dp[i - 2]
//     }
//     return dp[n]
// }

var climbStairs = function (n) {
    let dp1 = 1
    let dp2 = 1

    while (--n) {
        const temp = dp1 + dp2
        dp1 = dp2
        dp2 = temp
    }
    return dp2
}

console.log(climbStairs(2))
console.log(climbStairs(3))
console.log(climbStairs(4))
console.log(climbStairs(10))