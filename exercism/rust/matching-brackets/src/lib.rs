pub fn brackets_are_balanced(string: &str) -> bool {
    let mut open_braces = vec![];
    for letter in string.chars() {
        match letter {
            '{' | '[' | '(' => open_braces.push(letter),
            '}' => if open_braces.pop() != Some('{') { return false },
            ']' => if open_braces.pop() != Some('[') { return false },
            ')' => if open_braces.pop() != Some('(') { return false },
            _ => continue,
        }
    }
    open_braces.len() == 0
}
