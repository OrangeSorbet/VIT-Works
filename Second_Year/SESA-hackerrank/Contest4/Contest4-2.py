# You are given the head node of a singly linked list. Each node in the list contains a value that is either 0 or 1. The linked list represents a binary number. Your task is to return the decimal value of the number represented by the linked list. The most significant bit is at the head of the linked list.

# Example 1:

# Input: head = [1, 0, 1] Output: 5 Explanation: (101) in base 2 is (5) in base 10.

# Example 2:

# Input: head = [0] Output: 0

# Input Format

# The first line contains an integer N, the number of nodes in the list. The second line contains N space-separated integers (either 0 or 1).

# Constraints

# Constraints: 1 ≤ N ≤ 60 Each node's value is either 0 or 1.

# Note: Use 64-bit integers (long long in C++, long in Java) to avoid overflow for large N.

# Edge-case Rules: • A list with a single 0 should return 0. • A list with leading zeros (e.g., 0 → 1 → 1) should be treated as the binary value 011, which equals 3.

# Output Format

# A single integer representing the decimal value of the binary number.

# Sample Input 0

# 3
# 1 0 1
# Sample Output 0

# 5
# Sample Input 1

# 1
# 0
# Sample Output 1

# 0
# Sample Input 2

# 1
# 1
# Sample Output 2

# 1
# Sample Input 3

# 3
# 1 1 1
# Sample Output 3

# 7
# Sample Input 4

# 2
# 0 1
# Sample Output 4

# 1
# Sample Input 5

# 3
# 0 1 1
# Sample Output 5

# 3
# Sample Input 6

# 5
# 0 1 0 0 1
# Sample Output 6

# 9
# Sample Input 7

# 5
# 1 1 1 1 1
# Sample Output 7

# 31
# Sample Input 8

# 4
# 1 0 1 1
# Sample Output 8

# 11
# Sample Input 9

# 5
# 1 1 0 0 1
# Sample Output 9

# 25

import sys

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

#
# Complete the 'getDecimalValue' function below.
#
# The function is expected to return an INTEGER.
#

# ================= CODE AREA START =================
def getDecimalValue(head):
    # Write your code here
    num = 0
    while head:
        num = num * 2 + head.val
        head = head.next
    return num

# ================= CODE AREA END =================

# DO NOT MODIFY THE CODE BELOW
if __name__ == '__main__':
    input_data = sys.stdin.read().split()
    if not input_data:
        sys.exit(0)
        
    it = iter(input_data)
    n = int(next(it))
    
    head = ListNode(int(next(it)))
    curr = head
    for _ in range(n - 1):
        curr.next = ListNode(int(next(it)))
        curr = curr.next
        
    print(getDecimalValue(head))