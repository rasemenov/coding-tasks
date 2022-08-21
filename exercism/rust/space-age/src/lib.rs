#[derive(Debug)]
pub struct Duration(u64);

impl From<u64> for Duration {
    fn from(seconds: u64) -> Self {
        Self(seconds)
    }
}

const EARTH_YEAR_SECONDS: u64 = 31_557_600;

pub trait Planet {
    fn years_during(d: &Duration) -> f64 {
        unimplemented!("Convert {:?} to Earth years", d);
    }
}

pub struct Mercury;
pub struct Venus;
pub struct Earth;
pub struct Mars;
pub struct Jupiter;
pub struct Saturn;
pub struct Uranus;
pub struct Neptune;

macro_rules! impl_planet_for {
    ($($t:ty, $x:expr)?) => {
        $(impl Planet for $t {
            fn years_during(d: &Duration) -> f64 {
                d.0 as f64 / EARTH_YEAR_SECONDS as f64 / $x
            }
        })?
    }
}

impl_planet_for!(Mercury, 0.2408467);
impl_planet_for!(Venus, 0.61519726);
impl_planet_for!(Earth, 1.0);
impl_planet_for!(Mars, 1.8808158);
impl_planet_for!(Jupiter, 11.862615);
impl_planet_for!(Saturn, 29.447498);
impl_planet_for!(Uranus, 84.016846);
impl_planet_for!(Neptune, 164.79132);
