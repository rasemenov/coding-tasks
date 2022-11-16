const MAX_GRAINS: u32 = 64;

pub fn square(s: u32) -> u64 {
    if s < 1 || s > MAX_GRAINS {
        panic!("Square must be between 1 and 64")
    }
    2_u64.pow(s - 1)
}

pub fn total() -> u64 {
    (1..=MAX_GRAINS).map(square).sum()
}
