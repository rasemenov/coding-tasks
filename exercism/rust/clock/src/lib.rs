use std::fmt::{self, Display};

use time::{Time, Duration, format_description};


#[derive(Debug, Eq, PartialEq)]
pub struct Clock {
    time: Time,
}


impl Clock {
    pub fn new(hours: i32, minutes: i32) -> Self {
        let time = Time::MIDNIGHT;
        let offset = Duration::hours(hours as i64)
                     + Duration::minutes(minutes as i64);
        Self {
            time: time + offset
        }
    }

    pub fn add_minutes(&self, minutes: i32) -> Self {
        Self::new(self.time.hour() as i32, self.time.minute() as i32 + minutes)
    }
}


impl Display for Clock {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        let format = match format_description::parse("[hour]:[minute]") {
            Ok(format) => format,
            _ => return Err(std::fmt::Error),
        };
        match self.time.format(&format) {
            Ok(res) => write!(f, "{}", res),
            _ => Err(std::fmt::Error),
        }
    }
}
