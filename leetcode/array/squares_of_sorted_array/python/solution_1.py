class Solution:
    def sortedSquares(self, A: List[int]) -> List[int]:
        res = []
        minus_indx = -1
        for indx in range(len(A)):
            if A[indx] < 0:
                minus_indx = indx
                continue
            while minus_indx >= 0:
                if -A[minus_indx] <= A[indx]:
                    res.append(A[minus_indx] * A[minus_indx])
                    minus_indx -= 1
                else:
                    break
            res.append(A[indx] * A[indx])
        else:
            while minus_indx >= 0:
                res.append(A[minus_indx] * A[minus_indx])
                minus_indx -= 1
        return res
