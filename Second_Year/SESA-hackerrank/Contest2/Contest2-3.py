# Given an m x n integer matrix and an integer target, return true if target exists in matrix, otherwise return false.

# Input Format

# matrix: a list of m lists, each containing n integers, representing the 2D matrix.

# target: an integer to search for in the matrix.

# Constraints

# m == matrix.length

# n == matrix[i].length

# 1 <= m, n <= 100

# -10^4 <= matrix[i][j], target <= 10^4

# Each row is sorted in non-decreasing order.

# The first integer of each row is greater than the last integer of the previous row.

# Output Format

# Return true if target exists in the matrix, otherwise return false.

# Sample Input 0

# 3
# 4
# 1 3 5 7
# 10 11 16 20
# 23 30 34 60
# 3
# Sample Output 0

# true
# Sample Input 1

# 3
# 4
# 1 3 5 7
# 10 11 16 20
# 23 30 34 60
# 13
# Sample Output 1

# false

m=int(input())
n=int(input())
matrix=[]
for _ in range(m):
    row=list(map(int,input().split()))
    matrix.append(row)
target=int(input())
found=False
for i in range(m):
    for j in range(n):
        if matrix[i][j]==target:
            found=True
            break
    if found:
        break
if found:
    print("true")
else:
    print("false")