use std::collections::HashMap;

/// Count occurrences of words.
pub fn word_count(words: &str) -> HashMap<String, u32> {
    let mut map = HashMap::new();
    for part in words.split(&[' ', '\t', ',', '\n']) {
        let word = part
            .trim_start_matches(|ch: char| !ch.is_ascii_alphanumeric())
            .trim_end_matches(|ch: char| !ch.is_ascii_alphanumeric())
            .to_ascii_lowercase();
        if word.is_empty() {
            continue;
        }
        for (indx, ch) in word.chars().enumerate() {
            if !ch.is_ascii_alphanumeric()
                && (indx == 0 || indx == word.len() - 1 || ch != '\'') {
                    break;
            }
            if indx == word.len() - 1 {
                map.entry(word.to_string())
                    .and_modify(|cnt| *cnt += 1)
                    .or_insert(1);
            }
        }
    }
    map
}
