int findMaxConsecutiveOnes(int* nums, int numsSize){
    int i, ones_cnt, max_ones_cnt;
    ones_cnt = max_ones_cnt = 0;
    for (i = 0; i < numsSize; i++) {
        ones_cnt++;
        if (!nums[i]) {
            ones_cnt = 0;
        }
        if (ones_cnt > max_ones_cnt) {
            max_ones_cnt = ones_cnt;
        }
    }
    return max_ones_cnt;
}
