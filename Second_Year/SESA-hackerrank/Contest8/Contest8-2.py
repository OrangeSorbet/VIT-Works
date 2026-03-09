# You are given an array of 2n integers. This array is conceptually divided into two equal parts:

# The first n elements: [x1, x2, …, xn]
# The next n elements: [y1, y2, …, yn]

# Your task is to shuffle and rearrange the array so that the elements are interleaved in the following specific order:

# [x1, y1, x2, y2, …, xn, yn]

# Return the resulting shuffled array.

# Input Format

# The first line contains an integer n. (The total number of elements in the array will be 2 × n). The second line contains 2n space-separated integers.

# Constraints

# Constraints: 1 ≤ n ≤ 1000 1 ≤ nums[i] ≤ 10^4 The length of the array is exactly 2n.

# Output Format

# Print 2n space-separated integers representing the interleaved array.

# Sample Input 0

# 3
# 2 5 1 3 4 7
# Sample Output 0

# 2 3 5 4 1 7
# Sample Input 1

# 4
# 1 2 3 4 4 3 2 1
# Sample Output 1

# 1 4 2 3 3 2 4 1

# ================= CODE AREA START =================
def interleave(nums: list[int], n: int) -> list[int]:
    # Write your code here
    # Return the interleaved list [x1, y1, x2, y2, ...]
    result = []
    for i in range(n):
        result.append(nums[i])
        result.append(nums[i + n])
    return result
# ================= CODE AREA END ===================


# ===================================================
# DO NOT MODIFY THE MAIN FUNCTION BELOW
# ===================================================
if __name__ == '__main__':
    import sys
    input_data = sys.stdin.read().split()
    
    if not input_data:
        sys.exit()
        
    n = int(input_data[0])
    nums = [int(x) for x in input_data[1:]]
    
    result = interleave(nums, n)
    print(*(result))