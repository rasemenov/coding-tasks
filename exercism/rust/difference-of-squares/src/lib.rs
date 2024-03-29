pub fn square_of_sum(n: u32) -> u32 {
    (1..=n).sum::<u32>().pow(2)
}

#[cfg(not(fold))]
pub fn sum_of_squares(n: u32) -> u32 {
    (1..=n).map(|num| num.pow(2)).sum()
}

#[cfg(any(fold))]
pub fn sum_of_squares(n: u32) -> u32 {
    (1..=n).fold(0, |accum, current| accum + current.pow(2))
}

pub fn difference(n: u32) -> u32 {
    square_of_sum(n) - sum_of_squares(n)
}
