class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        nzeros = 0
        write_indx = None
        for read_indx, current_num in enumerate(nums):
            if current_num == 0:
                nzeros += 1
                if write_indx is None:
                    write_indx = read_indx
            else:
                if write_indx is not None:
                    nums[write_indx] = current_num
                    write_indx += 1
        if write_indx is not None:
            for indx in range(write_indx, write_indx + nzeros):
                nums[indx] = 0
