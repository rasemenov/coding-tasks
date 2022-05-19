#[derive(Debug, PartialEq)]
pub enum Comparison {
    Equal,
    Sublist,
    Superlist,
    Unequal,
}

pub fn sublist<T: PartialEq>(first_list: &[T], second_list: &[T]) -> Comparison {
    if first_list == second_list {
        return Comparison::Equal
    }
    let first_len = first_list.len();
    let second_len = second_list.len();
    if first_len < second_len {
        if is_sublist(second_list, first_list) {
            return Comparison::Sublist;
        }
    } else {
       if is_sublist(first_list, second_list) {
           return Comparison::Superlist;
       }
    }
    Comparison::Unequal
}

fn is_sublist<T: PartialEq>(longest: &[T], shortest: &[T]) -> bool {
    for indx in 0..=(longest.len() - shortest.len()) {
        if &longest[indx..(indx + shortest.len())] == shortest {
            return true;
        }
    }
    false
}
