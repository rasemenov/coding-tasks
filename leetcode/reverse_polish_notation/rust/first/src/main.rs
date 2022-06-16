fn main() {
    assert!(eval_rpn(vec!["2", "2", "+"]) == 5);
}


pub fn eval_rpn(tokens: Vec<&str>) -> i32 {
    let mut stack: Vec<i32> = vec![];
    for operand in tokens {
        if let Ok(num) = operand.parse() {
            stack.push(num);
            continue;
        }
        let (second, first) = match (stack.pop(), stack.pop()) {
            (Some(second), Some(first)) => (second, first),
            _ => return 0,
        };
        let value = match operand {
            "+" => first + second,
            "-" => first - second,
            "*" => first * second,
            "/" => {
                if second == 0 {
                    return 0;
                }
                first / second
            },
            _ => {panic!("Variable changed it value!");}
        };
        stack.push(value);
    }
    if stack.len() > 1 {
        0
    } else {
        stack.pop().unwrap_or(0)
    }
}
