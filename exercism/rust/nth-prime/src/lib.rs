#[cfg(brute)]
fn is_prime(num: u32) -> bool {
    let mut ndivisors = 0;
    let end = num / 4;
    for div in (1..end).step_by(4) {
        if num % div == 0 {
            ndivisors += 1;
        }
        if num % (div + 1) == 0 {
            ndivisors += 1;
        }
        if num % (div + 2) == 0 {
            ndivisors += 1;
        }
        if num % (div + 3) == 0 {
            ndivisors += 1;
        }
        if ndivisors > 1 {
            return false;
        }
    }
    true
}

/// Brute force algorithm.
#[cfg(brute)]
pub fn find_prime(n: u32) -> u32 {
    if n == 0 {
        return 2;
    }
    let mut num = 3;
    let mut nprimes = 0;
    loop {
        if is_prime(num) {
            nprimes += 1;
            if nprimes == n {
                return num;
            }
        }
        num += 2;
    }
}

/// Eratosthenes algorithm.
#[cfg(eratosthenes)]
pub fn find_prime(n: u32) -> u32 {
    const START: u32 = 2;
    const STOP: u32 = 1_000_000;
    let set = START..STOP;
    let mut indx_array = vec![true; (STOP - START + 2) as usize];
    let mut nprimes = 0;
    for num in set {
        // That was proven to be not a prime.
        if ! indx_array[num as usize] {
            continue;
        }
        nprimes += 1;
        if nprimes == n + 1 {
            return num;
        }
        let mut mult = (num + num) as usize;
        // All multiples of a prime are not primes, mark them as such.
        while mult < STOP as usize {
            if indx_array[mult] {
                indx_array[mult] = false;
            }
            mult += num as usize;
        }
    }
    0
}

pub fn nth(n: u32) -> u32 {
    find_prime(n)
}
