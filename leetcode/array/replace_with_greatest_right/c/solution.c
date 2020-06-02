int* replaceElements(int* arr, int arrSize, int* returnSize){
    int largest, tmp;
    *returnSize = arrSize;
    if (arrSize > 1) {
        largest = arr[arrSize - 1];
        if (arrSize == 2) {
            arr[arrSize - 1] = -1;
            return arr;
        }
    } else if (arrSize == 1) {
        arr[arrSize - 1] = -1;
        return arr;
    } else {
        return arr;
    }
    for (int indx = arrSize - 1; indx >= 0; indx--) {
        if (arr[indx] > largest) {
            tmp = largest;
            largest = arr[indx];
            arr[indx] = tmp;
        } else {
            arr[indx] = largest;
        }
    }
    arr[arrSize - 1] = -1;
    return arr;
}
