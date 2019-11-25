class Solution:
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        digits.insert(0, 0)
        digits[-1] += 1
        for i in reversed(range(1, len(digits))):
            if digits[i] > 9:
                digits[i-1] += 1
                digits[i] -= 10
        if digits[0] == 0:
            return digits[1:]
        else:
            return digits


a = Solution()
print(Solution.plusOne(a, [1, 2, 3]))
print(Solution.plusOne(a, [9, 9, 9]))
