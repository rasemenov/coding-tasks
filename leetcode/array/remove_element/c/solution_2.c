#include <stdio.h>


int removeElement(int *nums, int size, int val) {
    int *start, *end, left_shift, len = 0;
    start = nums;
    end = &nums[size-1];
    while ((start - nums < size) && (end - nums > 0)) {
        if (*start == val) {
            if (*end != val) {
                len++;
                *start++ = *end--;
            } else {
                end--;
            }
        } else {
            len++;
            start++;
            end--;
        }
    }
    return len;
}


int main(void) {
#define ARRAY_SIZE(x) sizeof(x)/sizeof(x[0])
	int arr[] = {3, 2, 2, 3};
    int n = 0;
    n = removeElement(arr, ARRAY_SIZE(arr), 3);
    for (int i = 0; i < n; i++) {
        printf("%s%d%s", (i == 0) ? "[" : "", arr[i],
               (i == n - 1 ) ? "]\n" : ", ");
    }
    return 0;
}
