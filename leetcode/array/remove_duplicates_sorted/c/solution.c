int removeDuplicates(int *nums, int numsSize){
    int start = -1, indx;
    if (numsSize <= 1) {
        return numsSize;
    }
    for (indx = 1; indx < numsSize; indx++) {
        if (nums[indx] == nums[indx-1]) {
            if (start == -1) {
                start = indx;
            }
        } else {
            if (start != -1) {
                nums[start++] = nums[indx];
            }
        }
    }
    return (start == -1) ? numsSize : start;
}
