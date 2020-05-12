/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *sortedSquares(int *A, int ASize, int *returnSize){
    int indx, minus_indx = -1, res_indx = 0, *res;
    res = malloc(sizeof(int) * ASize);
    *returnSize = ASize;
    if (!res) {
        return NULL;
    }
    for (indx = 0; indx < ASize; indx++) {
        if (A[indx] < 0) {
            minus_indx = indx;
            continue;
        }
        while (minus_indx >= 0) {
            if (-A[minus_indx] <= A[indx]) {
                res[res_indx++] = A[minus_indx] * A[minus_indx];
                minus_indx--;
            } else {
                break;
            }
        }
        res[res_indx++] = A[indx] * A[indx];
    }
    while (minus_indx >= 0) {
        res[res_indx++] = A[minus_indx] * A[minus_indx];
        minus_indx--;
    }
    return res;
}
