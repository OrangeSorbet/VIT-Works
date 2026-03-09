# You are given an array of N integers. Your goal is to find how many "valid splits" exist in the array.

# A split at index i is considered valid if: The sum of the first i + 1 elements is greater than or equal to the sum of the remaining N − i − 1 elements.

# Both resulting sections must be non-empty. This means you can split the array at any index i from 0 to N − 2.

# Return the total number of valid splits.

# Input Format

# The first line contains an integer N, representing the length of the array. The second line contains N space-separated integers representing the array elements.

# Constraints

# Constraints: 2 ≤ N ≤ 10^5 -10^5 ≤ nums[i] ≤ 10^5

# Output Format

# Print a single integer representing the number of valid splits.

# Sample Input 0

# 4
# 10 4 -8 7
# Sample Output 0

# 2
# Sample Input 1

# 5
# 2 3 1 0 0
# Sample Output 1

# 3

# ================= CODE AREA START =================
def ways_to_split_array(nums: list[int]) -> int:
    # Write your code here
    # Python handles large integers automatically
    # Return the number of valid splits
    total_sum = sum(nums)
    left_sum = 0
    valid_splits = 0
    for i in range(len(nums) - 1):
        left_sum += nums[i]
        right_sum = total_sum - left_sum
        if left_sum >= right_sum:
            valid_splits += 1
    return valid_splits
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
    nums = [int(x) for x in input_data[1:n+1]]
    
    result = ways_to_split_array(nums)
    print(result)