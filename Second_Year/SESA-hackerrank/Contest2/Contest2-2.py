# You are given an integer array nums and an integer k.

# Return the kth largest element in the array. The kth largest element refers to the element that would appear in position k if the array were sorted in descending order.

# Note that the kth largest element is not the kth distinct element.

# Input Format

# The first line contains an integer n, the number of elements in the array. The second line contains n space-separated integers. The third line contains an integer k.

# Constraints

# 1 ≤ k ≤ n ≤ 10^5

# -10^4 ≤ nums[i] ≤ 10^4

# Output Format

# Print a single integer representing the kth largest element in the array.

# Sample Input 0

# 6
# 3 2 1 5 6 4
# 2
# Sample Output 0

# 5
# Sample Input 1

# 9
# 3 2 3 1 2 4 5 5 6
# 4
# Sample Output 1

# 4

n=int(input())
a=list(map(int,input().split()))
k=int(input())
a.sort(reverse=True)
print(a[k-1])