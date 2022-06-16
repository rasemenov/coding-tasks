fn eval_rpn(tokens: Vec<&str>) -> i32 {
    let mut stack: Vec<i32> = vec![];
    for operand in tokens {
        let value = match operand {
            "+" => stack.pop().unwrap() + stack.pop().unwrap(),
            "-" => {
                let first = stack.pop().unwrap();
                let second = stack.pop().unwrap();
                second - first
            },
            "*" => stack.pop().unwrap() * stack.pop().unwrap(),
            "/" => {
                let first = stack.pop().unwrap();
                let second = stack.pop().unwrap();
                second  / first
            },
            _ => operand.parse().unwrap(),
        };
        stack.push(value);
    }
    stack.pop().unwrap()
}


fn main() {
    assert_eq!(eval_rpn(vec!["2", "2", "+"]), 4);
}
