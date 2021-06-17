from collections import defaultdict

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        pairs = defaultdict(list)
        for indx, num in enumerate(nums):
            diff = target - num
            opts = pairs.get(diff, None)
            if opts is None:
                pairs[num] = [indx]
                continue
            return [opts[0], indx]
