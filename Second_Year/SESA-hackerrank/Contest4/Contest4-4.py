# You are given a positive integer n representing an n × n cargo deck on a ship. Each cell on the deck can hold exactly one container. Every container has a weight of exactly w.

# However, there is a limit: the total weight of all containers loaded onto the deck must not exceed the ship's maximum weight capacity, maxWeight.

# Your task is to return the maximum number of containers that can be loaded onto the ship.

# Example 1:

# Input: n = 2, w = 3, maxWeight = 15 Output: 4 Explanation: The deck has 2 × 2 = 4 cells. The total weight for 4 containers is 4 × 3 = 12, which is ≤ 15. We cannot load 5 containers because there are only 4 cells.

# Example 2:

# Input: n = 3, w = 5, maxWeight = 20 Output: 4 Explanation: The deck has 3 × 3 = 9 cells. Each container weighs 5. Since 20 / 5 = 4, even though there are 9 cells, we can only carry 4 containers without exceeding the weight limit of 20.

# Input Format

# Three space-separated integers: n, w, and maxWeight.

# Constraints

# Constraints: 1 ≤ n, w ≤ 10^9 1 ≤ maxWeight ≤ 10^18

# Note: Use 64-bit integers (long long in C++, long in Java/Python) to prevent overflow when calculating n × n or total weight.

# Output Format

# A single integer representing the maximum number of containers.

# Sample Input 0

# 2 3 15
# Sample Output 0

# 4
# Sample Input 1

# 3 5 20
# Sample Output 1

# 4
# Sample Input 2

# 10 1 100
# Sample Output 2

# 100
# Sample Input 3

# 85 1 104
# Sample Output 3

# 104
# Sample Input 4

# 97 7 952
# Sample Output 4

# 136
# Sample Input 5

# 16 2 627
# Sample Output 5

# 256
# Sample Input 6

# 9 5 802
# Sample Output 6

# 81
# Sample Input 7

# 27 6 972
# Sample Output 7

# 162
# Sample Input 8

# 95 3 321
# Sample Output 8

# 107
# Sample Input 9

# 97 7 608
# Sample Output 9

# 86

import sys

# ================= CODE AREA START =================
def maxContainers(n, w, maxWeight):
    # Write your code here
    maxContainersByWeight = maxWeight // w
    maxContainersByCells = n * n
    return min(maxContainersByWeight, maxContainersByCells)
# ================= CODE AREA END =================

# DO NOT MODIFY THE CODE BELOW
if __name__ == '__main__':
    line = sys.stdin.read().split()
    if not line:
        sys.exit(0)
    n, w, maxWeight = map(int, line)
    print(maxContainers(n, w, maxWeight))