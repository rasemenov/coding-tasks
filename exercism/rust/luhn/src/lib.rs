#[cfg(any(iter))]
pub fn is_valid(code: &str) -> bool {
    let mut nprocessed: u8 = 0;
    let mut ndigits: u8 = 0;
    let sum: u32 = code.chars()
        .rev()
        .filter(|item| !item.is_whitespace())
        .map(|c| {
            nprocessed += 1;
            c.to_digit(10)
        })
        .take_while(Option::is_some)
        .map(|number| {
            ndigits += 1;
            number.unwrap()
        })
        .collect::<Vec<u32>>()
        .chunks(2)
        .map(|chunk| {
            let mut first: u32 = *chunk.get(1).unwrap_or(&0);
            let second: u32 = *chunk.get(0).unwrap();
            first = first * 2;
            if first > 9 {
                first -= 9;
            }
            first + second
        })
        .sum();
    ndigits > 1
        && nprocessed == ndigits
        && sum % 10 == 0
}


#[cfg(not(iter))]
pub fn is_valid(code: &str) -> bool {
    let mut sum = 0;
    let mut ndigits = 0;
    let iter = code.chars().rev().filter(|item| !item.is_whitespace());
    for (indx, item) in iter.enumerate() {
        if let Some(mut number) = item.to_digit(10) {
            ndigits += 1;
            if indx % 2 != 0 {
                number *= 2;
                if number > 9 {
                    number -= 9;
                }
            }
            sum += number;
        } else {
            return false;
        }
    }
    ndigits > 1 && sum % 10 == 0
}
