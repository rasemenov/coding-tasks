void duplicateZeros(int *arr, int arrSize){
    int indx, back_indx, to_double = 1, nextra = 0;
    for (indx = 0; indx < arrSize; indx++) {
        if (!arr[indx]) {
            /* Add second zero if there is space for it.*/
            if (indx + nextra < arrSize - 1) {
                nextra++;
            } else {
                /* Note that we do not need to double the first zero.*/
                to_double = 0;
            }
        }
        if (indx + nextra == arrSize - 1) {
            break;
        }
    }
    back_indx = arrSize - nextra - 1;
    for (indx = arrSize - 1; indx >= 0 && back_indx >= 0; indx--, back_indx--) {
        arr[indx] = arr[back_indx];
        if (!arr[back_indx]) {
            /* Copy extra zero if there is space for it. */
            if (indx > 0 && to_double) {
                arr[--indx] = arr[back_indx];
            } else {
                /* The only zero without duplicate is passed, every other 0 should be copied.*/
                to_double = 1;
            }
        }
    }
}
