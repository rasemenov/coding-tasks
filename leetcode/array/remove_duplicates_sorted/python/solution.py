class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        indx = 1
        start = None
        arr_len = len(nums)
        while indx < arr_len:
            if nums[indx] == nums[indx-1]:
                if start is None:
                    start = indx
            else:
                if start is not None:
                    nums[start] = nums[indx]
                    start += 1
            indx += 1
        return start
