# You are given five integers: cost1, cost2, costBoth, need1, and need2.

# There are three types of items available in unlimited supply:

# Type 1: • Cost: cost1
# • Contribution: 1 unit toward need1 only

# Type 2: • Cost: cost2
# • Contribution: 1 unit toward need2 only

# Type 3: • Cost: costBoth
# • Contribution: 1 unit toward both need1 and need2 simultaneously

# Your goal is to satisfy both requirements such that: • Total contribution toward type 1 ≥ need1 • Total contribution toward type 2 ≥ need2

# Return a single integer representing the minimum possible total cost to achieve these requirements.

# Input Format

# A single line containing five space-separated integers: cost1, cost2, costBoth, need1, and need2.

# Constraints

# Constraints: 1 ≤ cost1, cost2, costBoth ≤ 10^9 0 ≤ need1, need2 ≤ 10^6

# Note: Use 64-bit integers (long long in C++, long in Java) to store and compute the total cost.

# Output Format

# A single integer representing the minimum cost.

# Sample Input 0

# 3 2 1 3 2
# Sample Output 0

# 3
# Sample Input 1

# 5 4 15 2 3
# Sample Output 1

# 22
# Sample Input 2

# 5 4 15 0 0
# Sample Output 2

# 0
# Sample Input 3

# 7 3 2 5 5
# Sample Output 3

# 10
# Sample Input 4

# 5 8 9 6 6
# Sample Output 4

# 54
# Sample Input 5

# 9 8 3 4 4
# Sample Output 5

# 12
# Sample Input 6

# 6 9 9 2 2
# Sample Output 6

# 18
# Sample Input 7

# 7 1 5 10 10
# Sample Output 7

# 50
# Sample Input 8

# 8 6 7 5 5
# Sample Output 8

# 35
# Sample Input 9

# 3 6 10 4 4
# Sample Output 9

# 36

import sys

# ================= CODE AREA START =================
def minCost(cost1, cost2, costBoth, need1, need2):
    ans = 10**30
    for k in range(max(need1, need2) + 1):
        total = (
            k * costBoth +
            max(0, need1 - k) * cost1 +
            max(0, need2 - k) * cost2
        )
        if total < ans:
            ans = total
    return ans

# ================= CODE AREA END =================

# DO NOT MODIFY THE CODE BELOW
if __name__ == '__main__':
    line = sys.stdin.read().split()
    if not line:
        sys.exit(0)
    c1, c2, cb, n1, n2 = map(int, line)
    print(minCost(c1, c2, cb, n1, n2))