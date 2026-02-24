# You are given the head of a singly linked list where each node contains an integer value.

# Between every pair of adjacent nodes, insert a new node with a value equal to the Greatest Common Divisor (GCD) of those two nodes.

# Return the linked list after these insertions.

# The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers.

# Example 1:

# ![alt text](image-1.png)

# Input: nodes = [18, 6, 10, 3] Output: [18, 6, 6, 2, 10, 1, 3]

# Explanation: Between 18 and 6, insert gcd(18, 6) = 6. Between 6 and 10, insert gcd(6, 10) = 2. Between 10 and 3, insert gcd(10, 3) = 1.

# Example 2:

# image

# Input: nodes = [7] Output: [7]

# Explanation: There are no pairs of adjacent nodes.

# Input Format

# The first line contains an integer, the number of nodes in the list. The second line contains space-separated integers representing the node values.

# Constraints

# Edge-case rules If the list contains only one node, no nodes are inserted. Values can be large (), so ensure your GCD logic is efficient (Euclidean algorithm).

# Output Format

# Print the values of the modified linked list, separated by spaces.

# Sample Input 0

# 4
# 18 6 10 3
# Sample Output 0

# 18 6 6 2 10 1 3
# Sample Input 1

# 1
# 7
# Sample Output 1

# 7
# Sample Input 2

# 3
# 10 20 30
# Sample Output 2

# 10 10 20 10 30

import sys
import math

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

# ================= CODE AREA START =================
def insertGreatestCommonDivisors(head):
    # Write your code here
    if not head or not head.next:
        return head
    curr = head
    while curr and curr.next:
        gcd_value = math.gcd(curr.val, curr.next.val)
        new_node = ListNode(gcd_value)
        new_node.next = curr.next
        curr.next = new_node
        curr = new_node.next
    return head
# ================= CODE AREA END =================

# DO NOT MODIFY THE CODE BELOW
if __name__ == '__main__':
    data = sys.stdin.read().split()
    if not data: sys.exit(0)
    n = int(data[0])
    if n == 0: sys.exit(0)
    
    head = ListNode(int(data[1]))
    curr = head
    for i in range(2, n + 1):
        curr.next = ListNode(int(data[i]))
        curr = curr.next
        
    result = insertGreatestCommonDivisors(head)
    res_vals = []
    while result:
        res_vals.append(str(result.val))
        result = result.next
    print(" ".join(res_vals))