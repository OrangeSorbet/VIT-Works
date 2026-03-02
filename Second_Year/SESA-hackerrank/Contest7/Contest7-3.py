# You are given an array of non-negative integers representing the heights of a series of vertical barriers. These barriers are placed at equal intervals along a flat horizontal line. Your task is to select exactly two barriers to act as the walls of a water container. The width of the container is the horizontal distance between the two chosen barriers, and the height of the container is determined by the shorter of the two barriers (because water will spill over the shorter wall). Calculate and return the maximum volume (area) of water that such a container can hold. Note that you cannot slant the container.

# Input Format

# The input consists of two lines: The first line contains an integer N, representing the total number of vertical barriers. The second line contains N space-separated integers, where the i-th integer represents the height of the i-th barrier.

# Constraints

# Constraints: 2 ≤ N ≤ 10^5 0 ≤ height[i] ≤ 10^4

# Output Format

# Print a single integer representing the maximum area of water the container can store.

# Sample Input 0

# 9
# 1 8 6 2 5 4 8 3 7
# Sample Output 0

# 49
# Sample Input 1

# 2
# 1 1
# Sample Output 1

# 1
# Sample Input 2

# 5
# 4 3 2 1 4
# Sample Output 2

# 16

# ================= CODE AREA START =================
def max_area(height: list[int]) -> int:
    # Write your code here
    # Return the maximum amount of water a container can store
    left, right = 0, len(height) - 1
    max_area = 0
    while left < right:
        width = right - left
        current_area = min(height[left], height[right]) * width
        max_area = max(max_area, current_area)
        
        if height[left] < height[right]:
            left += 1
        else:
            right -= 1
    return max_area
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
    height = [int(x) for x in input_data[1:n+1]]
    
    result = max_area(height)
    print(result)