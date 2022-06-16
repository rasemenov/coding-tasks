// This stub file contains items that aren't used yet; feel free to remove this module attribute
// to enable stricter warnings.
#![allow(unused)]

use std::collections::HashMap;

pub fn can_construct_note(magazine: &[&str], note: &[&str]) -> bool {
    let mut map = HashMap::new();
    for &word in magazine.iter() {
        let counter = map.entry(word).or_insert(0);
        *counter += 1;
    }
    for &word in note.iter() {
        map.entry(word).and_modify(|e| *e -= 1);
        match map.get(word) {
            Some(num) => {
                if num < &0 {
                    return false;
                }
            },
            None => return false,
        }
    }
    true
}
