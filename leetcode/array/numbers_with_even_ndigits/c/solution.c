#include <math.h>

int findNumbers(int *nums, int nums_size){
    int i, num_power, even_ndigits = 0;
    for (i = 0; i < nums_size; i++) {
        num_power = (int)log10f((float)nums[i]);
        if (num_power % 2) {
            even_ndigits++;
        }
    }
    return even_ndigits;
}
