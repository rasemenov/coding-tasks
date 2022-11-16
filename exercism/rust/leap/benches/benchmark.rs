#![feature(test)]
extern crate leap;
extern crate test;

use test::Bencher;

const BENCH_SIZE: u64 = 3000;

#[bench]
fn bench_leap_condition(b: &mut Bencher) {
    b.iter(|| {
        (0..BENCH_SIZE).map(leap::is_leap_year_condition).collect::<Vec<_>>()
    });
}

#[bench]
fn bench_leap_condition_reduced_stack(b: &mut Bencher) {
    b.iter(|| {
        (0..BENCH_SIZE).map(
            leap::is_leap_year_condition_reduced_stack).collect::<Vec<_>>()
    });
}

#[bench]
fn bench_leap_pattern(b: &mut Bencher) {
    b.iter(|| {
        (0..BENCH_SIZE).map(leap::is_leap_year).collect::<Vec<_>>()
    });
}
