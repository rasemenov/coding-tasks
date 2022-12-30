use std::fmt::Display;

pub struct Luhn(String);

impl Luhn {
    pub fn is_valid(&self) -> bool {
        let mut sum = 0;
        let mut ndigits = 0;
        let iter = self.0.chars().rev().filter(|item| !item.is_whitespace());
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

/// Here is the example of how the From trait could be implemented
/// for the &str type. Naturally, you can implement this trait
/// by hand for the every other type presented in the test suite,
/// but your solution will fail if a new type is presented.
/// Perhaps there exists a better solution for this problem?
impl<T> From<T> for Luhn
    where T: ToString + Display
{
    fn from(input: T) -> Self {
        Self(input.to_string())
    }
}
