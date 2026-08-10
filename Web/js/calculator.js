function* calculator(start){
    let result=start;

    while(true){

        const input=yield result;
        if(!input || !["add","sub","mul","div"].includes(input.operation)){
            result="Invalid input";
            continue;

        }

        const value=Number(input.value);

        if (input.value === "" || !Number.isFinite(value)) {
            result = "Invalid input";
            continue;
        }

        switch(input.operation){
            case "add":
                result+=value;
                break;
            case "sub":
                result-=value;
                break;
            case "mul":
                result*=value;
                break;
            case "divide":
                if(value==0){
                    result="Cannot divide by zero";
                    continue;

                }

                result/=value;
                break;
        }

    }
}

const calc = calculator(50);
console.log(calc.next()); // 50

console.log(calc.next({ operation: "add", value: 30 }));
console.log(calc.next({ operation: "mul", value: 2 }));
console.log(calc.next({ operation: "sub", value: 20 }));