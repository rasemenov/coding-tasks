class Solution:
    def validMountainArray_1(self, A: List[int]) -> bool:
        arr_len = len(A)
        if arr_len < 3 or A[0] > A[1] or A[arr_len - 2] < A[arr_len - 1]:
            return False
        indx = 0
        while indx < arr_len - 1 and A[indx] < A[indx + 1]:
            indx += 1
        while indx < arr_len - 1 and A[indx] > A[indx + 1]:
            indx += 1
        return indx == arr_len - 1

    def validMountainArray(self, A: List[int]) -> bool:
        arr_len = len(A)
        if arr_len < 3:
            return False
        pairs = list(zip(A[:-1], A[1:]))
        raising = list(takewhile(lambda i: i[0] < i[1], pairs))
        if len(raising):
            indx = pairs.index(raising[-1])
        else:
            return False
        falling = list(takewhile(lambda i: i[0] > i[1], pairs[indx + 1:]))
        if not len(falling):
            return False
        return len(raising) + len(falling) + 1 == arr_len
