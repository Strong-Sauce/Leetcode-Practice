/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */
var promiseAll = function(functions) {
    return new Promise((resolve, reject) => {
        const results = new Array(functions.length);
        let resolved = 0;

        functions.forEach((fn, i) => {
            fn()
                .then(val => {
                    results[i] = val;
                    if (++resolved === functions.length) resolve(results);
                })
                .catch(reject); // first rejection wins
        });
    });
};


/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */