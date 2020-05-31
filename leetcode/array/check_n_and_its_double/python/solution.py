class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        index: Dict[int, int] = dict()
        for item in arr:
            if 2 * item in index:
                return True
            else:
                if not abs(item) % 2:
                    if item / 2 in index:
                        return True
            index[item] = item
        return False
