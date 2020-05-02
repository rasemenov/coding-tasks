class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        ones_cnt = 0
        max_ones_cnt = 0
        for item in nums:
            ones_cnt += 1
            if not item:
                ones_cnt = 0
            if ones_cnt > max_ones_cnt:
                max_ones_cnt = ones_cnt
        return max_ones_cnt
