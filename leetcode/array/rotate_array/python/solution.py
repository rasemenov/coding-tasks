class Solution:
    @staticmethod
    def gcd(first, second):
        if first == 0 or second == 0:
            return 0
        while first > 0:
            if second > first:
                first, second = second, first
            first %= second
        return second

    def rotate_1(self, nums: List[int], k: int) -> None:
        """
        From geekforgeeks with different rotation direction.
        """
        num_len = len(nums)
        k %= num_len
        if num_len < 2:
            return
        gcd = self.gcd(num_len, k)
        for i in range(gcd):
            temp = nums[i]
            j = i
            while 1:
                m = j - k
                if m < 0:
                    m = num_len + m
                if m == i:
                    break
                nums[j] = nums[m]
                j = m
            nums[j] = temp

    def rotate(self, nums: List[int], k: int) -> None:
        num_len = len(nums)
        k %= num_len
        gcd = self.gcd(num_len, k)
        if num_len < 2 or gcd == 0:
            return
        steps = num_len // gcd
        dst = 0
        for step in range(gcd):
            tmp = nums[num_len - k + step]
            for _ in range(steps):
                nums[dst], tmp = tmp, nums[dst]
                dst = (dst + k) % num_len
            dst += 1
