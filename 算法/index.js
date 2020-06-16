// var n = 1
// function foo() {
//     n = 100
//     console.log(n)
// }
// console.log(n)
// foo()

// var n = 1;
// (function foo() {
//     n = 100;
//     console.log(n);
// }())
// console.log(n)

var animal = {
    type: 'Default',
    color: 'Default',
    getInfo: function () {
        return `Type is: ${this.type}, color is ${this.color}`
    }
}

var dog = {
    type: 'Dog',
    color: 'Black'
}

dog.__proto__ = animal

console.log(dog.getInfo())
