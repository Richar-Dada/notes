function PromiseAll(promises) {
    return new Promise((resolve, reject) => {
        if (!Array.isArray(promises)) {
            reject('argrement must a array')
        }

        let promisesNum = promises.length
        let resolveArr = new Array(promisesNum)
        let promisesCount = 0

        for (let i = 0; i < promisesNum; i++) {
            Promise.resolve(promises[i])
                .then((value) => {
                    promisesCount++
                    resolveArr.push(value)
                    if (promisesCount === promisesNum) {
                        resolve(resolveArr)
                    }
                }, (reason) => {
                    reject(reason)
                })
        }
    })
}