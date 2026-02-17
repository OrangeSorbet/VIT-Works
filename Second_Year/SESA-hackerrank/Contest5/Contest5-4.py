# You are given an array of positive integers nums.

# A Fibonacci subarray is a contiguous sequence where, for every index i ≥ 2 in that subarray, the element satisfies the condition:

# subarray[i] = subarray[i - 1] + subarray[i - 2]

# Return the length of the longest Fibonacci subarray found in nums.

# Note: By definition, any subarray of length 1 or 2 is considered a Fibonacci subarray. Since the input size N ≥ 3, the minimum possible answer is always 2.

# Example 1: Input: nums = [1, 1, 1, 1, 2, 3, 5, 1] Output: 5 Explanation: The longest Fibonacci subarray is [1, 1, 2, 3, 5] (indices 2 to 6).

# Example 2: Input: nums = [5, 2, 7, 9, 16] Output: 5 Explanation: 5 + 2 = 7 2 + 7 = 9 7 + 9 = 16 The entire array is Fibonacci.

# Input Format

# The first line contains an integer N, the size of the array. The second line contains N space-separated integers.

# Constraints

# Constraints: 3 ≤ N ≤ 10^5 1 ≤ nums[i] ≤ 10^9

# Edge-case Rules: If no three consecutive elements satisfy the Fibonacci condition, the result is 2. Large values (10^9) may sum up to 2 × 10^9; ensure your addition logic handles this properly (use long long in C++ to avoid overflow).

# Output Format

# A single integer representing the maximum length of a Fibonacci contiguous subarray.

# Sample Input 0

# 8
# 1 1 1 1 2 3 5 1
# Sample Output 0

# 5
# Sample Input 1

# 5
# 5 2 7 9 16
# Sample Output 1

# 5
# Sample Input 2

# 3
# 1000000000 1000000000 1000000000
# Sample Output 2

# 2

import sys

# ================= CODE AREA START =================
def longestFibonacciSubarray(nums):
    # Write your code here
    if len(nums) < 3:
        return len(nums)
    max_length = 2
    current_length = 2
    for i in range(2, len(nums)):
        if nums[i] == nums[i - 1] + nums[i - 2]:
            current_length += 1
        else:
            max_length = max(max_length, current_length)
            current_length = 2
    max_length = max(max_length, current_length)
    return max_length
# ================= CODE AREA END =================

# DO NOT MODIFY THE CODE BELOW
if __name__ == '__main__':
    data = sys.stdin.read().split()
    if not data: sys.exit(0)
    n = int(data[0])
    nums = [int(x) for x in data[1:]]
    print(longestFibonacciSubarray(nums))