// This stub file contains items that aren't used yet; feel free to remove this module attribute
// to enable stricter warnings.
#![allow(unused)]

const PRODUCTION_RATE: u8 = 221;
const MINUTE_PER_HOUR: u8 = 60;

pub fn production_rate_per_hour(speed: u8) -> f64 {
    let raw_production: f64 = PRODUCTION_RATE as f64 * speed as f64;
    match speed {
        1..=4 => raw_production * 1.0,
        5..=8 => raw_production * 0.9,
        9..=10 => raw_production * 0.77,
        _ => 0.0,
    }
}

pub fn working_items_per_minute(speed: u8) -> u32 {
    (production_rate_per_hour(speed) / MINUTE_PER_HOUR as f64) as u32
}
