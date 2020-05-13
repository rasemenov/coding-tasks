#include <stdio.h>
#include "solution.h"


void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int indx, jdx, back_indx;
    indx = m - 1;
    jdx = n - 1;
    back_indx = m + n - 1;
    nums1Size--;
    nums2Size--;
    while (jdx >= 0) {
#ifndef TEST
        printf("nums1[]=%d nums2[]=%d bi=%d i=%d j=%d\n",
                nums1[indx], nums2[jdx], back_indx, indx, jdx);
#endif
        if (nums2[jdx] > nums1[indx] || back_indx <= m - 1) {
            nums1[back_indx] = nums2[jdx--];
        } else {
            nums1[back_indx] = nums1[indx--];
        }
        if (back_indx) {
            back_indx--;
        }
    }
}


#ifndef TEST
int main(void) {
    int nums1[] = {10, 0};
    int nums2[] = {1};
    merge(nums1, 2, 1, nums2, 1, 1);
    for (size_t i = 0; i < ARRAY_SIZE(nums1); i++) {
        printf("%d ", nums1[i]);
    }
    puts("");
    return 0;
}
#endif
