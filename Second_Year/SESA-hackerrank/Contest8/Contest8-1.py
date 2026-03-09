# You are working in a warehouse management system. You are given an array of integers capacities, where capacities[i] represents the volume of the i-th storage box. You are also given an integer itemSize representing the volume of a specific item you need to store.

# A box can store the item only if its capacity is greater than or equal to the itemSize (capacities[i] >= itemSize).

# Your goal is to find the minimum capacity among all boxes that can successfully store the item. Once you find that minimum capacity, return the index of that box.

# Important Rules: If multiple boxes have the same minimum capacity that can fit the item, return the smallest index. If no box in the warehouse is large enough to store the item, return -1.

# Input Format

# The first line contains two space-separated integers: N (the number of boxes) and itemSize (the size of the item). The second line contains N space-separated integers representing the capacities array.

# Constraints

# Constraints: 1 ≤ N ≤ 1000 1 ≤ capacities[i] ≤ 1000 1 ≤ itemSize ≤ 1000

# Output Format

# Print a single integer representing the index of the optimal box, or -1 if no such box exists.

# Sample Input 0

# 4 3
# 1 5 3 7
# Sample Output 0

# 2
# Sample Input 1

# 4 2
# 3 5 4 3
# Sample Output 1

# 0

# ================= CODE AREA START =================
def minimum_index(capacity: list[int], item_size: int) -> int:
    # Write your code here
    # Return the index of the box with minimum capacity that fits item_size
    # If multiple exist, return the smallest index. Return -1 if none fit.
    min_capacity = float('inf')
    min_index = -1
    for i in range(len(capacity)):
        if capacity[i] >= item_size:
            if capacity[i] < min_capacity:
                min_capacity = capacity[i]
                min_index = i
    return min_index
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
    item_size = int(input_data[1])
    capacity = [int(x) for x in input_data[2:n+2]]
    
    result = minimum_index(capacity, item_size)
    print(result)