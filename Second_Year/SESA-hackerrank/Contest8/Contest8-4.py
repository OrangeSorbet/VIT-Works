# A permutation of an array is a specific arrangement of its members. We want to find the "next" version of this arrangement in a dictionary-like (lexicographical) order.

# Given an array of integers nums, rearrange it into the lexicographically next greater permutation of numbers.

# Rules: If the array is already the largest possible arrangement (i.e., sorted in descending order), rearrange it as the lowest possible order (i.e., sorted in ascending order).

# The replacement must be done in-place (modify the existing array) and use only constant extra memory.

# Input Format

# The first line contains an integer N, the length of the array. The second line contains N space-separated integers.

# Constraints

# Constraints: 1 ≤ N ≤ 100 0 ≤ nums[i] ≤ 100

# Output Format

# Print N space-separated integers representing the modified array.

# Sample Input 0

# 3
# 1 2 3
# Sample Output 0

# 1 3 2
# Sample Input 1

# 3
# 3 2 1
# Sample Output 1

# 1 2 3
# Sample Input 2

# 3
# 1 1 5
# Sample Output 2

# 1 5 1

# ================= CODE AREA START =================
def next_permutation(nums: list[int]) -> None:
    n = len(nums)
    i = n - 2
    while i >= 0 and nums[i] >= nums[i + 1]:
        i -= 1
    if i >= 0:
        j = n - 1
        while nums[j] <= nums[i]:
            j -= 1
        nums[i], nums[j] = nums[j], nums[i]
    left, right = i + 1, n - 1
    while left < right:
        nums[left], nums[right] = nums[right], nums[left]
        left += 1
        right -= 1
# ================= CODE AREA END ===================

if __name__ == '__main__':
    import sys
    data = sys.stdin.read().split()
    if not data: sys.exit()
    n = int(data[0])
    nums = [int(x) for x in data[1:n+1]]
    
    next_permutation(nums)
    print(*(nums))