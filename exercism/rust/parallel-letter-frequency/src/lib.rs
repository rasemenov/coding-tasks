use std::collections::HashMap;
use std::thread;

pub fn calc_frequency(input: &Vec<String>) -> HashMap<char, usize> {
    let mut map = HashMap::new();
    let iter = input
        .iter()
        .flat_map(|line| line.chars())
        .filter(|ch| ch.is_alphabetic());
    for letter in iter {
        for ch in letter.to_lowercase() {
            map.entry(ch).and_modify(|cnt| *cnt += 1).or_insert(1);
        }
    }
    map
}

pub fn frequency(input: &[&str], worker_count: usize) -> HashMap<char, usize> {
    let mut res: HashMap<char, usize> = HashMap::new();
    let mut handles = Vec::with_capacity(worker_count);
    for chunk in input.chunks(input.len() / worker_count + 1) {
        let mut lines = Vec::with_capacity(chunk.len());
        for line in chunk {
            lines.push(line.to_string());
        }
        handles.push(thread::spawn(move || calc_frequency(&lines)));
    }
    for handle in handles {
        let words_count = handle.join().unwrap();
        for (key, val) in words_count {
            *res.entry(key).or_insert(0) += val;
        }
    }
    res
}
