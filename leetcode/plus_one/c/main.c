#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int* plusOne(int* digits, int digitsSize, int* returnSize){
    size_t array_size = digitsSize * sizeof(digits[0]);
    int *incremented = malloc(array_size);
    memcpy(incremented, digits, array_size);
    for (int indx = digitsSize - 1; indx >= 0; indx--) {
        incremented[indx] = (incremented[indx] + 1) % 10;
        if (incremented[indx] != 0) {
            *returnSize = digitsSize;
            return incremented;
        }
    }
    int *larger = malloc(array_size + sizeof(digits[0]));
    int *larger_head = larger;
    *larger = 1;
    larger++;
    memcpy(larger, incremented, array_size);
    *returnSize = digitsSize + 1;
    free(incremented);
    return larger_head;
}


void print_array(int *array, int len) {
    printf("[");
    for (int indx = 0; indx < len; indx++) {
        printf("%d", array[indx]);
        if (indx == len - 1) {
            printf("]\n");
        } else {
            printf(", ");
        }
    }
}


int main(void) {
    int array[] = {9, 9};
    int len = 2;
    int result_len;
    int *res = plusOne(array, len, &result_len);
    print_array(array, len);
    print_array(res, result_len);
    free(res);
}
