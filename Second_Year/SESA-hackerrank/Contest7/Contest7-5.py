# You are given a single positive integer N. You want to break this integer down into N separate units of 1.

# In one operation, you can take any integer X (where X > 1) and split it into two positive integers A and B such that A + B = X.

# The cost of this specific operation is calculated as: Cost = A × B

# You must continue performing these operations until all resulting pieces are equal to 1.

# Your task is to calculate and return the minimum total cost required to complete this process.

# Input Format

# A single line containing an integer N.

# Constraints

# Constraints: 1 ≤ N ≤ 500 (Note: While the logic works for larger values, we will stick to the provided constraints.)

# Output Format

# Print a single integer representing the minimum total cost to split N into N ones.

# Sample Input 0

# 3
# Sample Output 0

# 3
# Sample Input 1

# 4
# Sample Output 1

# 6
# Sample Input 2

# 1
# Sample Output 2

# 0

# ================= CODE AREA START =================
def min_cost(n: int) -> int:
    # Write your code here
    # Calculate the minimum total cost to split n into ones
    if n == 1:
        return 0
    total_cost = 0

    def split(x):
        nonlocal total_cost
        if x == 1:
            return

        a = x // 2
        b = x - a
        total_cost += a * b
        split(a)
        split(b)
    split(n)
    return total_cost
# ================= CODE AREA END ===================


# ===================================================
# DO NOT MODIFY THE MAIN FUNCTION BELOW
# ===================================================
if __name__ == '__main__':
    import sys
    line = sys.stdin.readline()
    if not line:
        sys.exit()
        
    n = int(line.strip())
    
    result = min_cost(n)
    print(result)