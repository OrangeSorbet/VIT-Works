# You are given the head of a singly linked list where each node contains an integer value.

# Between every pair of adjacent nodes, insert a new node with a value equal to the Greatest Common Divisor (GCD) of those two nodes.

# Return the linked list after these insertions.

# The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers.

# Example 1: Input: nodes = [18, 6, 10, 3] Output: [18, 6, 6, 2, 10, 1, 3]

# Explanation: Between 18 and 6, insert gcd(18, 6) = 6. Between 6 and 10, insert gcd(6, 10) = 2. Between 10 and 3, insert gcd(10, 3) = 1.

# Example 2: Input: nodes = [7] Output: [7]

# Explanation: There are no pairs of adjacent nodes.

# Input Format

# The first line contains an integer n, the length of the strings. The second line contains string s. The third line contains string t.

# Constraints

# Constraints: 1 ≤ n ≤ 2 × 10^5 s and t consist only of the characters '0' and '1'.

# Edge-case Rules: If t consists only of '1's or only of '0's, no rearrangement is possible; the result is fixed. The result must always be of length n (include leading zeros if the maximum possible XOR value has them).

# Output Format

# A binary string of length n representing the maximum XOR value.

# Sample Input 0

# 3
# 101
# 011
# Sample Output 0

# 110
# Sample Input 1

# 4
# 0110
# 1110
# Sample Output 1

# 1101
# Sample Input 2

# 4
# 0101
# 1010
# Sample Output 2

# 1111

import sys

# ================= CODE AREA START =================
def maxXorResult(n, s, t):
    count_1_t = t.count('1')
    count_0_t = n - count_1_t

    result = []

    for i in range(n):
        if s[i] == '0':
            # We want t[i] = '1' to get XOR = 1
            if count_1_t > 0:
                result.append('1')
                count_1_t -= 1
            else:
                result.append('0')
                count_0_t -= 1
        else:  # s[i] == '1'
            # We want t[i] = '0' to get XOR = 1
            if count_0_t > 0:
                result.append('1')
                count_0_t -= 1
            else:
                result.append('0')
                count_1_t -= 1

    return ''.join(result)
# ================= CODE AREA END =================

# DO NOT MODIFY THE CODE BELOW
if __name__ == '__main__':
    input_data = sys.stdin.read().split()
    if not input_data:
        sys.exit(0)
    n = int(input_data[0])
    s = input_data[1]
    t = input_data[2]
    print(maxXorResult(n, s, t))