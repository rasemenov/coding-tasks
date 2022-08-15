use std::collections::HashSet;

pub fn anagrams_for<'a>(word: &'a str, possible_anagrams: &[&'a str]) -> HashSet<&'a str> {
    let lword = word.to_lowercase();
    let mut word_vec = lword.chars().collect::<Vec<char>>();
    word_vec.sort();
    let mut res = HashSet::new();
    for option in possible_anagrams {
        let loption = option.to_lowercase();
        if lword != loption {
            let mut option_vec = loption.chars().collect::<Vec<char>>();
            option_vec.sort();
            if option_vec == word_vec {
                res.insert(*option);
            }
        }
    }
    res
}
