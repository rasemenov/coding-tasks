void rotate(int* nums, int numsSize, int k) {
    k %= numsSize;
    if (numsSize < 2 || k == 0) {
        return;
    }
    int *tmp_array = malloc(numsSize * sizeof(int));
    if (!tmp_array) {
        return;
    }
    memcpy(tmp_array, nums + numsSize - k, k * sizeof(int));
    memcpy(tmp_array + k, nums, (numsSize - k) * sizeof(int));
    memcpy(nums, tmp_array, numsSize * sizeof(int));
    free(tmp_array);
}
