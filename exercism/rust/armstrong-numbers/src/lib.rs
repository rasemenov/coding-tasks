#[cfg(not(char))]
pub fn is_armstrong_number(num: u32) -> bool {
    let mut accum = Vec::new();
    let mut tmp = num;
    while tmp != 0 {
        let digit = tmp % 10;
        tmp /= 10;
        accum.push(digit);
    }
    accum.iter().fold(0, |acc, num| acc + num.pow(accum.len() as u32)) == num
}


#[cfg(any(char))]
pub fn is_armstrong_number(num: u32) -> bool {
    let num_str = num.to_string();
    let res = 0;
    for digit in num_str.chars() {
        res += digit.to_digit(10).unwrap().pow(num_str.len());
    }
    res == num
}
