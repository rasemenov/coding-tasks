pub fn is_leap_year_condition(year: u64) -> bool {
    let is_4_years = year % 4 == 0;
    let is_hundred = year % 100 == 0;
    let is_4hundred = year % 400 == 0;
    if is_4_years && (!is_hundred || is_4hundred) {
        return true;
    }
    false
}

pub fn is_leap_year_condition_reduced_stack(year: u64) -> bool {
    year % 4 == 0 && (!(year % 100 == 0) || year % 400 == 0)
}

pub fn is_leap_year(year: u64) -> bool {
    match (year % 400, year % 100, year % 4) {
        (0, _, _) => true,
        (_, 0, _) => false,
        (_, _, 0) => true,
        _ => false,
    }
}
