class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        arr_len = len(nums)
        if not arr_len:
            return 0
        for next_indx, item in enumerate(nums):
            if item == val:
                break
        indx = next_indx
        next_indx += 1
        if nums[indx] != val:
            return arr_len
        while next_indx < arr_len:
            if nums[next_indx] != val:
                nums[indx] = nums[next_indx]
                indx += 1
                next_indx += 1
            else:
                next_indx += 1
        return arr_len - (next_indx - indx)
