class Solution:
    def sortedSquares(self, A: List[int]) -> List[int]:
        negatives = []
        indx = 0
        while indx < len(A):
            item = A[indx]
            squared = item * item
            if item < 0:
                del A[indx]
                negatives.append(squared)
                indx -= 1
            else:
                while len(negatives):
                    if negatives[-1] <= squared:
                        A.insert(indx, negatives.pop())
                        indx += 1
                    else:
                        break
                A[indx] = squared
            indx += 1
        A.extend(reversed(negatives))
        return A
