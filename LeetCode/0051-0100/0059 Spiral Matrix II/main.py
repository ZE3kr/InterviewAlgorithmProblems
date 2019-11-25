class Solution:
    def generateMatrix(self, n):
        matrix = [[0 for i in range(n)] for j in range(n)]
        visited = [[False for i in range(n)] for j in range(n)]
        x, y, t = 0, 0, 0
        move = 0
        for t in range(n * n):
            matrix[x][y] = t + 1
            visited[x][y] = True
            # print(x, y, move)
            # print(visited)
            if move == 0:
                if y >= n - 1 or visited[x][y + 1]:
                    move = 1
                    x += 1
                else:
                    y += 1
            elif move == 1:
                if x >= n - 1 or visited[x + 1][y]:
                    move = 2
                    y -= 1
                else:
                    x += 1
            elif move == 2:
                if y <= 0 or visited[x][y - 1]:
                    move = 3
                    x -= 1
                else:
                    y -= 1
            else:
                if x <= 0 or visited[x - 1][y]:
                    move = 0
                    y += 1
                else:
                    x -= 1
        return matrix


a = Solution()
print(Solution.generateMatrix(a, 3))
