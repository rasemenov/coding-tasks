int gcd(int first, int second) {
    if (first == 0 || second == 0) {
        return 0;
    }
    while (first > 0) {
        if (second > first) {
            int tmp = first;
            first = second;
            second = tmp;
        }
        first %= second;
    }
    return second;
}

void rotate(int* nums, int numsSize, int k) {
    k %= numsSize;
    int common_divisor = gcd(numsSize, k);
    if (numsSize < 2 || common_divisor == 0) {
        return;
    }
    int steps = numsSize / common_divisor;
    int dst = 0;
    for (int step = 0; step < common_divisor; step++) {
        int accum = nums[numsSize - k + step];
        for (int i = 0; i < steps; i++) {
            int tmp = nums[dst];
            nums[dst] = accum;
            accum = tmp;
            dst = (dst + k) % numsSize;
        }
        dst++;
    }
}
