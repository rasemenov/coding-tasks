#[derive(Debug)]
pub enum CalculatorInput {
    Add,
    Subtract,
    Multiply,
    Divide,
    Value(i32),
}

use CalculatorInput::{Add, Subtract, Multiply, Divide, Value};

pub fn evaluate(inputs: &[CalculatorInput]) -> Option<i32> {
    let mut stack: Vec<i32> = vec![];
    for operand in inputs {
        if let Value(num) = operand {
            stack.push(*num);
            continue;
        }
        let (second, first) = match (stack.pop(), stack.pop()) {
            (Some(second), Some(first)) => (second, first),
            _ => return None,
        };
        let value = match operand {
            Add => first + second,
            Subtract => first - second,
            Multiply => first * second,
            Divide => {
                if second < 0 {
                    return None;
                }
                first / second
            },
            _ => {panic!("Variable changed it value!");}
        };
        stack.push(value);
    }
    if stack.len() > 1 {
        None
    } else {
    stack.pop()
    }
}
