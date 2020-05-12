class Solution:
    def duplicateZeros(self, arr: List[int]) -> None:
        arr_len = len(arr)
        backindx = nextra = 0
        to_double = True
        for indx, item in enumerate(arr):
            if not item:
                if indx + nextra < arr_len - 1:
                    nextra += 1
                else:
                    to_double = False
            if indx + nextra == arr_len - 1:
                break
        backindx = arr_len - nextra - 1
        indx = arr_len - 1
        while backindx >= 0:
            arr[indx] = arr[backindx]
            if not arr[indx]:
                if indx > 0 and to_double:
                    indx -= 1
                    arr[indx] = 0
                else:
                    to_double = True
            backindx -= 1
            indx -= 1
