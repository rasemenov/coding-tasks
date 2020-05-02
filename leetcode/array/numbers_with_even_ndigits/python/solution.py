from math import log10, floor


class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        even_ndigits = 0
        for item in nums:
            if floor(log10(item)) % 2:
                even_ndigits += 1
        return even_ndigits
