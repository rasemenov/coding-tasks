bool validMountainArray(int *A, int ASize){
    if (!A || ASize < 3) {
        return false;
    }
    int indx = 0;
    if (A[indx] > A[indx + 1] || A[ASize - 2] < A[ASize - 1]) {
        return false;
    }
    while (indx < ASize - 1 && A[indx] < A[indx + 1]) {
        indx++;
    }
    while (indx < ASize - 1 && A[indx] > A[indx + 1]) {
        indx++;
    }
    return (indx == ASize - 1) ? true : false;
}
