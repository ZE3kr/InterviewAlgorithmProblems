class Solution:
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        a, b = 1, 1
        for _ in range(n):
            a, b = a + b, a
        return b


a = Solution()
for i in range(10):
    print(i, Solution.climbStairs(a, i))
