func validMountainArray(A []int) bool {
    arrLen := len(A)
    if arrLen < 3 || A[0] > A[1] || A[arrLen - 2] < A[arrLen - 1] {
        return false
    }
    indx := 0
    for indx < arrLen - 1 && A[indx] < A[indx + 1] {
        indx++
    }
    for indx < arrLen - 1 && A[indx] > A[indx + 1] {
        indx++
    }
    return indx == arrLen - 1
}
