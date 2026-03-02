# It is a sweltering summer day, and a group of friends is visiting an ice cream festival. The festival has N different ice cream bars available, each with a specific cost in coins.

# You are given an array costs of length N, where costs[i] is the price of the i-th ice cream bar. You are also given an initial number of coins. You want to buy as many ice cream bars as possible.

# You can buy the ice cream bars in any order. Your goal is to return the maximum number of ice cream bars you can collect without exceeding your total coins.

# Efficiency Note: To handle the largest test cases within the time limit, consider using an efficient sorting approach like Counting Sort or a highly optimized standard sort.

# Input Format

# The input consists of two lines: Two space-separated integers: N (number of ice cream bars) and coins (total coins available). N space-separated integers representing the costs array.

# Constraints

# Constraints: 1 ≤ N ≤ 10^5 1 ≤ costs[i] ≤ 10^5 1 ≤ coins ≤ 10^8

# Output Format

# Print a single integer representing the maximum number of ice cream bars you can buy.

# Sample Input 0

# 5 7
# 1 3 2 4 1
# Sample Output 0

# 4
# Sample Input 1

# 6 5
# 10 6 8 7 7 8
# Sample Output 1

# 0
# Sample Input 2

# 6 20
# 1 6 3 1 2 5
# Sample Output 2

# 6

# ================= CODE AREA START =================
def max_ice_cream_bars(costs: list[int], coins: int) -> int:
    # Write your code here
    # Use an efficient sorting algorithm to handle N=10^5
    # Return the maximum number of ice cream bars you can buy
    costs.sort()
    count = 0
    for cost in costs:
        if coins >= cost:
            coins -= cost
            count += 1
        else:
            break
    return count
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
    coins = int(input_data[1])
    costs = [int(x) for x in input_data[2:n+2]]
    
    result = max_ice_cream_bars(costs, coins)
    print(result)