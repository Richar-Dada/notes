var maxSubArray = function (nums) {
    const dp = new Array(nums.length).fill(Number.MIN_SAFE_INTEGER)

    dp[0] = nums[0]
    let sum = nums[0]
    for (let i = 1; i < nums.length; i++) {
        let temp1 = dp[i - 1] + nums[i]
        let temp2 = nums[i]
        dp[i] = Math.max(temp1, temp2)
        sum = Math.max(sum, dp[i])
    }
    return sum
}

console.log(maxSubArray([-2, 1, -3, 4, -1, 2, 1, -5, 4]))