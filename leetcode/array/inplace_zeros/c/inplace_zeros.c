void moveZeroes(int* nums, int numsSize){
    int read_indx = 0, nzeros = 0, write_indx = -1;
    for (; read_indx < numsSize; read_indx++) {
        int current_num = nums[read_indx];
        if (!current_num) {
            nzeros++;
            if (write_indx == -1) {
                write_indx = read_indx;
            }
        } else {
            if (write_indx != -1) {
                nums[write_indx] = current_num;
                write_indx++;
            }
        }
    }
    if (write_indx != -1) {
        while (nzeros--) {
            nums[write_indx + nzeros] = 0;
        }
    }
}
