use time::{Duration, PrimitiveDateTime as DateTime};

pub fn after(start: DateTime) -> DateTime {
    start + Duration::seconds(10_i64.pow(9))
}
