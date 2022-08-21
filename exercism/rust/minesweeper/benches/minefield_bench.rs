use minesweeper::annotate;
use criterion::{criterion_group, criterion_main, Criterion};

fn bench() {
    let _res = annotate(&[
        "  * ",
        "**  ",
        "   *",
        "*   ",
    ]);
}

fn criterion_benchmark(c: &mut Criterion) {
    c.bench_function("field_20", |b| b.iter(|| bench()));
}

criterion_group!(benches, criterion_benchmark);
criterion_main!(benches);
