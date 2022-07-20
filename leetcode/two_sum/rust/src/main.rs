use std::collections::HashMap;


fn main() {
    println!("{:?}", two_sum(vec![2, 7, 11, 15], 9));
}


fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
    let mut seen: HashMap<i32, i32> = HashMap::new();
    for (indx, num) in nums.iter().enumerate() {
        if let Some(prev_indx) = seen.get(&(target - num)) {
            return vec![*prev_indx, indx as i32];
        }
        seen.insert(*num, indx as i32);
    }
    Vec::<i32>::new()
}


#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_one_option() {
        assert_eq!(two_sum(vec![2, 7, 11, 15], 9), vec![0, 1]);
    }

    #[test]
    fn test_empty() {
        assert_eq!(two_sum(Vec::<i32>::new(), 2), Vec::<i32>::new())
    }

    #[test]
    fn test_no_solution() {
        assert_eq!(two_sum(vec![1, 2, 3], 12), Vec::<i32>::new());
    }
}
