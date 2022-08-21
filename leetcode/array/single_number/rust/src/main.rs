use std::collections::HashSet;


fn single_number(nums: Vec<i32>) -> i32 {
    let mut seen = HashSet::with_capacity(nums.len() / 2);
    for num in &nums {
        if !seen.insert(*num) {
            seen.remove(num);
        }
    }
    *seen.iter().next().unwrap()
}


fn single_number_2(nums: Vec<i32>) -> i32 {
    let mut res = nums[0];
    for num in nums.iter().skip(1) {
        res ^= num;
    }
    res
}

fn main() {
    println!("{}", single_number(vec![1, 0, 1]));
    println!("{}", single_number_2(vec![1, 0, 1]));
}
