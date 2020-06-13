// var uniquePaths = function (m, n) {
//     const dp = new Array(m).fill(0).map(x => new Array(n).fill(0))

//     for (let i = 0; i < n; i++) dp[0][i] = 1
//     for (let i = 1; i < m; i++) {
//         for (let j = 0; j < n; j++) {
//             if (j === 0) dp[i][j] = 1
//             else dp[i][j] = dp[i][j - 1] + dp[i - 1][j]
//         }
//     }
//     return dp[m - 1][n - 1]
// }

var uniquePaths = function (m, n) {
    const dp = new Array(n).fill(1)
    for (let i = 1; i < m; i++) {
        let pre = 0
        for (let j = 0; j < n; j++) {
            pre = dp[j] + pre
            dp[j] = pre
        }
    }

    return dp[n - 1]
}

console.log(uniquePaths(3, 3))