struct Solution;


impl Solution {
    pub fn plus_one(digits: Vec<i32>) -> Vec<i32> {
        let mut incremented = digits;
        for digit in incremented.iter_mut().rev() {
            *digit = (*digit + 1) % 10;
            if *digit != 0 {
                return incremented;
            }
        }
        incremented.insert(0, 1);
        incremented
    }
}


fn main() {
    assert_eq!(Solution::plus_one(vec![1, 2, 3]), vec![1, 2, 4]);
}
