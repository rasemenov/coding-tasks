pub trait Luhn: ToString {
    fn valid_luhn(&self) -> bool {
        let code = self.to_string();
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
}

/// Here is the example of how to implement custom Luhn trait
/// for the &str type. Naturally, you can implement this trait
/// by hand for the every other type presented in the test suite,
/// but your solution will fail if a new type is presented.
/// Perhaps there exists a better solution for this problem?
impl<T: ToString> Luhn for T {}
