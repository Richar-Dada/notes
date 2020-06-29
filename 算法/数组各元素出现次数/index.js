function countTime(data) {
    var obj = {}
    return data.reduce(function (time, name) {
        if (name in time) {
            time[name]++
        } else {
            time[name] = 1
        }
        return time
    }, {})
}
console.log(countTime([1, 1, 2, 3]))