class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        length = len(arr)
        if length > 1:
            largest = arr[-1]
        elif length == 1:
            arr[0] = -1
            return arr
        else:
            return arr
        for indx in range(length - 1, -1, -1):
            if arr[indx] > largest:
                largest, arr[indx] = arr[indx], largest
            else:
                arr[indx] = largest
        arr[-1] = -1
        return arr
