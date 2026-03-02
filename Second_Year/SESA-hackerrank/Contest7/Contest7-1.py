# You are given a non-empty array of integers. In this array, every element appears exactly twice, except for one specific element which appears only once.

# Your task is to find and return that single unique element.

# Constraint for Students: To pass all test cases, your solution must have a linear runtime complexity O(n) and use only constant extra space O(1).

# Input Format

# The first line contains an integer N, the number of elements in the array. The second line contains N space-separated integers.

# Constraints

# Constraints: 1 ≤ N ≤ 3 × 10^4 -3 × 10^4 ≤ nums[i] ≤ 3 × 10^4 N will always be an odd number (due to the problem logic).

# Output Format

# Print a single integer representing the element that appears only once.

# Sample Input 0

# 3
# 2 2 1
# Sample Output 0

# 1
# Sample Input 1

# 5
# 4 1 2 1 2
# Sample Output 1

# 4
# Sample Input 2

# 1
# 1
# Sample Output 2

# 1

# ================= CODE AREA START =================
def single_number(nums: list[int]) -> int:
    # Write your code here
    result = 0
    for num in nums:
        result ^= num
    return result
# ================= CODE AREA END ===================

if __name__ == '__main__':
    import sys
    data = sys.stdin.read().split()
    if not data: sys.exit()
    n = int(data[0])
    nums = [int(x) for x in data[1:n+1]]
    print(single_number(nums))