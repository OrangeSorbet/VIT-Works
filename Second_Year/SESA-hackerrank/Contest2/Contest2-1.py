# You are given a sorted array of distinct integers and an integer target.

# Your task is to return the index of the target if it exists in the array. If the target is not present, return the index where it would be inserted to keep the array sorted.

# Input Format

# The first line contains an integer n, the number of elements in the array. The second line contains n space-separated integers in ascending order. The third line contains an integer target.

# Constraints

# 1 ≤ n ≤ 10^4 -10^4 ≤ array[i] ≤ 10^4 The array is sorted in ascending order and contains distinct elements. -10^4 ≤ target ≤ 10^4

# Output Format

# Print a single integer representing the index of the target element or the position where it should be inserted.

# Sample Input 0

# 4
# 1 3 5 6
# 5
# Sample Output 0

# 2
# Sample Input 1

# 4
# 1 3 5 6
# 2
# Sample Output 1

# 1
# Sample Input 2

# 4
# 1 3 5 6
# 7
# Sample Output 2

# 4

n=int(input())
a=list(map(int,input().split()))
t=int(input())

i=0
while i<len(a):
    if a[i]>=t: break
    i+=1
print(i)