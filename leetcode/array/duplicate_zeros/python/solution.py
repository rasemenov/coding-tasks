class Solution:
    def duplicateZeros(self, arr: List[int]) -> None:
        interim_arr = []
        for indx, item in enumerate(arr):
            if not item:
                interim_arr.append(item)
            if len(interim_arr) > 0:
                interim_arr.append(item)
                arr[indx] = interim_arr.pop(0)
