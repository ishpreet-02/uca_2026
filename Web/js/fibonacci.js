function* fibonacci(){
    let a = 0;
    let b = 1;
    while(true){
        yield a;
        let temp = a + b;
        a = b;
        b = temp;
    }

}

const fib = fibonacci();
console.log(fib.next().value);
console.log(fib.next().value);
console.log(fib.next().value);
console.log(fib.next().value);
console.log(fib.next().value);
console.log(fib.next().value);
console.log(fib.next().value);