function add() {
    var _arg = Array.prototype.slice.call(arguments)

    var _adder = function () {
        _arg.push(...arguments)
        return _adder
    }

    _adder.toString = function () {
        return _arg.reduce(function (a, b) {
            return a + b
        })
    }

    return _adder
}

console.log(+add(1)(2)(3))
console.log(+add(1, 2, 3)(4))
console.log(add(1)(2)(3)(4)(5))
console.log(add(2, 6)(1))