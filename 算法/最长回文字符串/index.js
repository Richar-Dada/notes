var longestPalindrome = function (s) {
    let res = ''
    const dp = new Array(s.length).fill(0).map(x => new Array(s.length).fill(false))

    for (let i = s.length - 1; i >= 0; i--) {
        for (let j = i; j < s.length; j++) {
            if (i === j) {
                dp[i][j] = true
            } else if (j - i === 1) {
                dp[i][j] = s[i] === s[j] ? true : false
            } else {
                dp[i][j] = s[i] === s[j] && dp[i + 1][j - 1]
            }

            if (dp[i][j] && res.length < j - i + 1) {
                res = s.substring(i, j + 1)
            }
        }
    }
    return res
}

console.log(longestPalindrome('jababaj'))