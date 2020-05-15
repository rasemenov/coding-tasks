int removeElement(int* nums, int numsSize, int val){
    int indx, next_indx;
    if (!numsSize) {
        return 0;
    }
    for (indx = 0; indx < numsSize; indx++) {
        if (nums[indx] == val) {
            break;
        }
    }
    if (indx == numsSize) {
        return numsSize;
    }
    next_indx = indx + 1;
    while (next_indx < numsSize) {
        if (nums[next_indx] != val) {
            nums[indx++] = nums[next_indx++];
        } else {
            next_indx++;
        }
    }
    return numsSize - (next_indx - indx);
}
