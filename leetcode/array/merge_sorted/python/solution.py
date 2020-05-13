class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        indx = m - 1
        back_indx = len(nums1) - 1
        for item in nums2[::-1]:
            while item <= nums1[indx] and indx >= 0:
                nums1[back_indx] = nums1[indx]
                indx -= 1
                back_indx -= 1
            else:
                nums1[back_indx] = item
                back_indx -= 1
