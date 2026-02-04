# Given a binary array nums, return the maximum number of consecutive 1's in the array. A binary array is an array consisting only of 0s and 1s. You need to find the longest contiguous streak of 1s.

# Example: Input: nums = [1, 1, 0, 1, 1, 1] Output: 3

# Explanation: The first two digits are consecutive 1's. The last three digits are consecutive 1's. The maximum number of consecutive 1's is 3.

# Input Format

# The first line contains an integer N, the size of the array. The second line contains N space-separated integers (either 0 or 1).

# Constraints

# Constraints: 1 ≤ N ≤ 10^5 nums[i] is either 0 or 1.

# Edge Case Behavior: • If the array contains no 1s, the output should be 0. • If the array contains only 1s, the output should be N.

# Output Format

# Print a single integer representing the maximum number of consecutive 1's.

# Sample Input 0

# 6
# 1 1 0 1 1 1
# Sample Output 0

# 3
# Sample Input 1

# 6
# 1 0 1 1 0 1
# Sample Output 1

# 2

import sys

#
# Complete the 'findMaxConsecutiveOnes' function below.
#
# The function is expected to return an INTEGER.
# The function accepts INTEGER_LIST nums as parameter.
#

# ================= CODE AREA START =================
def findMaxConsecutiveOnes(nums):
    # Write your code here
    max_count = 0
    current_count = 0
    for num in nums:
        if num == 1:
            current_count += 1
            max_count = max(max_count, current_count)
        else:
            current_count = 0
    return max_count
# ================= CODE AREA END =================

# DO NOT MODIFY THE CODE BELOW
if __name__ == '__main__':
    input_data = sys.stdin.read().split()
    if not input_data:
        sys.exit(0)
    
    n = int(input_data[0])
    nums = [int(x) for x in input_data[1:n+1]]
    
    result = findMaxConsecutiveOnes(nums)
    print(result)