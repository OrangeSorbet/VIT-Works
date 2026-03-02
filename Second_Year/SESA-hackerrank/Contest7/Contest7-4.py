# You are an investor analyzing the daily prices of a specific stock over a period of time. You are given an array of integers representing the stock price on each consecutive day. Your goal is to maximize your profit by choosing exactly one day to buy one share of the stock and choosing a different day in the future to sell that share. Return the maximum profit you can achieve from this single transaction. If it is impossible to achieve any profit (for example, if the stock price only decreases over time), return 0.

# Input Format

# The input consists of two lines: The first line contains an integer N, representing the total number of days. The second line contains N space-separated integers, where the i-th integer represents the stock price on day i.

# Constraints

# Constraints: 1 ≤ N ≤ 10^5 0 ≤ Price on any given day ≤ 10^4

# Output Format

# Print a single integer representing the maximum profit achievable. If no profit is possible, print 0.

# Sample Input 0

# 6
# 7 1 5 3 6 4
# Sample Output 0

# 5
# Sample Input 1

# 5
# 7 6 4 3 1
# Sample Output 1

# 0
# Sample Input 2

# 4
# 3 3 3 3
# Sample Output 2

# 0

# ================= CODE AREA START =================
def max_profit(prices: list[int]) -> int:
    # Write your code here
    # Return the maximum profit, or 0 if no profit is possible
    min_price = float('inf')
    max_profit = 0
    for price in prices:
        if price < min_price:
            min_price = price
        elif price - min_price > max_profit:
            max_profit = price - min_price
    return max_profit
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
    prices = [int(x) for x in input_data[1:n+1]]
    
    result = max_profit(prices)
    print(result)